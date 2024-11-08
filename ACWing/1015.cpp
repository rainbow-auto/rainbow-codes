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

int T;
int r, c;

int a[maxn][maxn];
int dp[maxn][maxn];

int main ()
{
	fastread
	cin >> T;
	
	while (T--)
	{
		cin >> r >> c;
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				cin >> a[i][j];
			}
		}
		
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				dp[i][j] = max (dp[i][j - 1], dp[i - 1][j]) + a[i][j];
			}
		}
		cout << dp[r][c] << endl;
	}
		
	return 0;
}