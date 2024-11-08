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
using i128 = __int128;

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

inline bool chk (i128 a, i64 x, i128 n) { // a ^ x \leq n
	i128 res = 1;
	while (x) {
		if (a > n) { return false; }
		if (x & 1) { 
			res *= a; 
			if (res > n) { return false; }
		}
		a *= a; x >>= 1;
	}
	return true;
}

i64 calc (i64 n, i64 x) { // n 开 x 次方
	i64 l = 0, r = 1e9;
	i64 res = 0;
	while (l <= r) {
		i64 mid = (l + r) >> 1;
		if (chk (mid, x, n)) { res = mid; l = mid + 1; }
		else { r = mid - 1; }
	}
 
	return res;
}

const int maxn = 1e7 + 5;

std::vector <int> primes;
std::bitset <maxn> np;
int mu[maxn];
inline void sieve () {
	int R = 1e7;
	
	i64 ans = 0;
	np[1] = true;
	mu[1] = 1;
	rep (i, 2, R) {
		if (not np[i]) { primes.push_back (i); mu[i] = -1; }

		for (auto p : primes) {
			if (i * p > R) { break; }
			np[i * p] = true;
			mu[i * p] = -1 * mu[i];
			if (i % p == 0) { mu[i * p] = 0; break; }
		}
	}
}

inline void inversion (i64 n, i64 k) {
	if (k == 1) { std::cout << n << "\n"; return;  }

	int ans = 1;
	rep (i, k, 100) {
		for (int d = i; d <= 100; d += i) {
			ans += mu[d / i] * (calc (n, d) - 1);
		}
	}
	std::cout << ans << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	

	i64 n, k; std::cin >> n >> k;

	sieve ();
	inversion (n, k);

	return 0;
}
