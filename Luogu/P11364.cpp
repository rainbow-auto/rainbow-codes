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

	rep (i, 1, n) tr0.mdf(1, 1, n, i, Tree::dep[i]);

	std::cin >> q;

	std::vector<Query> qs;
	std::vector<int> ans(q);

	rep (i, 0, q - 1) {
		int l, r, k; std::cin >> l >> r >> k;

		if (k == 1) {
			ans[i] = tr0.qry(1, 1, n, l, r);
		} else {
			r--; k--;
			qs.push_back(Query {l, r, k, i});
		}
	}

	std::vector<int> b(n + 1);
	///////// tree -> chain /////////
	rep (i, 1, n - 1) {
		int x = Tree::LCA(i, i + 1);
		b[i] = Tree::dep[x];
		a[Tree::dep[x]].push_back(i);
	}

	n--;

	std::vector< std::pair<std::pair<int, int>, int> > rgs;

	dsu.init();
	per (dep, n + 1, 1) {
		auto ids = a[dep];
		if (ids.empty()) continue;

		for (auto id : ids) dsu.in.set(id);

		for (auto id : ids) {
			if (dsu.in[id - 1]) dsu.mrg(id, id - 1);
			if (dsu.in[id + 1]) dsu.mrg(id, id + 1);
		}
		
		for (auto id : ids) {
			id = dsu.find(id);
			// db << "[" << dsu.L[id] << ", " << dsu.R[id] << "] : " << dep << "\n";
			rgs.push_back(std::make_pair(std::make_pair(dsu.L[id], dsu.R[id]), dep));
		}
	}

	// l <= ql and r >= ql + k - 1
	std::sort(qs.begin(), qs.end(), [](auto x, auto y) -> bool {
		return x.l < y.l;
	});
	std::sort(rgs.begin(), rgs.end(), [](auto x, auto y) -> bool {
		return x.first.first < y.first.first;
	});

	tr1.build(1, 1, n);

	int rpos = 0;
	for (auto [l, r, k, id] : qs) {
		while (rpos < (int) rgs.size() and rgs[rpos].first.first <= l) tr1.mdf(1, 1, n, rgs[rpos].first.second, rgs[rpos].second), rpos++;
		if (l + k - 1 <= n) {
			ans[id] = std::max(ans[id], tr1.qry(1, 1, n, l + k - 1, n));
		}
	}

	// dbg(ans[0]);

	// l >= ql and l <= qr - k + 1 and r - l + 1 >= qk
	std::sort(qs.begin(), qs.end(), [](auto x, auto y) -> bool {
		return x.k > y.k;
	});
	std::sort(rgs.begin(), rgs.end(), [](auto x, auto y) -> bool {
		return x.first.second - x.first.first + 1 > y.first.second - y.first.first + 1;
	});

	tr1.build(1, 1, n);
	
	rpos = 0;
	for (auto [l, r, k, id] : qs) {
		while (rpos < (int) rgs.size() and rgs[rpos].first.second - rgs[rpos].first.first + 1 >= k) tr1.mdf(1, 1, n, rgs[rpos].first.first, rgs[rpos].second), rpos++;
		if (l <= r - k + 1) ans[id] = std::max(ans[id], tr1.qry(1, 1, n, l, r - k + 1));
	}

	///////// output /////////
	for (auto x : ans) std::cout << x << "\n";
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
