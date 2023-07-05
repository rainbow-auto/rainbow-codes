#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxn = 100005;

int n, m;

struct Edge{
	int u, v;
	int w;
	friend bool operator < (Edge a, Edge b)
	{
		return a.w < b.w;
	}
};
Edge es[maxn];

int fa[maxn];
inline void init ()
{
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
}

int find (int x)
{
	if (fa[x] != x)
	{
		return fa[x] = find (fa[x]);
	}
	return fa[x];
}

int main ()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, t;
		cin >> u >> v >> t;
		es[i] = Edge {u, v, t};
	}
	sort (es + 1, es + m + 1);
	
	init ();
	
	int tot = 0;
	for (int i = 1; i <= m; i++)
	{
		int u_root = find (es[i].u);
		int v_root = find (es[i].v);
		if (u_root != v_root)
		{
			tot ++;
			fa[v_root] = u_root;
		}
		if (tot == n - 1)
		{
			cout << es[i].w << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	return 0;
}