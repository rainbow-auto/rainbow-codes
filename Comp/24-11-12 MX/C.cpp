#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 1005;

int n;
int a[maxn];

namespace Task1 {
	const int maxc = 43;
	i64 f[maxn][maxc][maxc];

	i64 calc(i64 x, int a, int b) {
		rep (i, 1, a) x /= 2ll;
		rep (i, 1, b) x *= 2ll;
		return x;
	}

	i64 val[maxn][maxc][maxc];

	inline void solve() {
		std::memset(f, 0x3f, sizeof f);

		rep (j, 0, 18) rep (k, 0, 40) f[1][j][k] = j + k;

		rep (i, 1, n) rep (j, 0, 18) rep (k, 0, 40) val[i][j][k] = calc(a[i], j, k);

		rep (i, 2, n) {
			rep (j, 0, 18) {
				rep (k, 0, 40) {
					rep (pre_j, 0, 18) {
						rep (pre_k, 0, 40) {
							// if (f[i - 1][pre_j][pre_k] == 0x3f3f3f3f3f3f3f3f) continue;
							if (val[i - 1][pre_j][pre_k] <= val[i][j][k]) f[i][j][k] = std::min(f[i][j][k], f[i - 1][pre_j][pre_k] + j + k);
						}
					}
				}
			}
		}

		i64 ans = 0x3f3f3f3f3f3f3f3f;
		rep (j, 0, 18) rep (k, 0, 40) ans = std::min(ans, f[n][j][k]);
		std::cout << ans << "\n";
	}
}

void solve() {
	std::freopen("2.in", "r", stdin);
	std::freopen("c.out", "w", stdout);

	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];	

	Task1::solve();
	// else Task2::solve();
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
