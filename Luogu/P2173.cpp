#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 10005;

int n, m, C, k;

int val[maxn];

struct LCT {
	int deg[maxn];

	struct Node {
		int mx;
		int ch[2], fa;
		bool tag;

		Node () { mx = -0x3f3f3f3f; ch[0] = ch[1] = fa = 0; tag = false; }
	} tr[maxn];

	inline bool chk (int x) { return x == tr[tr[x].fa].ch[1]; }
	inline bool notRoot (int x) { return x == tr[tr[x].fa].ch[0] or x == tr[tr[x].fa].ch[1]; }

	inline void pushUp (int now) { tr[now].mx = std::max (std::max (tr[tr[now].ch[0]].mx, tr[tr[now].ch[1]].mx), val[now]); }

	inline void rev (int now) { std::swap (tr[now].ch[0], tr[now].ch[1]); tr[now].tag ^= 1; }
	inline void pushDown (int now) {
		if (not tr[now].tag) { return; }
		if (tr[now].ch[0]) { rev (tr[now].ch[0]); }
		if (tr[now].ch[1]) { rev (tr[now].ch[1]); }
		tr[now].tag = false;
	}

	inline void pushAll (int now) {
		if (notRoot (now)) { pushAll (tr[now].fa); }
		pushDown (now);
	}

	inline void connect (int f, int s, int p) { tr[f].ch[p] = s; tr[s].fa = f; }
	
	inline void rotate (int x) {
		int f = tr[x].fa, ff = tr[f].fa, p = chk (x), pp = chk (f);
		pushDown (f); pushDown (x);
		if (notRoot (f)) { connect (ff, x, pp); }
		else { tr[x].fa = ff; }
		connect (f, tr[x].ch[p ^ 1], p); connect (x, f, p ^ 1);
		pushUp (f); pushUp (x);
	}

	inline void splay (int x) {
		pushAll (x);
		for (; notRoot (x); rotate (x)) {
			if (notRoot (tr[x].fa)) { rotate (chk (tr[x].fa) == chk (x) ? tr[x].fa : x); }
		}
		pushUp (x);
	}

	inline void access (int x) {
		int pre = 0;
		while (x) {
			splay (x); tr[x].ch[1] = pre; pushUp (x);
			x = tr[pre = x].fa;
		}
	}

	inline void makeRoot (int x) { access (x); splay (x); rev (x); }
	inline void split (int x, int y) { makeRoot (x); access (y); splay (y); }

	inline int findRoot (int x) {
		access (x); splay (x);
		pushDown (x); while (tr[x].ch[0]) { x = tr[x].ch[0]; pushDown (x); }
		splay (x); return x;
	}

	inline void link (int x, int y) { makeRoot (x); tr[x].fa = y; deg[x] ++; deg[y] ++; }
	
	inline bool cut (int x, int y) { 
		split (x, y);
		if (tr[y].ch[0] != x or tr[x].ch[0] != tr[x].ch[1]) { return false; }
		tr[y].ch[0] = tr[x].fa = 0;
		deg[x] --; deg[y] --;
		return true;
	}
} col[10];

inline void Op0 () {
	int x, y; std::cin >> x >> y;
	for (int cid = 0; cid < C; cid ++) { 
		col[cid].access (x);
		col[cid].splay (x); 
	}
	val[x] = y;
	for (int cid = 0; cid < C; cid ++) { 
		col[cid].pushUp (x); 
	}
}

inline void Op1 () {
	int x, y; std::cin >> x >> y;
	int new_c; std::cin >> new_c;

	for (int old_c = 0; old_c < C; old_c ++) {
		if (col[old_c].cut (x, y)) {
			if (old_c == new_c) { 
				std::cout << "Success.\n"; 
				col[old_c].link (x, y);
				return;
			}

			if (col[new_c].deg[x] + 1 > 2 or col[new_c].deg[y] + 1 > 2) {
				std::cout << "Error 1.\n"; 
				col[old_c].link (x, y);
				return;
			}
			
			if (col[new_c].findRoot (x) == col[new_c].findRoot (y)) { 
				std::cout << "Error 2.\n"; 
				col[old_c].link (x, y);
				return;
			}

			col[new_c].link (x, y);
			std::cout << "Success.\n";

			return;
		}
	}

	std::cout << "No such edge.\n";
}

inline void Op2 () {
	int c, x, y; std::cin >> c >> x >> y;

	if (col[c].findRoot (x) != col[c].findRoot (y)) { std::cout << -1 << "\n"; return; }
	
	col[c].split (x, y);
	std::cout << col[c].tr[y].mx << "\n";
}

int main () {
	fastread

	std::cin >> n >> m >> C >> k;

	for (int i = 1; i <= n; i++) { 
		std::cin >> val[i];
	}

	for (int i = 1; i <= m; i++) {
		int u, v, c; std::cin >> u >> v >> c;
		col[c].link (u, v);
	}

	for (int i = 1; i <= k; i++) {
		int op; std::cin >> op;
		if (op == 0) {
			Op0 ();
		} else if (op == 1) {
			Op1 ();
		} else if (op == 2) {
			Op2 ();
		}
	}

	return 0;
}
