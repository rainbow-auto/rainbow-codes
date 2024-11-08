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

const int maxn = 100005;

int n, m;

struct Node {
	int ch[2], fa;
	bool rev;
} tr[maxn];

inline bool chk (int x) { return x == tr[tr[x].fa].ch[1]; }
inline bool notRoot (int x) { return x == tr[tr[x].fa].ch[0] or x == tr[tr[x].fa].ch[1]; }

inline void rev (int x) { std::swap (tr[x].ch[0], tr[x].ch[1]); tr[x].rev ^= 1; }

inline void pushUp (int x) { }

inline void pushDown (int x) {
	if (not tr[x].rev) { return; }
	if (tr[x].ch[0]) { rev (tr[x].ch[0]); }
	if (tr[x].ch[1]) { rev (tr[x].ch[1]); }
	tr[x].rev = false;
}

void pushAll (int x) {
	if (notRoot (x)) { pushAll (tr[x].fa); }
	pushDown (x);
}

inline void connect (int f, int s, int id) { tr[f].ch[id] = s; tr[s].fa = f; }

inline void rotate (int x) {
	int f = tr[x].fa, ff = tr[f].fa, p = chk (x), pp = chk (f);
	pushDown (f); pushDown (x);
	if (notRoot (f)) { connect (ff, x, pp); } else { tr[x].fa = ff; }
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

inline void link (int x, int y) { makeRoot (x); tr[x].fa = y; }
inline void cut (int x, int y) { split (x, y); tr[y].ch[0] = tr[x].fa = 0; }

int main () {
	fastread

	std::cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		std::string op; std::cin >> op;
		int u, v; std::cin >> u >> v;
		if (op[0] == 'Q') { std::cout << (findRoot (u) == findRoot (v) ? "Yes\n" : "No\n"); }
		if (op[0] == 'C') { link (u, v); }
		if (op[0] == 'D') { cut (u, v); }
	}

	return 0;
}
