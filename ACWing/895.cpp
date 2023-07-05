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

using namespace std;
const int maxn = 1005;

int n;
int a[maxn];
int dp[maxn];

int main ()
{
	fastread
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j --)
		{
			if (a[i] > a[j])
			{
				dp[i] = max (dp[i], dp[j] + 1);
			}
		}
	}
	
	int ans = 0;	
	for (int i = 1; i <= n; i ++)
	{
		ans = max (ans, dp[i]);
	}	
	
	cout << ans << endl;
	return 0;
}