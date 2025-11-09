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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 300005;

int n, k, s, q;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

std::vector<int> d[maxn];
int msk[maxn];

int tot;
std::vector<std::pair<int, int>> col[maxn];

void dfs(int now, int fa) {
	for (auto [c, id] : col[now]) msk[c] = id;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		for (auto &[c, id] : col[t]) {
			if (not msk[c]) id = ++tot;
			else id = msk[c];
			d[t].push_back(id);
		}
	}

	for (auto [c, id] : col[now]) msk[c] = 0;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		dfs(t, now);
	}
}

constexpr int B = 547;

int cid[maxn], ccur;
int c[maxn / B + 5][maxn];
inline void proc(int now) {
	ccur++;
	cid[now] = ccur;

	for (auto id : d[now]) msk[id] = true;

	rep (i, 1, n) {
		c[ccur][i] = 0;
		for (auto id : d[i]) {
			c[ccur][i] += msk[id];
		}
	}

	for (auto id : d[now]) msk[id] = false;
}

inline void clr() {
	rep (i, 1, n) std::vector<int>{}.swap(d[i]);
	rep (i, 1, n) std::vector<std::pair<int, int>>{}.swap(col[i]);
	tot = 0;

	cnt = 0;
	rep (i, 1, n) last[i] = 0;
	rep (i, 1, ccur) rep (j, 1, n) c[i][j] = 0;
	ccur = 0;
	rep (i, 1, n) cid[i] = 0;
}

void solve() {
	std::cin >> n >> k >> s >> q;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}

	rep (i, 1, s) {
		int u, x; std::cin >> u >> x;
		col[u].push_back({x, 0});
	}

	// rep (i, 1, n) {
	// 	dbg(i);
	// 	for (auto x : col[i]) db << x.first << " "; dbendl;
	// }

	for (auto &[c, id] : col[1]){
		id = ++tot;
		d[1].push_back(id);
	}
	dfs(1, 0);

	rep (i, 1, n) if (d[i].size() >= B) proc(i);

	while (q--) {
		int u, v; std::cin >> u >> v;
		if (d[u].size() >= B) {
			std::cout << c[cid[u]][v] << " ";
			continue;
		}
		if (d[v].size() >= B) {
			std::cout << c[cid[v]][u] << " ";
			continue;
		}
	
		int res = 0;

		for (auto id : d[u]) msk[id] = true;
		for (auto id : d[v]) res += msk[id];
		for (auto id : d[u]) msk[id] = false;

		std::cout << res << " ";
	}

	std::cout << "\n";

	clr();
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
