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

const int maxn = 105;
int n;
int dp[maxn][maxn];
int a[maxn][maxn];

int main ()
{
	fastread
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 2; i <= n; i++) dp[0][i] = 0x3f3f3f3f;
	for (int i = 2; i <= n; i++) dp[i][0] = 0x3f3f3f3f;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = min (dp[i][j - 1], dp[i - 1][j]) + a[i][j];
		}
	}
	
	cout << dp[n][n] << endl;
	
	return 0;
}