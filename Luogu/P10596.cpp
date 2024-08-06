#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using i64 = long long;

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 1000005;
const i64 mod = 1e9 + 7;

i64 n, k;

inline i64 ksm (i64 a, i64 b) {
	i64 res = 1;
	while (b) {
		if (b & 1) { res = (res * a) % mod; }
		a = (a * a) % mod; b >>= 1;
	} 
	return res;
}

i64 fac[maxn];

i64 pp2[maxn]; // 2 ^ {2 ^ i}

inline void init () {
	fac[0] = 1;
	for (i64 i = 1; i <= n; i++) { fac[i] = (fac[i - 1] * i) % mod; }
	pp2[0] = 2;
	for (int i = 1; i <= n; i++) { pp2[i] = (pp2[i - 1] * pp2[i - 1]) % mod; }
}

inline i64 inv (i64 x) { return ksm (x, mod - 2); }

inline i64 C (i64 n, i64 m) { // n \choose m
	return (((fac[n] * inv (fac[n - m])) % mod) * inv (fac[m])) % mod;
}

int main () {
	fastread

	std::cin >> n >> k;

	init ();

	i64 ans = 0;
	for (i64 i = k; i <= n; i++) {
		// ans = ans + (((i - k) & 1) ? -1 : 1) * C (i, k) * C (n, i) * (pp2[n - i] - 1); 
 		ans = (ans + ((((i - k) & 1) ? -1 : 1) * (((C (i, k) * C (n, i)) % mod) * (pp2[n - i] - 1) % mod) % mod + mod) % mod) % mod;
	}

	std::cout << ans << "\n";

	return 0;
}
