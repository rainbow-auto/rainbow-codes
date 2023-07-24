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

const int maxn = 205;

int n;
int a[maxn];
int dp1[maxn][maxn];
int dp2[maxn][maxn];

int sum[maxn];

int main () {
	fastread

	cin >> n;

	memset (dp2, 0x3f, sizeof (dp2));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	
	for (int i = 1; i <= n * 2; i++) {
		dp2[i][i] = 0;
		sum[i] = sum[i - 1] + a[i];
	} 

	for (int len = 2; len <= n; len ++) {
		for (int l = 1; l + len - 1 <= n * 2; l++) {
			int r = l + len - 1;

			for (int k = l; k < r; k++) {
				dp1[l][r] = max (dp1[l][r], dp1[l][k] + dp1[k + 1][r] + sum[r] - sum[l - 1]);
				dp2[l][r] = min (dp2[l][r], dp2[l][k] + dp2[k + 1][r] + sum[r] - sum[l - 1]);
			}
		}
	}

	int ans1 = 0, ans2 = 0x3f3f3f3f;

	for (int l = 1; l <= n; l++) {
		int r = l + n - 1;
		ans1 = max (ans1, dp1[l][r]);
		ans2 = min (ans2, dp2[l][r]);
	}

	cout << ans2 << endl;
	cout << ans1 << endl;

	return 0;
}
