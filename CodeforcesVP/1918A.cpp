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
	int n, m; std::cin >> n >> m;

	std::cout << (n * (m >> 1)) << "\n";
}

int main () {
	fastread
	
	std::cin >> T;

	while (T--) {
		solve ();
	}

	return 0;
}
