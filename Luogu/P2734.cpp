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
int a[maxn];
int sum[maxn];

int dp[maxn][maxn];

int main ()
{
	fastread
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = a[i];
	}
	
	for (int len = 2; len <= n; len ++)
	{
		for (int l = 1; l + len - 1 <= n; l ++)
		{
			int r = l + len - 1;
			
			dp[l][r] = (sum[r] - sum[l - 1]) - min (dp[l + 1][r], dp[l][r - 1]);			
		}
	}
	
	cout << dp[1][n] << " " << sum[n] - dp[1][n] << endl;	
	
	return 0;
}