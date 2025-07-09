#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

// #define dbg(x) std::cerr << (#x) << " : " << x << "\n";
// #define dbendl std::cerr << "\n"; 
// #define db std::cerr

#define dbg(x) if (0) std::cerr << (#x) << " : " << x << "\n";
#define dbendl if (0)std::cerr << "\n"; 
#define db if(0) std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

constexpr int maxn = 5005;

int n;
int mod;

int f[maxn][maxn];

std::vector<int> ds[maxn];
inline void init () {
	rep (i, 1, n) {
		for (int d = 1; d * d <= i; d++) {
			if (i % d) continue;
			ds[i].push_back(d);
			if (i / d != d) ds[i].push_back(i / d);
		}
		std::sort(ds[i].begin(), ds[i].end());
		ds[i].pop_back();
	}
}

namespace Sol1 {
	inline void solve() {
		i64 ans = 0;
		rep (i, 2, n + 1) (ans += f[1][i]) >= mod ? ans -= mod : 0;
		std::cout << ans << '\n';
		per (i, n, 2) {
			int pre = 0;
			rep (j, i + 1, n + 1) {
				(f[i - 1][i] += f[i][j]) >= mod ? f[i - 1][i] -= mod : 0;
				
				for (auto d : ds[i]) {
					(f[d][i] += f[i][j]) >= mod ? f[d][i] -= mod : 0;
				}			
				
				rep (k, i + 1, j - 1) {
					for (auto x : ds[k]) {
						if (x >= i) break;
						(f[x][i] += f[i][j]) >= mod ? f[x][i] -= mod : 0;
					}
				}
			}
		}
	}
}

int suf[maxn];

void solve() {
	std::cin >> n >> mod;
	
	init();
	
	f[n][n + 1] = 1;
	per (i, n, 2) {
		per (j, n + 1, i) (suf[j] = suf[j + 1] + f[i][j]) >= mod ? suf[j] -= mod : 0;

		rep (j, i + 1, n + 1) {
			(f[i - 1][i] += f[i][j]) >= mod ? f[i - 1][i] -= mod : 0;
			
			for (auto d : ds[i]) {
				(f[d][i] += f[i][j]) >= mod ? f[d][i] -= mod : 0;
			}			
			
			// rep (k, i + 1, j - 1) {
			// 	for (auto x : ds[k]) {
			// 		if (x >= i) break;
			// 		(f[x][i] += f[i][j]) >= mod ? f[x][i] -= mod : 0;
			// 	}
			// }
		}

		rep (t, 1, i - 1) {
			for (int x = t; x <= n + 1; x += t) {
				if (x <= i) continue;
				(f[t][i] += suf[x + 1]) >= mod ? f[t][i] -= mod : 0;
			}
		}
	}

	i64 ans = 0;
	rep (i, 2, n + 1) (ans += f[1][i]) >= mod ? ans -= mod : 0;
	std::cout << ans << '\n';
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
