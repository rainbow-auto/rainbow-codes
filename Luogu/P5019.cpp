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

const int maxn = 100005;

int n;
int a[maxn];

int main () {
	fastread
	
	std::cin >> n;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

	int ans = 0;

	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] > 0) { ans += a[i] - a[i - 1]; }
	}

	std::cout << ans << "\n";

	return 0;
}
