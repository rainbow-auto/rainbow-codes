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

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cout << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 25;

const int maxS = (1 << 23) + 5;

int n, m;
int dp[maxS];
int fa[maxS];
int path[maxS];

int friends[maxn]; // friends

void output (int now) {
	if (fa[now]) { output (fa[now]); }
	std::cout << path[now] << " ";
}

int main () {
	fastread

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { friends[i] |= (1 << (i - 1)); }
	
	for (int i = 1; i <= m; i++) {
		int u, v; std::cin >> u >> v;
		friends[u] |= (1 << (v - 1));
		friends[v] |= (1 << (u - 1));
	}

	if (m == n * (n - 1) / 2) { std::cout << "0\n"; return 0; }

	memset (dp, 0x3f, sizeof (dp));

	for (int i = 1; i <= n; i++) {
		dp[friends[i]] = 1;
		path[friends[i]] = i;
	}

	for (int S = 0; S < (1 << n); S++) {
		if (dp[S] == 0x3f3f3f3f) { continue; }
		
		for (int i = 1; i <= n; i++) { // 通过 i 转移
			if (S & (1 << (i - 1))) { 
				int tS = (S | friends[i]);
				
				if (dp[S] + 1 < dp[tS]) {
					dp[tS] = dp[S] + 1;
					path[tS] = i;
					fa[tS] = S;
				}
			}
		}
	}

	std::cout << dp[(1 << n) - 1] << "\n";

	output ((1 << n) - 1);

	return 0;
}
