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

const int maxn = 10005;

int n, m;

int t[maxn];
int x[maxn];
int y[maxn];

int dp[maxn];

int dis (int i, int j)
{
	return abs (x[i] - x[j]) + abs (y[i] - y[j]);
}

int main ()
{
	fastread
	
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++)
	{
		cin >> t[i] >> x[i] >> y[i];
	}

	for (int i = 1; i <= m; i++)
	{
		dp[i] = 1;
	}
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (not (dis (i, j) <= t[i] - t[j])) continue;
			dp[i] = max (dp[i], dp[j] + 1);
		}
	}	
	
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		ans = max (ans, dp[i]);
	}
	cout << ans << endl;
		
	return 0;
}
