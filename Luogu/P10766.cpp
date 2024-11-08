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

const int maxn = 500005;

int n;
std::string s, t;

int dp[maxn][3];
inline void solve () {
	memset (dp, 0x3f, sizeof (dp));
	
	dp[1][0] = 1 + (t[1] == '1');
	dp[1][1] = 1 + (t[1] == '0');
	dp[1][2] = (s[1] != t[1]);

	for (int i = 2; i <= n; i++) {
		for (int now = 0; now <= 2; now ++) {
			for (int pre = 0; pre <= 2; pre ++) {
				int cost1 = 0;
				if (now == 2) { cost1 = 0; }
				else { cost1 = (now != pre); }
				
				int now_c = (now == 2) ? (s[i] - '0')     : now;
				int pre_c = (pre == 2) ? (s[i - 1] - '0') : pre;
				int cost2 = ((now_c ^ (t[i] - '0')) == 1 and (pre_c ^ (t[i - 1] - '0')) == 0);

				dp[i][now] = std::min (dp[i][now], dp[i - 1][pre] + cost1 + cost2);
			}
		}
	}

	int res = 0x3f3f3f3f;
	res = std::min (res, dp[n][0]);
	res = std::min (res, dp[n][1]);
	res = std::min (res, dp[n][2]);
	std::cout << res << "\n";
}

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) {
		std::cin >> s >> t;
		n = s.size ();
		s = " " + s;
		t = " " + t;

		solve ();
	}
	

	return 0;
}
