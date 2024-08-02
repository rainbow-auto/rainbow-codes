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

i64 n, k;

int main () {
	fastread

	std::cin >> n >> k;

	i64 ans = n * k;
	for (i64 l = 1, r = 1; l <= n; l = r + 1) {
		if (k / l == 0) { r = n; }
		else { r = std::min (k / (k / l), n); }

		ans -= (k / l) * (l + r) * (r - l + 1) / 2;
	}

	std::cout << ans << "\n";

	return 0;
}
