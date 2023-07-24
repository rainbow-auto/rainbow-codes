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

const int maxn = 505;

int n;

int a[maxn];
int dp[maxn][maxn];

int main () {
	fastread
	
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) { for (int j = 1; j <= n; j++) { dp[i][j] = 0x3f3f3f3f; } }

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
		if (a[i] == a[i + 1]) { dp[i][i + 1] = 1; }
		else { dp[i][i + 1] = 2; }
	}

	for (int len = 3; len <= n; len ++) {
		for (int l = 1; l + len - 1 <= n; l ++) {
			int r = l + len - 1;
			
			if (a[l] == a[r]) { dp[l][r] = dp[l + 1][r - 1]; }
			
			for (int k = l; k < r; k++) {
				dp[l][r] = min (dp[l][r], dp[l][k] + dp[k + 1][r]);
			}
		}
	}

	cout << dp[1][n] << endl;

	return 0;
}
