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

const int mod = 9901;

i64 a, b;
std::map <int, i64> cnt;

i64 ksm (i64 a, i64 b) {
	i64 base = a % mod;
	i64 res = 1;
	while (b) {
		if (b & 1) { res *= base; res %= mod; }
	 	base *= base; base %= mod; b >>= 1;
	}
	return res;
}

i64 inv (i64 x) { return ksm (x, mod - 2); }

inline i64 sum (i64 p, i64 n) {
	if ((p - 1) % mod == 0) { return (n + 1) % mod; }
	else { return ((ksm (p, n + 1) - 1) % mod + mod) % mod * inv (p - 1) % mod; }
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> a >> b;
	if (a == 0) { std::cout << "0\n"; return 0; }

	for (i64 i = 2; i * i <= a; i ++) {
		while (a % i == 0) {
			cnt[i] ++;
			a /= i;
		}
	}
	if (a != 1) { cnt[a] ++; }

	for (auto& now : cnt) { now.second *= b; }

	i64 ans = 1;
	for (auto now : cnt) {
		ans = (ans * sum (now.first, now.second)) % mod;
	}

	std::cout << ans << "\n";

	return 0;
}
