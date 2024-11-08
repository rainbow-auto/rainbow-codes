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

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 10005;

int n;
int a[maxn];

inline void solve () {
	std::cin >> n;
	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
	
	std::sort (a + 1, a + n + 1);

	int ans = 0;
	for (int i = 2; i <= n; i++) {
		ans += a[i] - a[i - 1];
	}

	std::cout << ans << "\n";
}

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) {
		solve ();
	}
	
	return 0;
}
