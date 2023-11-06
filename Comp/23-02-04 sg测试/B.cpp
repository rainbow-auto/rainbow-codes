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

const int maxn = 1005;
int n, m, q;
int dis[maxn][maxn];

int t[maxn];

inline void init ()
{
	memset (t, 0x3f, sizeof (t));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			dis[i][j] = 0x3f3f3f3f;
		}
	}
}

void update (int x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dis[i][j] = min (dis[i][j], dis[i][x] + dis[x][j]);
		}
	}
}

int main ()
{
	fastread
	cin >> n >> m;
	
	init();	
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i - 1];
	}
	
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = w;
		dis[v][u] = w;
	}
	
	cin >> q;
	
	int tot = 0;
	while (q--)
	{
		int x, y, qt;
		cin >> x >> y >> qt;
		while (t[tot] <= qt)
		{
			update(tot);
			tot ++;
		}
		if (max (x, y) > tot - 1)
		{
			cout << -1 << endl;
		}
		else if (dis[x][y] == 0x3f3f3f3f)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << dis[x][y] << endl;	
		}		
	} 
	
	return 0;
}
