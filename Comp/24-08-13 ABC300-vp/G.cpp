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

int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
const int lim = (1 << 20);

i64 mem[25][lim + 5];

i64 f (i64 n, int curr) {
	if (not curr) { return log2 (n) + 1; }
	if (n <= lim and mem[curr][n]) { return mem[curr][n]; }

	i64 res = f (n, curr - 1);
	if (n >= primes[curr]) { res += f (n / primes[curr], curr); }
	
	if (n <= lim) { mem[curr][n] = res; }
	return res;
}

int main () {
	fastread

	i64 n, k; std::cin >> n >> k;
	
	int pos = std::lower_bound (primes, primes + 25, k) - primes;
	std::cout << f (n, pos) << "\n";

	return 0;
}
