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

const int maxS = (1 << 24) + 5;

int n;
int sum[maxS];

int main () {
	fastread
	
	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		int currS = 0;

		for (int j = 1; j <= 3; j++) {
			char c; std::cin >> c;
			if (c > 'x') { continue; }
			currS |= (1 << (c - 'a'));
		}

		sum[currS] ++;
	}

	for (int i = 0; i < 24; i++) { 
		for (int S = 0; S < (1 << 24); S++) {
			if (S & (1 << i)) { 
				sum[S] += sum[S ^ (1 << i)]; ;
			}
		} 
	}

	int ans = 0;
	for (int S = 0; S < (1 << 24); S++) {
		ans ^= (n - sum[S]) * (n - sum[S]);
	}

	std::cout << ans << "\n";

	return 0;
}
