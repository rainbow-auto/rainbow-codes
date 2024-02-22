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

int sum, n;

inline void solve () {
	std::cin >> sum >> n;

	int ans = -1;
	for (int x = 1; x * x <= sum; x++) {
		if (sum % x) { continue; }
		
		if (sum / x >= n) { ans = std::max (ans, x); }
		if (x != sum / x and x >= n) { ans = std::max (ans, sum / x); }
	}

	std::cout << ans << "\n";
}

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) { solve (); }

	return 0;
}
