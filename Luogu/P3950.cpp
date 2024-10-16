#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 300005;

int n, m;

struct Tree {
	int tr[maxn];
	int mx;
	inline int lowbit(int x) { return x & (-x); }

	inline void mdf(int pos, int val) {
		for (int i = pos; i <= mx; i += lowbit(i)) tr[i] += val;
	} 

	inline int qry(int pos) {
		int res = 0;
		for (int i = pos; i; i -= lowbit(i)) res += tr[i];
		return res;
	}

	inline int qry(int l, int r) {
		return qry(r) - qry(l - 1);
	}
} tr;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;
inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

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

int dfn[maxn], dpos;
int top[maxn];

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

inline void tree_decomp() {
	dfs1(1);
	dfs2(1, 1);
	tr.mx = dpos;
}

inline bool chk(int u, int v) {
	int res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			res += tr.qry(dfn[top[u]], dfn[u]);
			u = fa[top[u]];
		} else {
			res += tr.qry(dfn[top[v]], dfn[v]);
			v = fa[top[v]];
		}
	}
	if (dep[u] < dep[v]) {
		res += tr.qry(dfn[u] + 1, dfn[v]); // 去掉 lca 的点权
	} else {
		res += tr.qry(dfn[v] + 1, dfn[u]);
	}

	return res == 0;
}

inline void mdf(int u, int v, int val) {
	if (dep[u] > dep[v]) {
		tr.mdf(dfn[u], val);
	} else {
		tr.mdf(dfn[v], val);
	}
}

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v); addEdge(v, u);
	}

	tree_decomp();

	std::bitset<maxn> exist;
	std::vector<std::pair<int, int>> war;
	war.push_back(std::make_pair(0, 0));

	while (m--) {
		char op; std::cin >> op;
		if (op == 'Q') {
			int u, v; std::cin >> u >> v;
			if (chk(u, v)) std::cout << "Yes\n";
			else std::cout << "No\n";
		} else if (op == 'U') {
			int x; std::cin >> x;
			if (not exist[x]) continue;
			exist.reset(x);
			mdf(war[x].first, war[x].second, -1);
		} else {
			int u, v; std::cin >> u >> v;
			exist.set(war.size());
			war.push_back(std::make_pair(u, v));

			mdf(u, v, 1);
		}
	}
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

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
