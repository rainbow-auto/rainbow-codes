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

const int maxn = 2005;
const i64 mod = 1e9 + 7;

int n;
int a[maxn];

namespace Math {
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

	i64 fac[maxn << 1], ifac[maxn << 1];
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

namespace Task1 {
	i64 f[maxn][maxn];

	inline void solve () {
		rep (i, 1, n) { f[i][0] = 1; }
		f[1][1] = 1;
		rep (i, 2, n) {
			per (j, i - 1, 0) {
				if (a[j] > a[i]) { continue; }
				i64 cnt = 0;
				rep (k, j + 1, i - 1) { cnt += (a[k] > a[i] or a[k] < a[j]); }		

				i64 len = i - j - 1;
				rep (pre, 0, j) {
					f[i][pre + 1] += f[j][pre] * choose ((j - pre) + len, len) % mod * cnt % mod * fac[len - 1] % mod; 
					f[i][pre + 1] %= mod;
				}
			}

			rep (j, 1, i) { std::cerr << f[i][j] << " "; } std::cerr << "\n";
		}
	
		i64 ans = 0;
		rep (i, 1, n) {
			if (i == n) { 
				rep (pre, 1, n) { ans += f[i][pre]; ans %= mod; }	
				continue; 
			}

			i64 cnt = 0;
			rep (j, i + 1, n) { cnt += (a[j] < a[i]); }
			i64 len = n - i;
			rep (pre, 1, i) {
				ans += choose ((i - pre) + len, len) * f[i][pre] % mod * cnt % mod * fac[len - 1] % mod;
				ans %= mod;
			}
		}
		
		std::cout << ans << "\n";
	}
}

namespace Task2 {
	inline void solve () {
		std::map <int, int> dbt;

		i64 ans = 0;
		a[n + 1] = 2e9;

		rep (S, 0, (1 << n) - 1) {
			std::vector <std::pair <int, int> > nums;

			nums.push_back ({ 0, 0 });
			rep (i, 1, n) {
				if (S & (1 << (i - 1))) { nums.push_back ({ i, a[i] }); }
			}
			nums.push_back ({ n + 1, 2e9 });

			bool down = true;

			int last = 0;
			for (auto x : nums) { down &= x.second >= last; last = x.second; }

			if (not down) { continue; }

			i64 cnt = 0;
			rep (t, 1, (int) nums.size () - 1) {
				int i = nums[t].first;
				int j = nums[t - 1].first;

				rep (k, j + 1, i - 1) { cnt += (a[k] < a[j] or a[k] > a[i]); }
			}

			i64 len = nums.size () - 2;

			if (not cnt) { continue; }

			dbt[len] += cnt;

			ans += fac[n - len - 1] * cnt % mod;
			ans %= mod;
		}

		for (auto [len, cnt] : dbt) { std::cerr << "len: " << len << " " << cnt << "\n"; }

		std::cout << ans << "\n";
	}
}

namespace Task3 {
	i64 f[maxn][maxn];
	i64 g[maxn][maxn];

	inline void solve () {
		a[n + 1] = 2e9;

		g[0][0] = 1;

		rep (i, 1, n + 1) {
			rep (j, 0, i - 1) {
				if (a[j] > a[i]) { continue; }
				
				i64 cnt = 0;
				rep (k, j + 1, i - 1) { cnt += (a[k] > a[i] or a[k] < a[j]); }

				rep (pre, 0, j) {
					(f[i][pre + 1] += (f[j][pre] + g[j][pre] * cnt % mod) % mod) %= mod;
					(g[i][pre + 1] += g[j][pre]) %= mod;
				}
			}
		}

		i64 ans = 0;

		rep (k, 2, n + 1) {
			int len = k - 1;
			ans += f[n + 1][k] * fac[n - len - 1] % mod;
			ans %= mod;
		}
		
		std::cout << ans << "\n";
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen ("delete.in", "r", stdin);
	freopen ("delete.out", "w", stdout);

	init (4000);

	std::cin >> n;
	rep (i, 1, n) { std::cin >> a[i]; }

	// Task1::solve ();
	// Task2::solve ();
	Task3::solve ();

	return 0;
}

/*
len = 1 9
len = 2 6
len = 3 1
len = 4 0

len: 1 6
len: 2 6
*/