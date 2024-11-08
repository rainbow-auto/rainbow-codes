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

const int maxn = 305;
int n;
int a[maxn][maxn];
int s[maxn][maxn];

int sum (int x1, int y1, int x2, int y2)
{
	return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
}

int main ()
{
	fastread
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j]; 
		}
	}
 
 	int res = -0x3f3f3f3f;
 
	for (int x1 = 1; x1 <= n; x1++)
	for (int y1 = 1; y1 <= n; y1++)
	for (int x2 = x1; x2 <= n; x2++)
	for (int y2 = y1; y2 <= n; y2++)
	{
		res = max (res, sum(x1, y1, x2, y2));
	}
	
	cout << res << endl;
	
	return 0;
}
