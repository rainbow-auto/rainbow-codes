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

const int maxn = 305;
const int maxk = 1005;
const i64 mod = 998244353;

i64 n, k;

namespace Task1 {
	int ans = 0;

	int cnt[maxn], mx;
	void dfs (int now) {
		if (now > k) { ans += mx; return; }

		rep (i, 1, n) {
			int old = mx;
			cnt[i] ++;
			
			if (cnt[i] > mx) { mx = cnt[i]; }
			dfs (now + 1);
			
			cnt[i] --;
			mx = old;
		}
	}	
	
	inline void solve () {
		dfs (1);
		std::cout << ans << "\n";
	}
}	

namespace Task2 {

	i64 f[maxn][maxk << 1];

	inline i64 ksm (i64 a, i64 b) {
		i64 res = 1;
		i64 base = a % mod;
		while (b) {
			if (b & 1) { res *= base; res %= mod; }
			base *= base; base %= mod; b >>= 1;
		}
		return res;
	}

	inline i64 inv (i64 x) { return ksm (x, mod - 2); }

	i64 fac[maxk], ifac[maxk];
	inline void init () {
		fac[0] = 1;
		rep (i, 1, k) { fac[i] = fac[i - 1] * i % mod; }
		ifac[k] = inv (fac[k]);
		per (i, k - 1, 0) { ifac[i] = ifac[i + 1] * (i + 1) % mod; }
	}

	inline i64 choose (int x, int y) { // x choose y
		if (x < y) { return 0; }
		return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
	}

	// 假了
	inline void solve () {
		init ();

		i64 ans = 0;
		rep (cnt, 1, k) {
			// f[0][k] = 1;

			rep (i, 1, n) {
				rep (j, 0, k) { // 剩余
					f[i][j] = 0;
					// int tot = 0;
					rep (pre, j, j + cnt) { // 之前的剩余
						// 选择了 pre - j 个数
						// i64 from += f[i - 1][pre] * choose (pre, pre - j) % mod;
						// if (from > 0) { f[i][j] *= from; f[i][j] %= mod; tot ++; }
						f[i][j] += f[i - 1][pre] * choose (pre, pre - j) % mod;
					}
					// if (not tot) { f[i][j] = 0; }
				}
			}

			// std::cerr << "cnt: " << cnt << " " << f[n][0] << "\n";

			ans += f[n][0]; ans %= mod;
		}

		std::cout << ans << "\n";
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	// freopen ("caged.in", "r", stdin);
	// freopen ("caged.out", "w", stdout);

	std::cin >> n >> k;

	if (n <= 7) {
		Task1::solve ();
	} else {
		Task2::solve ();
	}

	return 0;
}
