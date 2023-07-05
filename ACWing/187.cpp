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

const int maxn = 55;
int n;
int a[maxn];

int up[maxn], down[maxn];
int ans;

void dfs (int u, int d, int curr)
{
	if (u + d >= ans) return; // 这次搜索的最终ans一定会超过原来的最小ans
	if (curr > n)
	{
		if (u + d < ans) ans = u + d;
		return;
	}

	int mem;
	int i;	
	
	for (i = 1; i <= u; i++)
		if (a[curr] > up[i])
			break;
	mem = up[i];
	up[i] = a[curr];
	dfs (max (u, i), d, curr + 1);
	up[i] = mem;

	for (i = 1; i <= d; i++)
		if (a[curr] < down[i])
			break;
	
	mem = down[i];
	down[i] = a[curr];
	dfs (u, max (d, i), curr + 1);
	down[i] = mem;

}

int main ()
{

	while (true)
	{
		cin >> n;
		if (not n) break;

		for (int i = 1; i <= n; i++) cin >> a[i];
		
		ans = 100;
		dfs (0, 0, 1);

		cout << ans << endl;
	}

	return 0;
}