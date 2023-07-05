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

using namespace std;

const int maxn = 1005;

int n, m;
int v[maxn], w[maxn];
int dp[maxn];

int main ()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = w[i]; j <= m; j++)
		{
			dp[j] = max (dp[j], dp[j - w[i]] + v[i]);
		}
	}
	
	cout << dp[m] << endl;	
		
	return 0;
}