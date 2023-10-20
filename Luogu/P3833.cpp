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

int n;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

template <int maxn, typename val_t>
struct SegmentTree {
	struct Node {
		val_t sum;
		val_t tag; bool cov;
	} tr[maxn << 3];

	inline void pushUp (int now) {
		tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
	}

	inline void update (int now, int l, int r, val_t val) {
		tr[now].sum += val * (r - l + 1);
		tr[now].tag += val;
		tr[now].cov = true;
	}

	inline void pushDown (int now, int l, int r) {
		if (not tr[now].cov) { return; }

		int mid = (l + r) >> 1;
		update (now << 1, l, mid, tr[now].tag);
		update (now << 1 | 1, mid + 1, r, tr[now].tag);
		tr[now].tag = 0; tr[now].cov = false;
	}

	void build (int now, int l, int r) {
		if (l == r) { tr[now] = Node { 0, 0, false }; return; }
		int mid = (l + r) >> 1;
		build (now << 1, l, mid);
		build (now << 1 | 1, mid + 1, r);
	}

	void modify (int now, int l, int r, int L, int R, val_t val) {
		if (L <= l and r <= R) { update (now, l, r, val); return; }
		pushDown (now, l, r);
		int mid = (l + r) >> 1;
		if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
		if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }
		pushUp (now);		
	}

	val_t query (int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) { return tr[now].sum; }
		pushDown (now, l, r);
		val_t res = 0;
		int mid = (l + r) >> 1;
		if (L <= mid) { res += query (now << 1, l, mid, L, R); }
		if (R > mid) { res += query (now << 1 | 1, mid + 1, r, L, R); }
		return res;
	}
};

SegmentTree<maxn, i64> tr;

int fa[maxn], siz[maxn], son[maxn], dep[maxn];
void build_tree (int now) {
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa[now]) { continue; }
		fa[t] = now;
		dep[t] = dep[now] + 1;
		build_tree (t);
		siz[now] += siz[t];
		if (siz[t] > siz[son[now]]) { son[now] = t; }
	}
}

int top[maxn], dfn[maxn], dpos, rnk[maxn], bottom[maxn];
void tree_decomp (int now, int topnow) {
	dfn[now] = ++dpos;
	rnk[dfn[now]] = now;
	top[now] = topnow;
	bottom[now] = dfn[now];

	if (not son[now]) { return; }
	tree_decomp (son[now], topnow);
	bottom[now] = std::max (bottom[now], bottom[son[now]]);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa[now]) { continue; }
		if (t == son[now]) { continue; }

		tree_decomp (t, t);
		bottom[now] = std::max (bottom[now], bottom[t]);
	}
}

inline void chainModify (int x, int y, i64 val) {
	while (top[x] != top[y]) {
		if (dep[top[x]] > dep[top[y]]) {
			tr.modify (1, 1, n, dfn[top[x]], dfn[x], val);
			x = fa[top[x]];
		} else {
			tr.modify (1, 1, n, dfn[top[y]], dfn[y], val);
			y = fa[top[y]];
		}
	}
	if (dfn[x] > dfn[y]) { std::swap (x, y); }
	tr.modify (1, 1, n, dfn[x], dfn[y], val);
}

inline i64 subtreeQuery (int x) {
	return tr.query (1, 1, n, dfn[x], bottom[x]);
}

int main () {
	fastread

	std::cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; std::cin >> u >> v;
		addEdge (u + 1, v + 1); addEdge (v + 1, u + 1); 
	}

	build_tree (1);
	tree_decomp (1, 1);
	tr.build (1, 1, n);

	int m; std::cin >> m;
	while (m--) {
		char op; std::cin >> op;
		if (op == 'A') { int u, v; std::cin >> u >> v; i64 d; std::cin >> d; chainModify (u + 1, v + 1, d); }
		if (op == 'Q') { int u; std::cin >> u; std::cout << subtreeQuery (u + 1) << "\n"; }
	}

	return 0;
}
