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
int x, y, z;

namespace Task0 {
	
	const int maxn = 10;

	int a[maxn];
	int sum[maxn];

	inline bool chk (int now) {
		for (int i = 1; i <= n; i++) { a[i] = (now % 10) + 1; now /= 10; sum[i] = sum[i - 1] + a[i]; }

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (sum[j - 1] - sum[i - 1] != x) { continue; } 
				for (int k = j + 1; k <= n; k++) {
					if (sum[k - 1] - sum[j - 1] != y) { continue; }
					for (int l = k + 1; l <= n; l++) {
						if (sum[l - 1] - sum[k - 1] != z) { continue; }
						return true;
					}
				}
			}
		}

		return false;
	}

	int pw10[maxn];
	inline void solve () {
		pw10[0] = 1;
		for (int i = 1; i <= 5; i++) { pw10[i] = pw10[i - 1] * 10; }

		int ans = 0;
		for (int i = 0; i <= pw10[n]; i++) {
			ans += chk (i);
		}

		std::cout << ans << "\n";
	}
}

int main () {
	fastread
	
	std::cin >> n >> x >> y >> z;

	Task0::solve ();

	return 0;
}
