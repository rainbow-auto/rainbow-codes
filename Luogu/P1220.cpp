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

int n, c;
int s[maxn];
int dp[maxn][maxn][2];

int p[maxn];
int v[maxn];
int ans;

inline int sum (int l, int r)
{
	return s[r] - s[l - 1];
}

int main ()
{
	fastread
	
	cin >> n >> c;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i] >> v[i];
		s[i] = s[i - 1] + v[i];
	}
	memset (dp, 0x3f, sizeof (dp));
	
	dp[c][c][0] = dp[c][c][1] = 0;
	
	for (int len = 2; len <= n; len ++)
	{
		for (int l = 1; l + len - 1 <= n; l++)
		{
			int r = l + len - 1;
		
			dp[l][r][0] = min (dp[l + 1][r][0] + (p[l + 1] - p[l]) * (s[n] - sum(l + 1, r)) , 
			                   dp[l + 1][r][1] + (p[r] - p[l]) * (s[n] - sum(l + 1, r)));			
			dp[l][r][1] = min (dp[l][r - 1][0] + (p[r] - p[l]) * (s[n] - sum(l, r - 1)) , 
							   dp[l][r - 1][1] + (p[r] - p[r - 1]) * (s[n] - sum(l, r - 1)));
							   
		}
	}	

	cout << min (dp[1][n][0], dp[1][n][1]) << endl;
	
	return 0;
}