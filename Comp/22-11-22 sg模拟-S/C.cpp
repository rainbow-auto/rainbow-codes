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

const int maxn = 200005;
const int maxk = 105;

int n, m, k;

namespace Original_Graph{
	int to[maxn], pre[maxn], last[maxn];
	int cnt;
	inline void addEdge (int u, int v)
	{
		cnt ++;
		to[cnt] = v;
		pre[cnt] = last[u];
		last[u] = cnt;
	}
}
	
namespace Graph{
	int to[maxn * maxk], pre[maxn * maxk], last[maxn];
	int cnt;
	inline void addEdge (int u, int v)
	{
		cnt++;
		to[cnt] = v;
		pre[cnt] = last[u];
		last[u] = cnt;
	}
}

namespace Sub1{
	
	bool vis[maxn];
	int root;
	void dfs (int now, int know)
	{
		if (know == 0)
		{
			return;
		}
		if (now != root)
		{
			Graph::addEdge (root, now);
		}
		vis[now] = true;
		for (int i = Original_Graphlast[now]; i; i = Original_Graph::pre[i])
		{
			int t = Original_Graph::to[i];
			if (vis[t]) continue;
			dfs (t, know - 1);
		}
	}
	
	inline void build ()
	{
		for (int i = 1; i <= n; i++)
		{
			memset (vis, 0, sizeof (vis));
			root = i;
			dfs (i, k);
		}	
	}
	
	void solve ()
	{
		build ();
		
	}
}

int main ()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
	}
	
	return 0;
}

