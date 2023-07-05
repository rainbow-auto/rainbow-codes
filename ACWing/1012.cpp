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

const int maxn = 5005;

struct Node {
	int x, y;
	friend bool operator < (Node a, Node b)
	{
		return a.x < b.x;
	}
};

int n;
Node a[maxn];

int dp[maxn];

int main ()
{
	fastread
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	
	sort (a + 1, a + n + 1);
	
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j++)
		{
			if (a[j].y < a[i].y)
			{
				dp[i] = max (dp[i], dp[j] + 1);
			}
		}
		res = max (dp[i], res);
	}
	cout << res << endl;
	
	return 0;
}