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

const int maxn = 100105;

int n, k;
int h[maxn];

int dp[maxn];

int main () {
	fastread

	std::cin >> n >> k;

	for (int i = 1; i <= n; i++) { std::cin >> h[i]; }

	memset (dp, 0x3f, sizeof (dp));
	dp[1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i + j] = std::min (dp[i + j], dp[i] + abs (h[i] - h[i + j]));
		}
	}

	std::cout << dp[n] << "\n";

	return 0;
}
