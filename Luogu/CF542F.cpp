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

const int maxt = 205;
const int maxn = 2005;

int n, T;

int dp[maxt][maxn];

int maxh;
std::vector<int> q[maxt];

inline bool comp (int a, int b) {
	return a > b;
}

int main () {
	fastread

	std::cin >> n >> T;

	for (int i = 1; i <= n; i++) {
		int a, b; std::cin >> a >> b; // (t, q)
		q[T - a].push_back (b);
	}

	for (int i = 0; i <= 100; i++) { std::sort (q[i].begin (), q[i].end (), comp); }

	for (int h = 100; h >= 0; h--) { 
		for (int j = 0; j <= 1000; j++) { // 上一层已经占用的
			int sum = 0;

			dp[h][(j + 1) / 2] = std::max (dp[h][(j + 1) / 2], dp[h + 1][j]);
			
			for (int k = 1; k <= q[h].size (); k++) {
				sum += q[h][k - 1];

				dp[h][(j + 1) / 2 + k] = std::max (dp[h][(j + 1) / 2 + k], dp[h + 1][j] + sum);
			}
		}
	}

	std::cout << dp[0][1] << "\n";

	return 0;
}
