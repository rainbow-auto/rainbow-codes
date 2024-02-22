// not solve by myself

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

int n, k;

inline void solve () {
	std::cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int d = 0; d <= k - 1; d++) {
			std::cout << char('a' + d);
		}
	}
	std::cout << "\n";
}

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) { solve (); }

	return 0;
}
