#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
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

constexpr int maxn = 250005;
constexpr int inf = 0x3f3f3f3f;

int n, m;
std::vector<int> a[maxn];

std::vector<std::vector<int>> f[maxn];
std::vector<int> ans[maxn];

inline void clr() {
	rep (i, 1, n) std::exchange(ans[i], {});
	rep (i, 1, std::max(n, m)) std::exchange(f[i], {});
	rep (i, 1, n) std::exchange(a[i], {});
}

// O(n ^ 2 m)
void solve1() {
	rep (j, 1, m) f[j].assign(n + 1, std::vector<int>(n + 1, inf));

	rep (i, 1, n) rep (j, i + 1, n) {
		int lst = -1;
		rep (k, 1, m) {
			if (a[i][k] and a[j][k]) {
				if (~lst) {
					rep (p, lst, k) {
						f[p][i][j] = std::min(f[p][i][j], (k - lst + 1) * (j - i + 1));
						// f[p][i].push_back({j, (k - lst + 1) * (j - i + 1)});
						// f[p].push_back({{i, j}, (k - lst + 1) * (j - i + 1)});
					}
				}
				lst = k;
			}
		}
	}

	rep (i, 1, n) ans[i].assign(m + 1, inf);

	rep (j, 1, m) {
		// std::vector<std::vector< std::pair<int, int> >> add(n + 1);
		
		// for (auto [rg, v] : f[j]) {
		// 	add[rg.first].push_back({rg.second, v});
		// }

		std::vector<int> cur(n + 1, inf);
		rep (i, 1, n) {
			rep (ed, 1, n) cur[ed] = std::min(cur[ed], f[j][i][ed]);
			// for (auto [ed, v] : f[j][i]) cur[ed] = std::min(cur[ed], v);

			rep (ed, i, n) {
				ans[i][j] = std::min(ans[i][j], cur[ed]);
			} 

			if (ans[i][j] == inf) ans[i][j] = 0;
		}
	}

	rep (i, 1, n) rep (j, 1, m) std::cout << ans[i][j] << " \n"[j == m];
}

// O(m ^ 2 n)
void solve2() {
	rep (j, 1, n) f[j].assign(m + 1, std::vector<int>(m + 1, inf));

	rep (i, 1, m) rep (j, i + 1, m) {
		int lst = -1;
		rep (k, 1, n) {
			if (a[k][i] and a[k][j]) {
				if (~lst) {
					rep (p, lst, k) {
						f[p][i][j] = std::min(f[p][i][j], (k - lst + 1) * (j - i + 1));
						// f[p][i].push_back({j, (k - lst + 1) * (j - i + 1)});
						// f[p].push_back({{i, j}, (k - lst + 1) * (j - i + 1)});
					}
				}
				lst = k;
			}
		}
	}

	rep (i, 1, n) ans[i].assign(m + 1, inf);

	rep (j, 1, n) {
		// std::vector<std::vector< std::pair<int, int> >> add(n + 1);
		
		// for (auto [rg, v] : f[j]) {
		// 	add[rg.first].push_back({rg.second, v});
		// }

		std::vector<int> cur(m + 1, inf);
		rep (i, 1, m) {
			rep (ed, 1, m) cur[ed] = std::min(cur[ed], f[j][i][ed]);
			// for (auto [ed, v] : f[j][i]) cur[ed] = std::min(cur[ed], v);

			rep (ed, i, m) {
				ans[j][i] = std::min(ans[j][i], cur[ed]);
			} 

			if (ans[j][i] == inf) ans[j][i] = 0;
		}
	}

	rep (i, 1, n) rep (j, 1, m) std::cout << ans[i][j] << " \n"[j == m];
}

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) {
		a[i].resize(m + 1);
		rep (j, 1, m) {
			char c; std::cin >> c;
			a[i][j] = c - '0';
		}
	}

	// solve1();
	// solve2();

	if (n < m) solve1();
	else solve2();

	clr();

	lookTime
}

bool MemED;
int main() {
	fastread
	// lookMem	

	// file("E")

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
