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

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) {
		i64 n; std::cin >> n;
		if (n == 1) { std::cout << 1 << "\n"; }
		else { std::cout << n * (n - 1) << "\n"; }
	}	

	return 0;
}
