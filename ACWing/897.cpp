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

const int maxn = 1005;
int n, m;

char a[maxn], b[maxn];
int dp[maxn][maxn];

int main ()
{
	fastread
	cin >> n >> m;
	scanf ("%s", a + 1);
	scanf ("%s", b + 1);
	
	memset (dp, 0, sizeof (dp));
		
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}	
	
	cout << dp[n][m] << endl;
		
	return 0;
}