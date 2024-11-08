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

const int maxn = 50005;
const int maxm = 100005;

const int inf = 2e9;

int n, m;

struct Edge {
	int u, v, a, b;
	int id;

	friend bool operator < (Edge a, Edge b) {
		return a.a < b.a;
	}
} es[maxm];

struct Node {
	std::pair <int, int> val, mx;
	int ch[2], fa;
	bool rev;

	Node () { val.first = -inf; mx.first = -inf; }
} tr[maxn + maxm];

inline bool chk (int x) { return x == tr[tr[x].fa].ch[1]; }
inline bool notRoot (int x) { return x == tr[tr[x].fa].ch[0] or x == tr[tr[x].fa].ch[1]; }
inline void pushUp (int x) { tr[x].mx = std::max (std::max (tr[tr[x].ch[0]].mx, tr[tr[x].ch[1]].mx), tr[x].val); }

inline void rev (int x) { std::swap (tr[x].ch[0], tr[x].ch[1]); tr[x].rev ^= 1; }

inline void pushDown (int x) {
	if (not tr[x].rev) { return; }
	if (tr[x].ch[0]) { rev (tr[x].ch[0]); }
	if (tr[x].ch[1]) { rev (tr[x].ch[1]); }
	tr[x].rev = false;
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

inline void MSTAddEdge (Edge x) {
	if (findRoot (x.u) != findRoot (x.v)) { link (x.u, x.id); link (x.v, x.id); return; }

	split (x.u, x.v);

	if (x.b > tr[x.v].mx.first) { return; }

	int mxid = tr[x.v].mx.second;
	cut (es[mxid - n].u, mxid);
	cut (es[mxid - n].v, mxid);

	link (x.u, x.id); 
	link (x.v, x.id);
}

int main () {
	fastread
	
	std::cin >> n >> m;

	for (int i = 1; i <= m; i++) { std::cin >> es[i].u >> es[i].v >> es[i].a >> es[i].b; }

	std::sort (es + 1, es + m + 1);

	for (int i = 1; i <= m; i++) {
		es[i].id = n + i;
		tr[es[i].id].val.first = es[i].b;
		tr[es[i].id].val.second = es[i].id;
	}

	int ans = inf;
	for (int i = 1; i <= m; i++) {
		MSTAddEdge (es[i]);
		if (findRoot (1) == findRoot (n)) { split (1, n); ans = std::min (ans, tr[n].mx.first + es[i].a); }
	}

	if (ans == inf) { std::cout << "-1\n"; }
	else { std::cout << ans << "\n"; }

	return 0;
}