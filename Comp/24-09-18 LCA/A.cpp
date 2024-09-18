#include <bits/stdc++.h>
// #pragma GCC optimize(2)

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

const i64 mod = 998244353;


namespace Math {
	const int maxn = 1000005;

	inline i64 ksm (i64 a, i64 b) {
		i64 res = 1;
		i64 base = a % mod;
		while (b) {
			if (b & 1) { (res *= base) %= mod; }
			(base *= base) %= mod; b >>= 1;
		}
		return res;
	}

	inline i64 inv (i64 x) { return ksm (x, mod - 2); }

	i64 fac[maxn], ifac[maxn];
	inline void init (int R) {
		fac[0] = 1;
		rep (i, 1, R) { fac[i] = fac[i - 1] * i % mod; }
		ifac[R] = inv (fac[R]);
		per (i, R - 1, 0) { ifac[i] = ifac[i + 1] * (i + 1) % mod; }
	}

	inline i64 choose (i64 a, i64 b) {
		if (a < b) { return 0; }
		return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
	}
}
using namespace Math;

i64 n;

namespace Task0 {
	const int maxn = 100005;
	int p[maxn];

	inline bool chk (int l, int r) {
		int mn = std::min (p[l], p[r]);
		int mx = std::max (p[l], p[r]);
		int flag = -1;
		rep (i, l + 1, r - 1) {
			if (flag == -1) {
				if (p[i] < mn) {
					flag = true;
				} else if (p[i] > mx) {
					flag = false;
				} else {
					return false;
				}
				continue;
			}
			if (flag and p[i] > mx) { return false; }
			if (not flag and p[i] < mn) { return false; } 
			if (p[i] > mn and p[i] < mx) { return false; } 
		}
		return true;
	}

	inline void solve () {
		init (n);

		int ans = 0;
		rep (i, 1, n) { p[i] = i; }
		do {
			// rep (l, 1, n) {
			// 	std::cerr << p[l] << " ";
			// }
			// std::cerr << "\n";

			rep (i, 1, n) {
				rep (j, i + 1, n) {
					rep (k, j + 1, n) {
						// if (std::min ({p[i], p[j], p[k]}) == 1 and std::max ({p[i], p[j], p[k]}) == 3) {
						// 	ans += chk (i, j) and chk (i, k) and chk (j, k);
						// 	if (chk (i, j) and chk (i, k) and chk (j, k)) {
						// 		std::cerr << p[i] << " " << p[j] << " " << p[k] << "\n";
						// 	}
						// }
						ans += chk (i, j) and chk (i, k) and chk (j, k);							
					}
				}
			}
			// std::cerr << "\n";
		} while (std::next_permutation (p + 1, p + n + 1));
		std::cout << ans * ifac[n] % mod << "\n";
		// std::cerr << ans << "\n";
	}
}

namespace Task1 {
	inline void solve () {
		init (n);

		i64 ans = 0;
		rep (i, 1, n) {
			rep (j, i + 1, n) {
				i64 mn = 0;
				rep (t, 1, i - 1) {
					(mn += choose (i - 1, t) * fac[t] % mod * fac[n - 2 - t + 1] % mod) %= mod;
				}
				i64 mx = 0;
				rep (t, 1, n - j) {
					(mx += choose (n - j, t) * fac[t] % mod * fac[n - 2 - t + 1] % mod) %= mod;
				}
				(ans += (mn + mx) % mod * 2ll % mod) %= mod;
			}
		}
		std::cout << ans * ifac[n] % mod << "\n";
	}
}

namespace Task2 {
	i64 f[maxn];

	inline void solve () {
		init (n);

		i64 ans = 0;
		rep (i, 1, n) {
			i64 mn = 0;
			rep (t, 1, i - 1) {
				(mn += choose (i - 1, t) * fac[t] % mod * fac[n - 2 - t + 1] % mod) %= mod;
			}
			rep (j, i + 1, n) {
				i64 mx = 0;
				rep (t, 1, n - j) {
					(mx += choose (n - j, t) * fac[t] % mod * fac[n - 2 - t + 1] % mod) %= mod;
				}
				(ans += (mn + mx) % mod * 2ll % mod) %= mod;
			}
		}
		std::cout << ans * ifac[n] % mod << "\n";
	}
}


bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n;
	// Task0::solve ();
	Task1::solve ();

	return 0;
}
