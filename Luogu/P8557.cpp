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

inline i64 ksm (i64 a, i64 b) {
	i64 base = a % mod;
	i64 res = 1;
	while (b) {
		if (b & 1) { res *= base; res %= mod; }
		base *= base; base %= mod; b >>= 1;
	}
	return res;
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	i64 n, k; std::cin >> n >> k;
	
	i64 ans = ksm (ksm (2, k) - 1, n);
	std::cout << ans << "\n";

	return 0;
}
