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

constexpr int maxn = 105;
constexpr int maxm = 505;
constexpr int maxk = 11;

int n, m, k;
struct Edge {
	int u, v;
	int w;
	int pre;
} es[maxm << 1];

int last[maxn], cnt;
inline void addEdge(int u, int v, int w) {
	es[++cnt] = Edge { u, v, w, last[u] };
	last[u] = cnt;
}

int a[maxk];

std::priority_queue<std::pair<i64, int>> q;
i64 f[1 << maxk][maxn];

std::bitset<maxn> vis;
inline void dij(int S) {
	vis.reset();
	while (not q.empty()) {
		auto [_, now] = q.top(); q.pop();
		if (vis[now]) continue;
		vis[now] = true;

		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (f[S][t] > f[S][now] + es[i].w) {
				f[S][t] = f[S][now] + es[i].w;
				q.push({-f[S][t], t});
			}
		}
	}
}

void solve() {
	std::cin >> n >> m >> k;
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		int w; std::cin >> w;
		addEdge(u, v, w);
		addEdge(v, u, w);
	}

	rep (i, 0, k - 1) std::cin >> a[i];

	std::memset(f, 0x3f, sizeof f); 
	auto inf = f[0][0];
	rep (i, 0, k - 1) f[1 << i][a[i]] = 0;

	rep (S, 1, (1 << k) - 1) {
		rep (i, 1, n) {
			for (int T = (S & (S - 1)); T; T = (S & (T - 1))) {
				f[S][i] = std::min(f[S][i], f[T][i] + f[S - T][i]);
			}
			if (f[S][i] < inf) q.push({-f[S][i], i});
		}
		dij(S);
	}

	std::cout << f[(1 << k) - 1][a[0]] << "\n";
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
