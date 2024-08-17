#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

const int maxn = 25;
const int maxS = (1 << 20) + 5;

int n, k;
int c[maxn][maxn];

int dp[maxS];

int main () {
	fastread
	
	std::cin >> n >> k;
	rep (i, 1, n) {
		rep (j, 1, n) {
			std::cin >> c[i][j];
		}
	}

	memset (dp, 0x3f, sizeof (dp));
	dp[0] = 0;

	rep (S, 1, (1 << n) - 1) { // S 维护的是补集, S[i] 为 1 表示 i 无水
		std::vector <int> st[2];
		rep (i, 1, n) { st[bool (S & (1 << (i - 1)))].push_back (i); }

		for (auto i : st[1]) { // 无水
			for (auto j : st[0]) { // 有水
				dp[S] = std::min (dp[S], dp[S ^ (1 << (i - 1))] + c[i][j]);
			}
		}
	}

	int ans = 0x3f3f3f3f;
	rep (S, 0, (1 << n) - 1) {
		int cnt0 = 0;
		rep (i, 1, n) { cnt0 += bool (S & (1 << (i - 1))) ^ 1; }
		if (cnt0 <= k) { ans = std::min (ans, dp[S]); }
	}

	std::cout << ans << "\n";

	return 0;
}
