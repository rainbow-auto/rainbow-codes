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

inline bool check (int a, int b) {
	if (a % 2 != 0 and b % 2 != 0) { return false; }
	if (a % 2 != 0) { std::swap (a, b); }
	a /= 2;
	return a != b;
}

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) {
		int a, b; std::cin >> a >> b;
		if (check (a, b) or check (b, a)) { std::cout << "Yes\n"; }
		else { std::cout << "No\n"; }
	}
	
	return 0;
}
