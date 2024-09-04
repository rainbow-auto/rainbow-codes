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

const int maxn = 200005;
const i64 mod = 998244353;

int n, m;

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

i64 fac[maxn], ifac[maxn];
inline void init () {
	int R = 200000;

	fac[0] = 1; 
	rep (i, 1, R) { fac[i] = fac[i - 1] * i % mod; }
	ifac[R] = inv (fac[R]);
	per (i, R - 1, 0) { ifac[i] = ifac[i + 1] * (i + 1) % mod; }
}

i64 C (int a, int b) { // a choose b
	if (a - b < 0) { return 0; }
	if (a < 0 or b < 0) { return 0; }
	return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	init ();

	int _; std::cin >> _;
	while (_--) {
		std::cin >> n >> m;
		i64 ans = 0;
		rep (s, 0, m) { // 钦定 min
			rep (x, 0, n) {
				ans += ksm (2ll * m - 2ll * s, 2) * C (s + n - 1, n - 1) % mod * C (n, x) % mod * C (m - s - 1, x - 1) % mod * C (m - s + n - x - 1, n - x - 1) % mod;
				ans %= mod;
			}
		}
		std::cout << ans << "\n";
	}

	return 0;
}
