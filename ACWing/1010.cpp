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
int a[maxn];
int dp[maxn];
int q[maxn];
int ans1, ans2;


int main ()
{
	fastread
	
	while (cin >> a[++n]);
	n --;
	
	ans1 = 1;	
	dp[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		if (dp[ans1] >= a[i]) dp[++ans1] = a[i];
		else *upper_bound (dp + 1, dp + ans1 + 1, a[i], greater<int>()) = a[i];
	}
	
	ans2 = 1;
	q[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		if (q[ans2] < a[i]) q[++ans2] = a[i];
		else *lower_bound (q + 1, q + ans2 + 1, a[i]) = a[i];
	}
	
	cout << ans1 << endl;
	cout << ans2 << endl;
	
	return 0;
}