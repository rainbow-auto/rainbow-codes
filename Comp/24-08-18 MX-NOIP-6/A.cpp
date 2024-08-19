#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
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

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

const i64 mod = 1e9 + 7;

i64 l, r;

inline i64 ksm (i64 a, i64 b) {
	i64 res = 1;
	a %= mod;

	while (b) {
		if (b & 1) { res *= a; res %= mod; }
		a *= a; a %= mod; b >>= 1;
	}

	return res;
}

namespace Task1 {

	std::set <i64> nums;

	inline void solve () {
		rep (i, 0, 10000) { nums.insert (i * i); }
		nums.insert (-1e9);

		i64 ans = ksm (10, 1000);
		rep (i, l, r) {
			auto it = nums.lower_bound (i);
			
			i64 dis1 = (*it) - i;
			i64 dis2 = i - (*std::prev (it));

			i64 delta;
			if (dis1 < dis2) { delta = (((i64) sqrt (*it) & 1) ? 1 : -1) * i % mod; }
			else { delta = (((i64) sqrt (*std::prev (it)) & 1) ? 1 : -1) * i % mod; }

			std::cerr << delta << " ";
			ans = (ans + (delta + mod) % mod) % mod;
		}

		ans = ((ans % mod - ksm (10, 1000) % mod) % mod + mod) % mod;
		
		std::cout << ans << "\n";
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	

	// freopen ("alice.in", "r", stdin);
	// freopen ("alice.out", "w", stdout);

	std::cin >> l >> r;

	Task1::solve ();

	return 0;
}
