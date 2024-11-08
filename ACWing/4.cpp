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

const int maxn = 205;
int n, m;

int w[maxn], v[maxn];
int dp[maxn];
int cnt;

int main ()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int a, b, s;
		
		cin >> a >> b >> s;
		
		int k = 1;
		while (k <= s)
		{
			cnt ++;
			v[cnt] = k * a;
			w[cnt] = k * b;	
			s -= k;
			k *= 2;
		}
		if (s > 0)
		{
			cnt++;
			v[cnt] = s * a;
			w[cnt] = s * b;
		}
	}	
	
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = m; j >= v[i]; j--)
		{
			dp[j] = max (dp[j], dp[j - v[i]] + w[i]);
		}
	}
	
	cout << dp[m] << endl;
	
	return 0;
}
