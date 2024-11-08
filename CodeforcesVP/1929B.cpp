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

int T;

inline void solve () {
	int n, k; std::cin >> n >> k;
	
	int ans;
	if (k <= 4 * n - 4) { ans = (k + 1) >> 1; }
	else { ans = 2 * n - 2; ans += k - (4 * n - 4); }

	std::cout << ans << "\n";
}

int main () {
	fastread
	
	std::cin >> T;

	while (T--) {
		solve ();
	}

	return 0;
}
