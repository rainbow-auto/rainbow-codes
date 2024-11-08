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
bool MemST;

i64 mul (i64 a, i64 b, i64 mod) {
	i64 res = 0;
	a %= mod;
	while (b) {
		if (b & 1) { res += a; res %= mod; }
		a += a; a %= mod; b >>= 1;
	}
	return res;
}

bool MemED;
int main () {
	fastread
	// lookMem	

	i64 a, b, mod;
	std::cin >> a >> b >> mod;

	std::cout << mul (a, b, mod) << "\n";

	return 0;
}
