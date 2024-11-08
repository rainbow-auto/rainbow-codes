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

const i64 mod = 1e9 + 7;

inline i64 mul (i64 a, i64 b, i64 p = mod) {
	i64 base = a % p;
	i64 res = 0;
	while (b) {
		if (b & 1) { res += base; res %= p; }
		base += base; base %= p; b >>= 1;
	}
	return res;
}

inline i64 ksm (i64 a, i64 b, i64 p = mod) {
	i64 base = a % p;
	i64 res = 1;
	while (b) {
		if (b & 1) { res = mul (res, base, p); }
		base = mul (base, base, p); b >>= 1;
	}
	return res;
}

inline i64 inv (i64 x) { return ksm (x, mod - 2, mod); }

namespace Task1 {
	inline void solve (i64 l, i64 r) {
		i64 pw2 = ksm (2, l);
		i64 pw2mod3 = ksm (2, l, 3);

		i64 ans = 0;
		rep (k, l, r) {
			i64 x = pw2;
			i64 rest = pw2mod3;
			ans = (ans + (((x - rest) % mod) + mod) % mod) % mod;
			
			pw2 = pw2 * 2ll % mod;
			pw2mod3 = pw2mod3 * 2ll % 3;
		}

		std::cout << ans * inv (3) % mod << "\n";
	}

	inline void solve1 (i64 l, i64 r) {
		i64 pw2 = ksm (2, l);

		i64 ans = 0;
		rep (k, l, r) {
			i64 x = pw2;
			ans = (ans + x) % mod;
			
			pw2 = pw2 * 2ll % mod;
		}

		std::cerr << ans << "\n";

		i64 delta = 0;

		i64 pw2mod3 = ksm (2, l, 3);
		rep (k, l, r) {
			i64 rest = pw2mod3;
			ans -= rest; ans += mod; ans %= mod;

			delta += rest;

			pw2mod3 = pw2mod3 * 2ll % 3;
		}

		std::cerr << delta << "\n";

		std::cout << ans * inv (3) % mod << "\n";
	}
}

namespace Solution {
	inline void make_table (i64 l, i64 r) {
		rep (i, 1, r) {
			std::cerr << ksm (2, i, 3) << " ";
		}
		std::cerr << "\n";
		rep (i, 1, r) {
			std::cerr << ((i & 1) ? 2 : 1) << " ";
		}
	}

	inline i64 SumOfPw2Mod3 (i64 x) {
		i64 res = mul (3, (x >> 1));
		res += 2ll * bool (x & 1);
		return res % mod;
	}

	inline void solve (i64 l, i64 r) {
		i64 a = ((ksm (2, r + 1) - ksm (2, l)) % mod + mod) % mod;
		i64 b = ((SumOfPw2Mod3 (r) - SumOfPw2Mod3 (l - 1)) % mod + mod) % mod;
		i64 res = ((a - b) % mod + mod) % mod * inv (3) % mod;
		std::cout << res << "\n";
	}
}

// 458948306
// 489528041

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	// freopen ("a.in", "r", stdin);
	// freopen ("a.out", "w", stdout);

	i64 l, r; std::cin >> l >> r;

	// Task1::solve (l, r);
	// Solution::make_table (l, r);
	// Task1::solve1 (l, r);
	Solution::solve (l, r);

	return 0;
}
