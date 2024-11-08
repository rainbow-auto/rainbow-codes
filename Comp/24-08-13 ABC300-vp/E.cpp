#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

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

const i64 mod = 998244353;

inline i64 ksm (i64 a, i64 b) {
	i64 res = 1; a %= mod;
	while (b) {
		if (b & 1) { res *= (a % mod); res %= mod; }
		a *= (a % mod); a %= mod; b >>= 1;
	}
	return res;
}

inline i64 inv (i64 x) { return ksm (x, mod - 2); }

i64 inv5;

std::unordered_map <i64, i64> mem;

i64 f (i64 x) {
	if (x == 1) { return 1; }
	if (mem.count (x)) { return mem[x]; }

	i64 res = 0;
	rep (i, 2, 6) { if (x % i == 0) { res += inv5 * f (x / i); res %= mod; }; }

	mem[x] = res; return res;
}

int main () {
	fastread

	inv5 = ksm (5, mod - 2);

	i64 n; std::cin >> n;

	std::cout << f (n);

	return 0;
}
