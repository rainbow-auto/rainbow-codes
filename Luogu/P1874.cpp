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

const int maxn = 100005;

int n;
long long dp[45][maxn];
int a[maxn];
long long t;

long long get_num (int l, int r)
{
	long long res = 0;
	
	for (int i = l; i <= r; i++)
	{
		res = res * 10 + a[i];
	}
	
	if (res > t) return 0x3f3f3f3f;
	else return res;
}

int main ()
{
	fastread
	
	string s;
	cin >> s;
	
	cin >> t;
	
	n = s.length();
	
	for (int i = 1; i <= n; i++)
	{	
		a[i] = s[i - 1] - '0';
	}
	
	memset (dp, 0x3f, sizeof(dp));
	dp[0][0] = -1;	
		
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= t; j++)
		{
			for (int k = i - 1; k >= 0 and get_num (k + 1, i) <= t; k--)
			{
				if (j >= get_num (k + 1, i))
				{
					dp[i][j] = min (dp[i][j], dp[k][j - get_num(k + 1, i)] + 1);
				}
			}
		}
	}
	
	if (dp[n][t] < maxn)
	{
		cout << dp[n][t] << endl;
	}
	else
	{
		cout << -1 << endl;
	}
		
	return 0;
}
