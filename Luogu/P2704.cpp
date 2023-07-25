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

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

// #define int long long

const int maxn = 105;
const int maxm = 11;
int n, m;

int dp[1 << maxm][1 << maxm][3];
int a[maxn];

int mem[1 << maxm];
inline int count (int x) {
	if (mem[x]) return mem[x];
	
	int res = 0;
	while (x) {res += x & 1; x >>= 1;}
	return res;
}

signed main () {
	fastread
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char now; cin >> now;
			a[i] <<= 1; a[i] += (now == 'H');
		}
	}

	int tot = 1 << m;

	for (int S = 0; S < tot; S++) {
		if (S & a[1] or S & (S << 1) or S & (S << 2)) { continue; } // 有的地方是山(1) 而且也放上了炮兵(1)
		dp[0][S][1] = count(S); // 初始化, 不作限制
	}

	for (int S1 = 0; S1 < tot; S1++) {
		for (int S2 = 0; S2 < tot; S2++) {
			if (S1 & S2) { continue; }
			if (S1 & a[1] or S2 & a[2]) { continue; }
			if (S1 & (S1 << 1) or S1 & (S1 << 2)) { continue; }
			if (S2 & (S2 << 1) or S2 & (S2 << 2)) { continue; }

			dp[S1][S2][2] = count(S1) + count(S2);
		}
	}

	for (int i = 3; i <= n; i++) {
		for (int S1 = 0; S1 < tot; S1++) { // 上一行
			if (S1 & (S1 << 1) or S1 & (S1 << 2)) { continue; }
			if (S1 & a[i - 1]) { continue; }

			for (int S2 = 0; S2 < tot; S2++) { // 当前行
				if (S1 & S2) { continue; }
				if (S2 & (S2 << 1) or S2 & (S2 << 2)) { continue; }
				if (S2 & a[i]) { continue; }

				for (int S3 = 0; S3 < tot; S3++) { // 上上一行
					if (S2 & S3 or S1 & S3) { continue; }
					if (S3 & (S3 << 1) or S3 & (S3 << 2)) { continue; }
					if (S3 & a[i - 2]) { continue; }

					dp[S1][S2][i % 3] = max (dp[S1][S2][i % 3], dp[S3][S1][(i - 1) % 3] + count(S2));
				}	
			}
		}
	}

	int ans = 0;
	for (int S1 = 0; S1 < tot; S1 ++) {
		for (int S2 = 0; S2 < tot; S2 ++) {
			ans = max (ans, dp[S1][S2][n % 3]);
		}
	}
	cout << ans << endl;

	return 0;
}
