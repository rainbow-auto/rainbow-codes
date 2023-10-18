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

const int maxn = 105;
const int maxw = 100005;

int n, W;
int w[maxn];
i64 v[maxn];

i64 dp[maxw];

int main () {
	fastread
	
	std::cin >> n >> W;

	for (int i = 1; i <= n; i++) { std::cin >> w[i] >> v[i]; }

	for (int i = 1; i <= n; i++) {
		for (int j = W; j >= w[i]; j--) {
			dp[j] = std::max (dp[j], dp[j - w[i]] + v[i]);
		}
	}

	std::cout << dp[W] << "\n";

	return 0;
}
