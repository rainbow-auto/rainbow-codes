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

const int maxn = 3005;
int n;
int a[maxn], b[maxn];

int dp[maxn][maxn];

int main ()
{
	fastread
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
		
	for (int i = 1; i <= n; i++)
	{
		int maxv = 1;
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (a[i] == b[j]) dp[i][j] = max (dp[i][j], maxv);
			if (a[i] > b[j]) maxv = max (maxv, dp[i - 1][j] + 1);
		}
	}	
	
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max (res, dp[n][i]);
	}
	cout << res << endl;
		
	return 0;
}