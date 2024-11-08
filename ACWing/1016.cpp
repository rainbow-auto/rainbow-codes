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
int n;
int a[maxn];
int dp[maxn];

int main ()
{
	fastread
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = a[i];
		for (int j = i - 1; j >= 1; j --)
		{
			if (a[i] > a[j])
			{
				dp[i] = max (dp[i], dp[j] + a[i]);
			}	
		}
		res = max (res, dp[i]);	
	}	
	cout << res << endl;
	
	return 0;
}