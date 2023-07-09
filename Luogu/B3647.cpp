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

const int maxn = 1005;

int n, m;
int dis[maxn][maxn];

inline void floyd ()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

int main ()
{
	fastread
	
	cin >> n >> m;
	
	memset (dis, 0x3f, sizeof (dis));
	
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = w;
		dis[v][u] = w;
	}
	
	floyd ();
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
