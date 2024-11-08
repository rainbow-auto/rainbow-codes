#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 500010;
int n, m;

struct Edge{
	int u, v;
	long long w;
	friend bool operator < (Edge a, Edge b)
	{
		return a.w < b.w;
	}
}; 
Edge es[maxn];

int fa[maxn];
int find (int now)
{
	if (now != fa[now])
	{
		return fa[now] = find (fa[now]);
	}
	return fa[now];
}

inline void init ()
{
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}	
} 

long long kruskal (int s)
{
	sort (es + 1, es + m + 1);
	int tot = 0;
	long long res = 0;
	for (int i = 1; i <= m; i++)
	{
		if (es[i].u == s or es[i].v == s) continue;
		int root_u = find (es[i].u);
		int root_v = find (es[i].v);
		if (root_u != root_v)
		{
			tot ++;
			res += es[i].w;
			fa[root_u] = root_v;
		} 
		if (tot == n - 2)
		{
			return res;
		}
	}
	return -1ll;
}

int main ()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> es[i].u >> es[i].v >> es[i].w;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		init ();
		ans += kruskal (i);
	}
	
	cout << ans << endl;
	
	return 0;
}

