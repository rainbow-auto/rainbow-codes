#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 2e5 + 5;

int n, l, r;
int a[maxn];

int dp[maxn];

int main ()
{
	cin >> n >> l >> r;
	
	for (int i = 0; i <= n; i++)
	{
		cin >> a[i];
	}
	
	int ans = -0x3f3f3f3f;
	fill (dp, dp + maxn, -0x3f3f3f3f);
	
	dp[0] = 0;	
		
	deque<int> q;
	q.push_back(0);
			
	for (int i = l; i <= n; i++)
	{
//		for (int j = i - r ; j <= i - l; j++)
//		{
//			dp[i] = max (dp[i], dp[j] + a[i]);	
//		}	
		
		while (not q.empty() and dp[q.back()] <= dp[i - l]) q.pop_back();
		q.push_back(i - l);
		while (q.front() < i - r) q.pop_front();		
		
		dp[i] = dp[q.front()] + a[i];
	}
	
	for (int i = n - r + 1; i <= n; i++)
	{
		ans = max (ans, dp[i]);
	}
	
	cout << ans << endl;
		
	return 0;
}

