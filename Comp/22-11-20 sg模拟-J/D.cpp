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

const int maxn = 105;
const int mod = 1000007;

int n, m;
int a[maxn];

int dp[maxn][maxn];

int main ()
{
	freopen ("flower.in", "r", stdin);
	freopen ("flower.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
		
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k <= a[i]; k++) 
			{
				if (j - k < 0) break;
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
			}
		}	
	}	

	cout << dp[n][m] << endl;	
		
	fclose (stdin);
	fclose (stdout);	
		
	return 0;
}

