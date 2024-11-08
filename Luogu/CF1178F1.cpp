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

const int maxn = 505;	
const int mod = 998244353;

int n, m;
int a[maxn];

int dp[maxn][maxn];

inline int get_min_pos (int l, int r) {
	int mn = 0x3f3f3f3f, pos = 0;
	for (int i = l; i <= r; i++) {
		if (mn > a[i]) {mn = a[i]; pos = i;}
	}
	return pos;
}

signed main () {
	fastread
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i <= n; i++) {
		dp[i + 1][i] = 1; dp[i][i] = 1;
	}
	
	for (int len = 2; len <= n; len ++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len -  1;
			int pos = get_min_pos (l, r);			

			int lsum = 0, rsum = 0;
			for (int i = l - 1; i <= pos - 1; i ++) {
				lsum = (lsum + dp[l][i] * dp[i + 1][pos - 1] % mod) % mod; 
			}	

			for (int i = pos; i <= r; i++) { // 不是pos + 1的原因是左边可以不选
				rsum = (rsum + dp[pos + 1][i] * dp[i + 1][r] % mod) % mod;
			}

			dp[l][r] = (lsum * rsum) % mod;
		}
	}

	cout << dp[1][n] << endl;

	return 0;
}
