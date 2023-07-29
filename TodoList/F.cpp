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

#define int long long

const int maxn = 3005;
const int maxp = 15;

int n, k;

int w[maxn][maxp];
int p[maxn];

int dp1[maxn][maxn]; // 正 
int dp2[maxn][maxn]; // 反 

signed main () {

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	
		for (int j = 1; j <= p[i]; j++) {
			cin >> w[i][j];
		}		
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = k; j >= 0; j--) {
			if (j >= p[i]) {
				dp1[i][j] = max (dp1[i - 1][j], dp1[i - 1][j - p[i]] + w[i][p[i]]);
			} else {
				dp1[i][j] = dp1[i - 1][j];
			}
		}
	}
	
	for (int i = n; i >= 1; i--) {
		for (int j = k; j >= 0; j--) {
			if (j >= p[i]) {
				dp2[i][j] = max (dp2[i + 1][j], dp2[i + 1][j - p[i]] + w[i][p[i]]);
			} else {
				dp2[i][j] = dp2[i + 1][j];
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= p[i]; j++) {
			for (int x = 0; x + j <= k; x++) {
				int l = x;
				int r = k - x - j;

				// if (i == 3 and j == 1) {
				// 	cout << "x = " << x << endl;
				// 	cout << "j = " << j << endl;

				// 	cout << "l limit: " << l << endl;
				// 	cout << "r limit: " << r << endl;

				// 	cout << "lw: " << dp1[i - 1][l] << endl;
				// 	cout << "rw: " << dp2[i + 1][r] << endl;
				// 	cout << "w: " << w[i][j] << endl;

				// 	cout << endl;
				// }

				ans = max (ans, dp1[i - 1][l] + dp2[i + 1][r] + w[i][j]);
			}		
		}
		
	}
	
	cout << ans << endl; 

	return 0;
}
