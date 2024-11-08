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

int n, m, p;

int cost[maxn];
int a[maxn][maxn];
int dp[maxn];

int main ()
{
	fastread
	
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}
	
	for (int i = 1; i <= m; i++)
	{
		dp[i] = -0x3f3f3f3f;	
	}	
	
	for (int i = 1; i <= m; i++) // 枚举时间 
	{
		for (int j = 1; j <= n; j++) // 枚举开始行走的点 
		{
			int ans = dp[i - 1] - cost[j];
			for (int k = 0; k < p and i + k <= m; k++) // 枚举步数 | i + k = 结束的时间 
			{           
				int t = j + k > n ? (j + k) % n : (j + k); // 处理环形 | j + k = 结束的点 
				ans += a[t][i + k];
				dp[i + k] = max (dp[i + k], ans);	
			} 
		}
	}
	
	cout << dp[m] << endl;
	
	return 0;
}
