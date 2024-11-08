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
const int maxv = maxn * 1005;

int n;
i64 W;
int v[maxn];
i64 w[maxn];

i64 dp[maxv];

int main () {
	fastread

	std::cin >> n >> W;

	int sumv = 0;
	for (int i = 1; i <= n; i++) { std::cin >> w[i] >> v[i]; sumv += v[i]; }

	memset (dp, 0x3f, sizeof (dp));
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = sumv; j >= v[i]; j--) {
			dp[j] = std::min (dp[j], dp[j - v[i]] + w[i]);
		}
	}

	for (int i = sumv; i; i--) { if (dp[i] <= W) { std::cout << i << "\n"; break; } }
	
	return 0;
}
