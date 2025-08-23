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

constexpr int maxn = 505;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

int n, m, q, K, T;
i64 g[maxn][maxn], ans;

inline void init() {
	rep (k, 1, n + 1) {
		rep (i, 1, n + 1) {
			rep (j, 1, n + 1) {
				g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	ans = 0;
	rep (i, 1, n) rep (j, 1, n) if (g[i][j] != inf) ans += g[i][j];
}

inline void addEdge(int u, int v, i64 w, bool bio = true) {
	g[u][v] = std::min(g[u][v], w);
	if (bio) g[v][u] = std::min(g[v][u], w);
	rep (i, 1, n + 1) rep (j, 1, n + 1) {
		g[i][j] = std::min(g[i][j], g[i][u] + g[v][j] + w);
		if (bio) g[i][j] = std::min(g[i][j], g[i][v] + g[u][j] + w);
	}
	ans = 0;
	rep (i, 1, n) rep (j, 1, n) if (g[i][j] != inf) ans += g[i][j];
}

void solve() {
	std::cin >> n >> m;

	std::memset(g, 0x3f, sizeof g);
	rep (i, 1, n + 1) g[i][i] = 0;
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		i64 w; std::cin >> w;
		g[u][v] = std::min(g[u][v], w);
		g[v][u] = std::min(g[v][u], w);
	}

	std::cin >> K >> T;

	int sky = n + 1;
	rep (i, 1, K) {
		int d; std::cin >> d;
		g[d][sky] = 0;
		g[sky][d] = T;
	}

	init();

	std::cin >> q;
	while (q--) {
		int op; std::cin >> op;
		if (op == 1) {
			int x, y; std::cin >> x >> y;
			i64 t; std::cin >> t;
			addEdge(x, y, t);
		} else if (op == 2) {
			int t; std::cin >> t;
			addEdge(t, sky, 0, false);
			addEdge(sky, t, T, false);
		} else {
			std::cout << ans << "\n"; 
		}
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
