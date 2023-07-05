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

const int maxn = 205;

int n;
int a[maxn];
int s[maxn];
int dp_max[maxn][maxn];
int dp_min[maxn][maxn];

int main ()
{
	fastread
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char ch;
		cin >> ch;
		cin >> a[i];
		
		if (ch == 't') s[i] = 1;
		else s[i] = 2;
	}	
	
	for (int i = 1; i <= n; i++)
	{
		a[n + i] = a[i];
		s[n + i] = s[i];
	}
	
	fill (dp_min[0], dp_min[0] + maxn * maxn, 0x3f3f3f3f);
	fill (dp_max[0], dp_max[0] + maxn * maxn, -0x3f3f3f3f);

	for (int i = 1; i <= n * 2; i++)
	{
		dp_max[i][i] = a[i];
		dp_min[i][i] = a[i];
	}
	
	for (int len = 2; len <= n; len ++)
	{
		for (int l = 1; l + len - 1 <= n * 2; l ++)
		{
			int r = l + len - 1;
			for (int i = l; i < r; i++)
			{
//					int uni = (s[i + 1] == 1) ? dp_max[l][i] + dp_max[i][r] : dp_max[l][i] * dp_max[i][r];
				if (s[i + 1] == 1) // +
				{
					dp_max[l][r] = max (dp_max[l][r], dp_max[l][i] + dp_max[i + 1][r]);
					dp_min[l][r] = min (dp_min[l][r], dp_min[l][i] + dp_min[i + 1][r]);
				}
				else if (s[i + 1] == 2) // * 
				{
					dp_max[l][r] = max ({dp_max[l][r], dp_max[l][i] * dp_max[i + 1][r], dp_min[l][i] * dp_min[i + 1][r], dp_min[l][i] * dp_max[i + 1][r], dp_max[l][i] * dp_min[i + 1][r]});
					dp_min[l][r] = min ({dp_min[l][r], dp_max[l][i] * dp_max[i + 1][r], dp_min[l][i] * dp_min[i + 1][r], dp_min[l][i] * dp_max[i + 1][r], dp_max[l][i] * dp_min[i + 1][r]});
				}
			}
		}
	}	

	int ans = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		ans = max (ans, dp_max[i][i + n - 1]);
	}
	
	cout << ans << endl;
	
	for (int i = 1; i <= n; i++)
	{
		if (dp_max[i][i + n - 1] == ans) cout << i << " "; 
	}
	cout << endl;
	
	return 0;
}