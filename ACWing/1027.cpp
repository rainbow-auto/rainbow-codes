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

const int maxn = 15;
int n;
int a[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];

int main ()
{
	cin >> n;
	while (true)
	{
		int x, y, val;
		cin >> x >> y >> val;
		if (x == 0 and y == 0 and val == 0) break;
		a[x][y] = val;		
	}
	
	for (int x1 = 1; x1 <= n; x1++)
	{
		for (int y1 = 1; y1 <= n; y1++)
		{
			for (int x2 = 1; x2 <= n; x2++)
			{
				for (int y2 = 1; y2 <= n; y2++)
				{
					int w = a[x1][y1];
					if (y1 != y2 and x1 != x2) w += a[x2][y2];
					
					dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[x1 - 1][y1][x2 - 1][y2]);
					dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[x1][y1 - 1][x2 - 1][y2]);
					dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[x1 - 1][y1][x2][y2 - 1]);
					dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[x1][y1 - 1][x2][y2 - 1]);
					dp[x1][y1][x2][y2] += w;
				}
			}
		}
	}
	cout << dp[n][n][n][n] << endl;
	
	return 0;
}