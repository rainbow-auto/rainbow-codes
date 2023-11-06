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

const int maxn = 100005;

int n;
int dp[maxn][4][3];
int v[maxn][4];

int main ()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> v[i][j];
		}
	}
	
	int ans = 0;
	for (int front = 1; front <= 3; front ++)
	{
		for (int i = 1; i <= 3; i++) // init
		{
			dp[1][i][1] = 0;
			dp[1][i][2] = 0;
		}
		dp[1][front][1] = v[1][front];
		dp[1][front][2] = v[1][front];
		
		for (int i = 2; i <= n; i++)
		{
			dp[i][1][1] = max (dp[i - 1][2][2], dp[i - 1][3][2]) + v[i][1];
			dp[i][2][1] = dp[i - 1][3][2] + v[i][2];
			dp[i][2][2] = dp[i - 1][1][1] + v[i][2];
			dp[i][3][2] = max (dp[i - 1][2][1], dp[i - 1][1][1]) + v[i][3];
		}
		for (int i = 1; i < front; i++)
		{
			ans = max (ans, dp[n][i][1]);	
		}
		for (int i = 3; i > front; i--)
		{
			ans = max (ans, dp[n][i][2]);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

