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

int dp[maxn];
int solve (int n, int a[])
{
	memset (dp, 0, sizeof (dp));
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			if (a[i] < a[j])
			{
				dp[i] = max (dp[i], dp[j] + 1);
			}
		}
	}
	
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max (res, dp[i]);
	}
	return res;
}

int main ()
{
	fastread
	
	cin >> T;
	while (T--)
	{
		int a[maxn];
		int n;
		
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		
		int res = solve (n, a);
		reverse(a + 1, a + n + 1);
		res = max (res, solve (n, a));
		
		cout << res << endl;
	}
		
	return 0;
}