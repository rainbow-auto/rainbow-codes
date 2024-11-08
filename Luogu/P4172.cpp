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

const int maxn = 1005;
const int maxm = 100005;

int n, m, q;

struct Edge {
	int u, v, w;
	int id;
};
std::vector <Edge> es;

std::map < std::pair<int, int> , int > id;

std::set <int> del;

struct Query {
	int k, u, v;
	int ans;
};
std::vector <Query> qs;

struct Node {
	int val, mx;
	int ch[2], fa;
	bool rev;
} tr[maxn + maxm];

inline bool chk (int x) { return x == tr[tr[x].fa].ch[1]; }
inline bool notRoot (int x) { return x == tr[tr[x].fa].ch[0] or x == tr[tr[x].fa].ch[1]; }

inline void pushUp (int x) { tr[x].mx = std::max (tr[x].val, std::max (tr[tr[x].ch[0]].mx, tr[tr[x].ch[1]].mx)); }

inline void rev (int x) { std::swap (tr[x].ch[0], tr[x].ch[1]); tr[x].rev ^= 1; }
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

inline void connect (int fa, int son, int pos) { tr[fa].ch[pos] = son; tr[son].fa = fa; }

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

inline void cut (int x, int y) { split (x, y); tr[y].ch[0] = tr[x].fa = 0; pushUp (y); }
inline void link (int x, int y) { makeRoot (x); tr[x].fa = y; }

int findEdge (int now, int val) {
	if (tr[now].val == val) { return now; }
	else if (tr[tr[now].ch[0]].mx == val) { return findEdge (tr[now].ch[0], val); }
	else { return findEdge (tr[now].ch[1], val); }
}

inline void MSTaddEdge (Edge e) {
	if (findRoot (e.u) != findRoot (e.v)) { 
		link (e.u, e.id + (n + 1));
		link (e.v, e.id + (n + 1));
		return; 
	}

	split (e.u, e.v);
	
	if (e.w > tr[e.v].mx) { return; }
	else {
		int x = findEdge (e.v, tr[e.v].mx);
		cut (es[x - (n + 1)].u, x);
		cut (es[x - (n + 1)].v, x);
		link (e.u, e.id + (n + 1));
		link (e.v, e.id + (n + 1));
	}
}

int main () {
	fastread

	std::cin >> n >> m >> q;

	for (int i = 1; i <= m; i++) {
		int u, v, t; std::cin >> u >> v >> t;
		id[{ u, v }] = es.size ();
		id[{ v, u }] = es.size ();
		es.push_back (Edge { u, v, t, id[{ u, v }]});
		tr[id[{ u, v }] + (n + 1)].val = t; pushUp (id[{ u, v }] + (n + 1));
	}

	for (int i = 1; i <= q; i++) {
		int k, u, v; std::cin >> k >> u >> v;
		qs.push_back (Query { k, u, v, 0 });
		if (k == 2) { del.insert ( id[{ u, v }] ); }
	}

	for (auto e : es) {
		if (del.count (e.id)) { continue; }
		MSTaddEdge (e);
	}

	std::reverse (qs.begin (), qs.end ());

	for (auto& now : qs) {
		if (now.k == 1) { 
			split (now.u, now.v); 
			now.ans = tr[now.v].mx; 
		}
		if (now.k == 2) { 
			MSTaddEdge (es[id[{ now.u, now.v }]]); 
		}
	}

	std::reverse (qs.begin (), qs.end ());

	for (auto now : qs) { if (now.k == 1) { std::cout << now.ans << "\n"; } }

	return 0;
}
