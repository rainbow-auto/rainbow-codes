#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxn = 3005;
const int maxp = 15;

int n, k;

int w[maxn][maxp];
int p[maxn];

int dp1[maxn][maxn]; // Õý 
int dp2[maxn][maxn]; // ·´ 

int main ()
{

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	
		for (int j = 1; j <= p[i]; j++) {
			cin >> w[i][j];
		}		
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = p[i]; j <= k; j++) {
			dp1[i][j] = max (dp1[i][j], dp1[i - 1][j - p[i]] + w[i][p[i]]);
		}
	}
	
	for (int i = n; i >= 1; i--) {
		for (int j = p[i]; j <= k; j++) {
			dp2[i][j] = max (dp2[i][j], dp2[i - 1][j - p[i]] + w[i][p[i]]);
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		int mx = 0;
		int mxj = 0;
		for (int j = 1; j <= p[i]; j++) {
			if (mx <= w[i][j]) {
				mx = w[i][j];
				mxj = j;
			}
		}0
		
		int sum = k - mxj + 2;
		
		cout << "mx = " << mx << " mxj = " << mxj << endl;
		cout << "sum = " << sum << endl;	
			
		for (int x = 0; x <= sum; x++) {
			int l = x;
			int r = sum - x;
		
			cout << "l:" << dp1[i - 1][l] << endl;
			cout << "r: " << dp2[i + 1][r] << endl;
			cout << "ans" << x << " " << dp1[i - 1][l] + dp2[i + 1][r] + mx << endl;
		
			ans = max (ans, dp1[i - 1][l] + dp2[i + 1][r] + mx);
		}		
	}
	
	cout << ans << endl; 

	return 0;
}

