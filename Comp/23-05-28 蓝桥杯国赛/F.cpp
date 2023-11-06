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
	
const int maxn = 505;

int n, m;
int t[maxn];
int dp[maxn];

int main ()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
	}
	sort (t + 1, t + n + 1);
	
	dp[1] = 0;
	int tnow = t[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 0x3f3f3f3f;
		for (int j = i - 1; j >= 1; j--)
		{
			dp[i] = min (dp[i], max (t[j] + m - t[i], 0));
		}
		
		if (t[i] == t[i - 1])
		{
			dp[i] = min (dp[i], dp[i - 1]);
		}		
	}
	
	cout << dp[n] << endl;
		
	return 0;
}

