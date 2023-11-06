#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxn = 100005;
int dp[maxn][2];

int p[maxn];

int k;
int n;
int a, b, k;

int main ()
{
	cin >> n >> a >> b >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] + a * 
	}
	return 0;
}

