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
const int maxk = 205;
const int mod = 1e9 + 7;

int n, m, k;
string a, b;

int dp[maxn][maxk];
int sum[maxn][maxk];

int main ()
{
	fastread
	
	cin >> n >> m >> k;
	cin >> a >> b;
	
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = m; j >= 1; j--)
		{
			for (int l = k; l >= 1; l--)
			{
				if (a[i - 1] == b[j - 1])
				{
					sum[j][l] = (sum[j - 1][l] + dp[j - 1][l - 1]) % mod;
				}
				else
				{
					sum[j][l] = 0;
				}
				dp[j][l] = (dp[j][l] + sum[j][l] % mod) % mod;
			}
		}
	}
	
	cout << dp[m][k] % mod << endl;
		
	return 0;
}
