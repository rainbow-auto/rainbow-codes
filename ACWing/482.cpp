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

void solve (int a[], int n, int dp[])
{
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = i; j >= 1; j--)
		{
			if (a[i] > a[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
}

int n;
int a[maxn];
int dp[2][maxn];

int main ()
{
	fastread
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	solve (a, n, dp[0]);
	reverse (a + 1, a + n + 1);
	solve (a, n, dp[1]);
	
	int res = 0;
	for (int i = 1, j = n; i <= n; i++, j--)
	{
		res = max (res, dp[0][i] + dp[1][j] - 1);
	}
	cout << n - res << endl;
	
	return 0;
}