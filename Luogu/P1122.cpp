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

const int maxn = 32005;

int n;

int to[maxn], pre[maxn], last[maxn];
int cnt;

inline void addEdge (int u, int v)
{
	cnt ++;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt; 
}

int dp[maxn];
void solve (int now, int fa)
{
	int tot = 0; 
	for (int i = last[now]; i; i = pre[i])
	{
		int t = to[i];
		
		if (t == fa) continue;
		
		tot ++;
		solve (t, now);
		dp[now] += (dp[t] > 0) ? dp[t] : 0;
	}
}

int main ()
{
	fastread
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i];
	}
	
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		addEdge (u, v);	
		addEdge (v, u);	
	}	
	
	solve (1, -1);
	
	int ans = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		ans = max (ans, dp[i]);
	}
	cout << ans << endl;
	
	return 0;
}
