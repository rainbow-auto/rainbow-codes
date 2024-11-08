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

const int maxn = 100005;
const int inf = 999999999;

int n, c;
int h[maxn];
int dp[maxn][105];
int maxh;

int main ()
{
	fastread
	
	cin >> n >> c;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];	
		maxh = max (maxh, h[i]);
	}	
	
	fill (dp[0] + 1, dp[0] + maxn * 105, inf);
	for (int i = h[1]; i <= maxh; i++)
	{
		dp[1][i] = (i - h[1]) * (i - h[1]);
	}
		
	for (int i = 2; i <= n; i++)
	{
		int k = h[i - 1];
		for (int j = h[i]; j <= maxh; j ++)
		{
			while (dp[i - 1][k] + c * abs(j - k) > dp[i - 1][k + 1] + c * abs (j - k - 1) and k < maxh) k ++;
			
			dp[i][j] = dp[i - 1][k] + c * abs(j - k) + (j - h[i]) * (j - h[i]);
		}
	}
	
	int ans = inf;
	for (int i = h[n]; i <= maxh; i++)
	{
		ans = min (ans, dp[n][i]);
	}
	cout << ans << endl;
			
	return 0;
}
