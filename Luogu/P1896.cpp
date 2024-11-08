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

const int maxn = 15;
const int maxS = (1 << 10);

i64 n, k;

i64 dp[maxn][maxS][maxn * maxn];

struct Node {
	i64 S;
	int cnt;
};

std::vector<Node> states;

inline void init () {
	for (int S = 0; S < (1 << n); S ++) {
		if (S & (S >> 1)) { continue; }
		if (S & (S << 1)) { continue; }

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (S & (1 << i)) { cnt ++; }
		}

		states.push_back ({ S, cnt });
	}
}

int main () {
	fastread
	
	std::cin >> n >> k;

	init ();
	for (auto x : states) {
		if (x.cnt <= k) { dp[1][x.S][x.cnt] = 1; }
	}

	for (int i = 2; i <= n; i++) {
		for (auto now : states) {
			for (auto pre : states) {
				if (pre.S & now.S) { continue; }
				if (pre.S & (now.S << 1)) { continue; }
				if ((pre.S << 1) & now.S) { continue; }

				for (int j = 1; j <= k; j++) {
					if (j + now.cnt > k) { continue; } 
					dp[i][now.S][j + now.cnt] += dp[i - 1][pre.S][j];
				}
			}
		}
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		for (auto now : states) {
			ans += dp[i][now.S][k];
		}
	}

	std::cout << ans << "\n";

	return 0;
}
