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

const int maxc = 22;
const int maxn = 100005;

int n, m;
char str[maxn];
int near[maxc][maxc];

int sum[1 << maxc];
int dp[1 << maxc];

int main () {
	fastread

	cin >> n >> m;
	cin >> str + 1;

	for (int i = 2; i <= n; i++) {
		near[str[i] - 'a'][str[i - 1] - 'a'] ++;
		near[str[i - 1] - 'a'][str[i] - 'a'] ++;
	}	

	int tot = (1 << m) - 1;

	memset (dp, 0x3f, sizeof(dp));
	dp[0] = 0;

	for (int S = 0; S <= tot; S++) {
		for (int i = 0; i < m; i++) { // i存在于S中
			if (not ((1 << i) & S)) { continue; } // 保证i存在于S中

			for (int j = 0; j < m; j++) {
				if ((1 << j) & S) { continue; } // 保证j不在S中
				sum[S] += near[i][j];
			}
		}
	}

	for (int S = 0; S <= tot; S++) {
		for (int i = 0; i < m; i++) {
			if (S & (1 << i)) {
				dp[S] = min (dp[S], dp[S ^ (1 << i)] + sum[S ^ (1 << i)]); // 相对位置差 = 被加入键盘的时间差, 为了维护时间差, 
			}
		}
	}

	cout << dp[tot] << endl;

	return 0;
}
