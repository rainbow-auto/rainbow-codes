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

const int maxn = 55;
int n, m;

int a[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];

int main ()
{
	fastread
	
	cin >> n >> m;	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				for (int l = 1; l <= m; l++)
				{
					int &t = dp[i][j][k][l];
					
					t = max (t, dp[i - 1][j][k - 1][l]);
					t = max (t, dp[i][j - 1][k - 1][l]);
					t = max (t, dp[i - 1][j][k][l - 1]);
					t = max (t, dp[i][j - 1][k][l - 1]);
					
					if (i == k and j == l) t += a[i][j];
					else t += a[i][j] + a[k][l];
				}
			}
		}
	}
	
	cout << dp[n][m][n][m] << endl;
			
	return 0;
}