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

const int maxn = 405;

int n;

int w[maxn];

int to[maxn], pre[maxn], last[maxn];
int cnt;

inline void addEdge (int u, int v)
{
	cnt ++;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt;
}

bool vis[maxn];
int path[maxn][maxn];
int curr;

int solve (int now)
{
	if (vis[now]) return 0;
	
	int res = w[now];
	int p = 0;
	for (int i = last[now]; i; i = pre[i])
	{
		int t = to[i];
		if (res < w[now] + solve (t))
		{
			res = w[now] + solve (t);
			p = t;
		}
	}

	path[curr][now] = p;
	
	return res;
}

void print_path (int now, int c)
{
	if (path[c][now] == 0) return;
	
	cout << path[c][now] << " ";
	print_path (path[c][now], c);
}

int main ()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];		
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int flag;
			cin >> flag;
			if (flag) addEdge (i, j);
		}
	}
	
	int ansp = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		memset (vis, 0, sizeof (vis));
		
		curr = i;
		int res = solve (i);
		
		if (ans < res)
		{
			ans = res;
			ansp = i;
		}
	}
	
	cout << ansp << " ";
	print_path (ansp, ansp);
	cout << endl;
	
	cout << ans << endl;
	
	return 0;
}