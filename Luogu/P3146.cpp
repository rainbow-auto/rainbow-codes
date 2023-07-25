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

const int maxn = 250;

int n;
int a[maxn];

int dp[maxn][maxn];


int main () {
	fastread
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {cin >> a[i]; dp[i][i] = a[i];}

	for (int len = 2; len <= n; len ++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			
			for (int k = l; k < r; k++) {
				if (dp[l][k] == 0 or dp[k + 1][r] == 0) continue;
				
				if (dp[l][k] == dp[k + 1][r]) {dp[l][r] = max (dp[l][r], dp[l][k] + 1);}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << endl;
 
	return 0;
}
