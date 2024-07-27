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

int n, k;

int main () {
	fastread

	std::cin >> n >> k;

	int ans = 1, now = k;
	while (now < n) { ans ++; now *= k; }

	std::cout << ans << "\n";

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int col = 0;
			
			int u = i - 1, v = j - 1;
			while (u != v) {
				u /= k;
				v /= k;
				col ++;
			}

			std::cout << col << " ";
		}
	}

	return 0;
}
