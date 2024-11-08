#include <bits/stdc++.h>
#pragma GCC optimize(3)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 305;
const int maxk = 1005;
const int mod = 998244353;

int n, k;

inline i64 ksm (i64 a, i64 b) {
	i64 base = a % mod;
	i64 res = 1;
	while (b) {
		if (b & 1) { res *= base; res %= mod; }
		base *= base; base %= mod; b >>= 1;
	}
	return res;
}

inline i64 inv (i64 x) { return ksm (x, mod - 2); }

i64 fac[maxk + 5];
i64 ifac[maxk + 5];
inline void init () {
	int R = std::max (n, k) + 5;
	fac[0] = 1;
	rep (i, 1, R) { fac[i] = fac[i - 1] * i % mod; }	
	ifac[R] = inv (fac[R]);
	per (i, R - 1, 0) { ifac[i] = ifac[i + 1] * (i + 1) % mod; }
}

inline int choose (i64 a, i64 b) {
	if (a < b) { return 0; }
	return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

namespace Solution {
	int f[maxk][maxn][2];

	i64 inv_nxt[maxn];

	inline void solve () {
		init ();

		rep (j, 0, n) { f[j][j][1 & 1] = choose (n, j); }

		i64 ans = 0;
		rep (i, 1, k) {
			// clear
			rep (j, 1, k) {
				rep (p, 1, n) { 
					// if (i * p > j) { break; }
					f[j][p][(i + 1) & 1] = 0;
				}
			}

			// i64 base = inv (i + 1);
			i64 base = ifac[i + 1] * fac[i] % mod;
			inv_nxt[0] = 1;
			rep (q, 1, n) { inv_nxt[q] = inv_nxt[q - 1] * base % mod; }

			rep (j, 1, k) {
				rep (p, 1, n) { 
					if (i * p > j) { break; }

					rep (q, 1, std::min (p, k - j)) {
						// if ((i + 1) * q > j + q) { break; }

						// i64& to = f[(i + 1) & 1][j + q][q];
						(f[j + q][q][(i + 1) & 1] += 1ll * f[j][p][i & 1] * choose (p, q) % mod * inv_nxt[q] % mod) %= mod;
						// to %= mod;
					}
				}
			}

			// i64 delta = 0;
			rep (p, 1, n) { // 要求至少有一个顶到 i
				// std::cerr << "(" << f[i & 1][k][p] << ", p = " << p << ") ";
				// if (i * p > k) { break; }
				ans += fac[k] * f[k][p][i & 1] % mod * i % mod; ans %= mod;
				// delta += fac[k] * f[i & 1][k][p] % mod * i % mod; delta %= mod;
			}	
			// std::cerr << "\n";
			// std::cerr << "i: " << i << " |" << delta * inv (i) % mod << " " << delta << "\n"; 
		}
		
		std::cout << ans << "\n";
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen ("caged.in", "r", stdin);
	freopen ("caged.out", "w", stdout);

	std::cin >> n >> k;

	Solution::solve ();

	return 0;
}
