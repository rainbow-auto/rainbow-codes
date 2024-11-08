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

const i64 mod = 1e5 + 3;
const int maxn = 2005;

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

i64 fac[maxn];
i64 ifac[maxn];
inline void init (int R) {
	fac[0] = 1;
	rep (i, 1, R) { fac[i] = fac[i - 1] * i % mod; }
	ifac[R] = inv (fac[R]);
	per (i, R - 1, 0) { ifac[i] = ifac[i + 1] * (i + 1) % mod; }
}

inline i64 choose (i64 a, i64 b) {
	if (a < 0) { return 0; }
	if (b < 0) { return 0; }
	if (a < b) { return 0; }
	return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

inline i64 f (i64 n, i64 m, int k) {
	return choose (n, k) * choose (m, k) % mod * fac[k] % mod; 	
}

int a, b, c, d, k;

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> a >> b >> c >> d >> k;

	init (2000);

	int n1 = a, m1 = b;
	int n2 = a + c, m2 = d;

	i64 ans = 0;
	rep (x, 0, k) {
		ans += f (n1, m1, x) * f (n2 - x, m2, k - x) % mod;		
		ans %= mod;
	}

	std::cout << ans << "\n";

	return 0;
}
