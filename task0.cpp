#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

const int maxn = 500005;

struct SegTree {
	struct Node {
		int mx;
	} tr[maxn << 2];

	inline void pushUp(int now) {
		tr[now].mx = std::max(tr[now << 1].mx, tr[now << 1 | 1].mx);
	}

	void build(int now, int l, int r) {
		tr[now].mx = 0;
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(now << 1, l, mid);
		build(now << 1 | 1, mid + 1, r);
	}

	void mdf(int now, int l, int r, int pos, int val) {
		if (l == r) return void(tr[now].mx = val);
		int mid = (l + r) >> 1;
		if (pos <= mid) mdf(now << 1, l, mid, pos, val);
		if (pos > mid) mdf(now << 1 | 1, mid + 1, r, pos, val);
		pushUp(now);
	}

	int qry(int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) return tr[now].mx;
		int mid = (l + r) >> 1;
		if (R <= mid) return qry(now << 1, l, mid, L, R);
		if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R);
		return std::max(qry(now << 1, l, mid, L, R), qry(now << 1 | 1, mid + 1, r, L, R));
	}
} tr0, tr1;

namespace Tree {
	struct Edge {
		int u, v;
		int pre;
	} es[maxn << 1];
	int last[maxn], cnt;

	inline void addEdge(int u, int v) {
		es[++cnt] = Edge {u, v, last[u]};
		last[u] = cnt;
	}

	int fa[maxn], siz[maxn], son[maxn], dep[maxn];
	void dfs1(int now) {
		siz[now] = 1;
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (t == fa[now]) continue;
			fa[t] = now;
			dep[t] = dep[now] + 1;
			dfs1(t);
			siz[now] += siz[t];
			if (siz[son[now]] <= siz[t]) son[now] = t;
		}
	}

	int dfn[maxn], top[maxn], dpos;
	void dfs2(int now, int topnow) {
		dfn[now] = ++dpos;
		top[now] = topnow;
		if (not son[now]) return;
		dfs2(son[now], topnow);
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (t == fa[now]) continue;
			if (t == son[now]) continue;
			dfs2(t, t);
		}
	}

	inline int LCA(int u, int v) {
		while (top[u] != top[v]) {
			if (dep[top[u]] > dep[top[v]]) {
				u = fa[top[u]];
			} else {
				v = fa[top[v]];
			}
		}
		if (dep[u] < dep[v]) {
			return u;
		} else {
			return v;
		}
	}

	inline void init() {
		dep[1] = 1;
		dfs1(1);
		dfs2(1, 1);
	}
}

int n, q;

std::vector<int> a[maxn];

struct DSU {
	int fa[maxn];
	int L[maxn], R[maxn];
	std::bitset<maxn> in;
	inline void init() {
		rep (i, 1, n) fa[i] = L[i] = R[i] = i;
		in.reset();
	}

	int find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}

	inline void mrg(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		fa[u] = v;
		L[v] = std::min(L[v], L[u]);
		R[v] = std::max(R[v], R[u]);
	}
} dsu;

/*
LCA* 477 479 : 213 | 35
LCA* 478 480 : 256 | 13
LCA* 479 481 : 256 | 13
LCA* 480 482 : 256 | 13
LCA* 481 483 : 266 | 37
LCA* 482 484 : 102 | 8
LCA* 483 485 : 485 | 2
LCA* 484 486 : 485 | 2
LCA* 485 487 : 485 | 2
LCA* 486 488 : 409 | 3
LCA* 487 489 : 409 | 3
LCA* 488 490 : 263 | 47
LCA* 489 491 : 491 | 31
*/

struct Query {
	int l, r;
	int k;
	int id;
};

void solve() {
	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		Tree::addEdge(u, v);
		Tree::addEdge(v, u);
	}	

	Tree::init();

	int q; std::cin >> q;
	while (q--) {
		int l, r; std::cin >> l >> r;
		int k; std::cin >> k;	

		int res = 0;
		rep (i, l, r - k + 1) {
			int x = i;
			rep (j, i + 1, i + k - 1) {
				x = Tree::LCA(x, j);
			}
			db << "LCA* " << i << " " << i + k - 1 << " : " << x << " | " << Tree::dep[x] << "\n";
			res = std::max(res, Tree::dep[x]);
		}
		std::cout << res << "\n";
	}
}

bool MemED;
int main() {
	fastread
	// lookMem	

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
