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

const int maxn = 5005;

int n;
int a[maxn];
int dp[maxn][maxn];

int main ()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i][i] = a[i];
	}
	
	for (int len = 2; len <= n; len ++)
	{
		for (int l = 1; l <= n; l++)
		{
			int r = l + len - 1;
			
			for (int k = l; k <= r - 1; k ++)
			{
				if (dp[l][k] == dp[k + 1][r])
				{
					dp[l][r] = max (dp[l][r], dp[l][k] + 1);
				}
			}
		}
	}
	
	int ans = 0;	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans = max (ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	
	return 0;
}

