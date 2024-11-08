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
#include <cstdlib>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 1005;

int T;
int n;
char s[maxn][maxn];
int dp[maxn][maxn];

int edit_dis (char a[], char b[])
{
	int lena = strlen (a + 1);
	int lenb = strlen (b + 1);
	
	for (int i = 1; i <= lena; i++)
		for (int j = 1; j <= lenb; j++)
			dp[i][j] = 0x3f3f3f3f;
	
	for (int i = 1; i <= lena; i++) dp[i][0] = i;
	for (int i = 1; i <= lenb; i++) dp[0][i] = i;
	
	for (int i = 1; i <= lena; i++)
	{
		for (int j = 1; j <= lenb; j++)
		{
			dp[i][j] = min (dp[i - 1][j] + 1, dp[i][j - 1] + 1);
			dp[i][j] = min (dp[i][j], dp[i - 1][j - 1] + (a[i] != b[j]));
		}
	}
	
	return dp[lena][lenb];
}

int main ()
{
	fastread
	
	cin >> n >> T;
	for (int i = 1; i <= n; i++)
	{
		cin >> (s[i] + 1);
	}
	
	while (T --)
	{
		char curr[maxn];
		int limit;
		cin >> (curr + 1);
		cin >> limit;
		
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			if (edit_dis (s[i], curr) <= limit)
			{
				res ++;
			}
		}
		cout << res << endl;
	}
		
	return 0;
}