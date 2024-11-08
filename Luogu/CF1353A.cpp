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


inline void solve () {
	int n, m; std::cin >> n >> m;

	if (n == 1) { std::cout << 0 << "\n"; return; }
	if (n == 2) { std::cout << m << "\n"; return; }

	std::cout << (m << 1) << "\n";
}

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) {
		solve ();
	}

	return 0;
}
