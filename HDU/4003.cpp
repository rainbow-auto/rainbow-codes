#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

// #pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n";
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;


const int maxn = 10005;
const int maxk = 20;

int n, s, k;
i64 dp[maxn][maxk];

struct Edge {
	int v;
	int w;
};
std::vector <Edge> g[maxn];

inline void addEdge (int u, int v, int w) {
	g[u].push_back (Edge { v, w });
}

inline void clear () {
	memset (dp, 0, sizeof (dp));
	rep (i, 1, n) { g[i].clear (); }
}

void dfs (int now, int fa) {
	for (auto e : g[now]) {
		int t = e.v;
		if (t == fa) { continue; }

		dfs (t, now);

		per (a, k, 1) {
			dp[now][a] += dp[t][0] + 2 * e.w;
			rep (b, 1, a) {
				dp[now][a] = std::min (dp[now][a], dp[now][a - b] + dp[t][b] + b * e.w);
			}
		}
		dp[now][0] += dp[t][0] + 2 * e.w;
	}
}

bool MemED;
int main () {
	fastread
	// lookMem

	while (std::cin >> n >> s >> k) {
		clear ();
		rep (i, 1, n - 1) {
			int u, v; std::cin >> u >> v;
			int w; std::cin >> w;
			addEdge (u, v, w); addEdge (v, u, w);
		}
		
		dfs (s, 0);
		std::cout << dp[s][k] << "\n";
	}

	return 0;
}
