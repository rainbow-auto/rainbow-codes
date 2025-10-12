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

constexpr int maxn = 15;

int n, m;
bool g[maxn][maxn];

void solve() {	
	std::cin >> n >> m;
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		g[u][v] = true;
	}

	int ans = 0x3f3f3f3f;
	rep (S, 0, (1 << n) - 1) {
		int cnt = 0;
		rep (i, 1, n) rep (j, 1, n) if (g[i][j]) {
			bool ci = S & (1 << (i - 1));
			bool cj = S & (1 << (j - 1));
			if (ci == cj) cnt ++;
		}
		ans = std::min(ans, cnt);
	}

	std::cout << ans << "\n";
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
