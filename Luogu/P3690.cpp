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

const int maxn = 300005;

struct Splay {
	int ch[2];
	int fa;
	
	int val;
	int sum;
	
	int tag;
} tr[maxn];

inline bool chk (int x) { return x == tr[tr[x].fa].ch[1]; }
inline bool notRoot (int x) { return x == tr[tr[x].fa].ch[0] or x == tr[tr[x].fa].ch[1]; }
inline void pushUp (int x) { tr[x].sum = tr[tr[x].ch[0]].sum xor tr[tr[x].ch[1]].sum xor tr[x].val; }

inline void rev (int x) { std::swap (tr[x].ch[0], tr[x].ch[1]); tr[x].tag ^= 1; }

inline void pushDown (int x) {
	if (not tr[x].tag) { return; }
	if (tr[x].ch[0]) { rev (tr[x].ch[0]); }
	if (tr[x].ch[1]) { rev (tr[x].ch[1]); }
	tr[x].tag = false;
}

inline void connect (int f, int s, int p) { tr[f].ch[p] = s; tr[s].fa = f; }

inline void rotate (int x) {
	int f = tr[x].fa, ff = tr[f].fa, p = chk (x), pp = chk (f);
	pushDown (f); pushDown (x);
	if (notRoot (f)) { connect (ff, x, pp); } else { tr[x].fa = ff; } // 只认父亲
	connect (f, tr[x].ch[p ^ 1], p); connect (x, f, p ^ 1);
	pushUp (f); pushUp (x);
}

inline void pushAll (int x) {
	if (notRoot (x)) { pushAll (tr[x].fa); }
	pushDown (x);
}

inline void splay (int x) {
	pushAll (x);
	for (; notRoot (x); rotate (x))	{ 
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
	access (x); splay (x); pushDown (x);
	while (tr[x].ch[0]) { x = tr[x].ch[0]; pushDown (x); }
	splay (x); return x;
}
inline void link (int x, int y) { 
	makeRoot (x); 
	if (x == findRoot (y)) { return; } 
	tr[x].fa = y;
}
inline void cut (int x, int y) { 
	split (x, y); 
	if (tr[y].ch[0] != x or tr[x].ch[0] != tr[x].ch[1]) { return; } 
	tr[x].fa = tr[y].ch[0] = 0; 
	pushUp (y);
}

int n, m;

int main () {
	fastread

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { std::cin >> tr[i].val; }

	for (int i = 1; i <= m; i++) {
		int op, x, y; std::cin >> op >> x >> y;
		if (op == 0) { split (x, y); std::cout << tr[y].sum << "\n"; }
		if (op == 1) { link (x, y); }
		if (op == 2) { cut (x, y); }
		if (op == 3) { splay (x); tr[x].val = y; pushUp (x); }
	}

	return 0;
}
