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

using i64 = __int128;

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

std::bitset <10000000> np;
std::vector <i64> primes;

inline void sieve (int R) {
	np[1] = true;
	for (int i = 2; i <= R; i++) {
		if (not np[i]) { primes.push_back (i); }

		for (auto p : primes) {
			if (p * i > R) { break; }
			np[i * p] = true;
			if (i % p == 0) { break; }
		}
	}
}

i64 n;

int main () {
	fastread
	
	unsigned long long _n; std::cin >> _n; n = _n;

	sieve (10000000);
	
	int ans = 0;
	rep (i, 0, primes.size () - 1) {
		i64 a = primes[i];
		if (a * a > n) { break; }
		
		rep (j, i + 1, primes.size () - 1) {
			i64 b = primes[j];
			if (a * a * b > n) { break; }
		
			rep (k, j + 1, primes.size () - 1) {
				i64 c = primes[k];
				if (a * a * b * c * c > n) { break; }
				
				ans ++;
			}
		}
	}
	
	std::cout << ans << "\n";

	return 0;
}
