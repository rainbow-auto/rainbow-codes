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

int n;
std::set <i64> a;

int main () {
	fastread

	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; std::cin >> x;
		a.insert (x);
	}

	// 3 
	for (auto x : a) {
		for (int i = 0; i <= 32; i++) {
			if (a.count (x + (1ll << i)) and a.count (x + (1ll << (i + 1)))) {
				std::cout << "3\n";
				std::cout << x << " " << (x + (1ll << i)) << " " << (x + (1ll << (i + 1))) << "\n";
				return 0;
			}
		}
	}

	// 2
	for (auto x : a) {
		for (int i = 0; i <= 32; i++) {
			if (a.count (x + (1ll << i))) {
				std::cout << "2\n";
				std::cout << x << " " << (x + (1ll << i)) << "\n";
				return 0;
			}
		}
	}

	std::cout << "1\n";
	std::cout << (*a.begin ()) << "\n";

	return 0;
}
