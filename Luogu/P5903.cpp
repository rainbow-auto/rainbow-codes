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

constexpr int maxn = 50005;
constexpr int mod = 201314;

int n, q;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];
int last[maxn], cnt;
inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

struct Query {
	int x;
	int id;
	int c;
};
std::vector<Query> qs[maxn];

int ans[maxn];

struct SegTree {
	struct Node {
		int sum;
		int tag;
	} tr[maxn << 2];

	inline void apply(int now, int l, int r, int v) {
		(tr[now].sum += 1ll * v * (r - l + 1) % mod) %= mod;
		(tr[now].tag += v) %= mod;
	}

	inline void pushdown(int now, int l, int r) {
		if (not tr[now].tag) return;
		int mid = (l + r) >> 1;
		apply(now << 1, l, mid, tr[now].tag);
		apply(now << 1 | 1, mid + 1, r, tr[now].tag);
		tr[now].tag = 0;
	}

	inline void pushup(int now) {
		tr[now].sum = (tr[now << 1].sum + tr[now << 1 | 1].sum) % mod;
	}

	void mdf(int now, int l, int r, int L, int R, int v) {
		if (L <= l and r <= R) return apply(now, l, r, v), void(0);
		pushdown(now, l, r);
		int mid = (l + r) >> 1;
		if (L <= mid) mdf(now << 1, l, mid, L, R, v);
		if (R > mid) mdf(now << 1 | 1, mid + 1, r, L, R, v);
		pushup(now);
	}

	int qry(int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) return tr[now].sum;
		pushdown(now, l, r);
		int mid = (l + r) >> 1;
		if (R <= mid) return qry(now << 1, l, mid, L, R);
		if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R);
		return (qry(now << 1, l, mid, L, R) + qry(now << 1 | 1, mid + 1, r, L, R)) % mod;
	}
} tr;

int fa[maxn], dep[maxn], siz[maxn], son[maxn];

void dfs1(int now) {
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa[now]) continue;
		fa[t] = now;
		dep[t] = dep[now] + 1;
		dfs1(t);
		siz[now] += siz[t];
		if (siz[t] > siz[son[now]]) son[now] = t;
	}
}

int dfn[maxn], dpos, top[maxn];

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

void mdf(int u) {
	while (top[u] != 1) {
		tr.mdf(1, 1, dpos, dfn[top[u]], dfn[u], 1);
		u = fa[top[u]];
	}
	tr.mdf(1, 1, dpos, dfn[1], dfn[u], 1);
}

int qry(int u) {
	int res = 0;
	while (top[u] != 1) {
		(res += tr.qry(1, 1, dpos, dfn[top[u]], dfn[u])) %= mod;
		u = fa[top[u]];
	}
	(res += tr.qry(1, 1, dpos, dfn[1], dfn[u])) %= mod;
	db << res << "\n";
	return res;
}

void solve() {
	std::cin >> n >> q;
	rep (i, 2, n) {
		int f; std::cin >> f;
		f++;
		
		addEdge(f, i);
	}

	rep (t, 1, q) {
		int l, r; std::cin >> l >> r;
		l++, r++;
		int x; std::cin >> x;
		x++;

		qs[r].push_back(Query { x, t, 1 });
		qs[l - 1].push_back(Query { x, t, -1 });
	}

	dfs1(1);
	dfs2(1, 1);

	rep (y, 1, n) {
		mdf(y);
		for (auto qcur : qs[y]) {
			(((ans[qcur.id] += qcur.c * qry(qcur.x)) %= mod) += mod) %= mod;
		}
	}

	rep (t, 1, q) std::cout << ans[t] << "\n";
}

/*
5 2
1 2
1 3
2 4
2 5

2 5 3
2 5 2
*/

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
