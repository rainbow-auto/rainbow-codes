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

inline void solve (int l, int r) {
	if ((l << 1) <= r) {
		std::cout << l << " " << (l << 1) << "\n";
	} else {
		std::cout << -1 << " " << -1 << "\n";
	}
}

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) {
		int l, r; std::cin >> l >> r;
		solve (l, r);
	}

	return 0;
}
