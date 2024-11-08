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

const int maxn = 105;
int dp[maxn];
int n;

int main ()
{
//	freopen ("stack.in", "r", stdin);
//	freopen ("stack.out", "w", stdout);
	
//	cin >> n;
	n = 18;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << endl;
	}
	
//	cout << dp[n] << endl;
	
//	fclose (stdin);
//	fclose (stdout);
	return 0;
}

