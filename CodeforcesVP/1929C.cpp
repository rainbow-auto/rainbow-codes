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

i64 k, x, a;

inline void solve () {
	std::cin >> k >> x >> a;

	i64 sum = 0;
	i64 b = 0;

	for (int i = 1; i <= x + 1; i++) {
		b = sum / (k - 1) + 1; sum += b;
		if (sum > a) { std::cout << "NO\n"; return; }
	}

	std::cout << "YES\n";
}

int main () {
	fastread
	
	int T; std::cin >> T;

	while (T--) { solve (); }

	return 0;
}
