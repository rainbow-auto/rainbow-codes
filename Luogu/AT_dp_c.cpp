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
int a[maxn], b[maxn], c[maxn];

int dp[maxn][3];

int main () {
	fastread

	std::cin >> n;

	for (int i = 1; i <= n; i++) { std::cin >> a[i] >> b[i] >> c[i]; }

	for (int i = 1; i <= n; i++) {
		dp[i][0] = std::max (dp[i - 1][1], dp[i - 1][2]) + a[i];
		dp[i][1] = std::max (dp[i - 1][0], dp[i - 1][2]) + b[i];
		dp[i][2] = std::max (dp[i - 1][0], dp[i - 1][1]) + c[i];
	}

	int res = 0;
	res = std::max (res, dp[n][0]);
	res = std::max (res, dp[n][1]);
	res = std::max (res, dp[n][2]);

	std::cout << res << "\n";

	return 0;
}
