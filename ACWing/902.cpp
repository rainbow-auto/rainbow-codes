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

const int maxn = 1005;

int n, m;
char a[maxn], b[maxn];
int dp[maxn][maxn];

int main ()
{
	fastread
	
	cin >> n;
	cin >> a + 1;
	cin >> m;
	cin >> b + 1;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = 0x3f3f3f3f;
		}
	}
	
	for (int i = 1; i <= n; i++) dp[i][0] = i;
	for (int i = 1; i <= m; i++) dp[0][i] = i;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = min (dp[i - 1][j], dp[i][j - 1]) + 1;
			if (a[i] == b[j]) dp[i][j] = min (dp[i][j], dp[i - 1][j - 1]);
			else dp[i][j] = min (dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}
	
	cout << dp[n][m] << endl;	
				
	return 0;
}