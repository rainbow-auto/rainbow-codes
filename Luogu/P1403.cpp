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

const int maxn = 1000005;

int n;

int main () {
	fastread
	
	std::cin >> n;

	i64 ans = 0;

	for (int l = 1, r = 1; l <= n; l = r + 1) {
		r = (n / (n / l));
		ans += (r - l + 1) * (n / l);
	}

	std::cout << ans << "\n";

	return 0;
}
