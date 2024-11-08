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
int h[maxn];
int dp[maxn];

int main () {
	fastread

	std::cin >> n;

	for (int i = 1; i <= n; i++) { std::cin >> h[i]; }

	memset (dp, 0x3f, sizeof (dp));
	dp[0] = dp[1] = 0;

	for (int i = 1; i <= n; i++) {
		dp[i + 1] = std::min (dp[i + 1], dp[i] + abs (h[i] - h[i + 1]));
		dp[i + 2] = std::min (dp[i + 2], dp[i] + abs (h[i] - h[i + 2]));
	}

	std::cout << dp[n] << "\n";

	return 0;
}
