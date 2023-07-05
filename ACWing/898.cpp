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

using namespace std;

const int maxn = 505;
int n;
int a[maxn][maxn];
int dp[maxn][maxn];

int main ()
{
	fastread
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}
	
	fill (dp[0], dp[0] + maxn * maxn, -0x3f3f3f3f);
	
	dp[1][1] = a[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j =1; j <= i; j++)
		{
			dp[i][j] = max (dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
		}
	}
	
	int ans = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		ans = max (dp[n][i], ans);
	}
	cout << ans << endl;
	
	return 0;
}