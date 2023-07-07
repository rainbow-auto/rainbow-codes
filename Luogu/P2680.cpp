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

const int maxn = 600005;

struct Graph {
	struct Edge {
		int from, to, pre;
		int w;
	};
	Edge e[maxn];
	int last[maxn], cnt;
	
	inline void addEdge (int u, int v, int w)
	{
		cnt ++;
		e[cnt].from = u;
		e[cnt].to = v;
		e[cnt].w = w; 
		e[cnt].pre = last[u];
		last[u] = cnt;
	}	
	
	inline int from (int i) { return e[i].from; }
	inline int to (int i) { return e[i].to; }
	inline int pre (int i) { return e[i].pre; }
	inline int w (int i) { return e[i].w; }
};

Graph g;

struct Plan{
	int a, b;
	int len;
	int lca;
}p[maxn];

int n, m;

namespace LCA {
	
	int siz[maxn], dep[maxn], son[maxn], fa[maxn];
	void tree_build (int now)
	{
		siz[now] = 1;
		int siz_k = -1, siz_max = 0;
		for (int i = g.last[now]; i; i = g.pre(i))
		{
			int t = g.to(i);
			
			if (siz[t]) continue;			
									
			fa[t] = now;
			dep[t] = dep[now] + 1;
			tree_build (t);
			siz[now] += siz[t];
			
			if (siz_max < siz[t])
			{
				siz_max = siz[t];
				siz_k = t;
			}
		}	
		son[now] = siz_k;
	}
	
	int top[maxn];
	void tree_pos (int now, int topnow)
	{
		top[now] = topnow;
		if (son[now] == -1) return;
		
		tree_pos (son[now], topnow);
		for (int i = g.last[now]; i; i = g.pre(i))
		{
			int t = g.to(i);
			if (t == fa[now] or t == son[now]) continue;
			tree_pos (t, t);
		}
	}

	inline void lca_init ()
	{
		tree_build (1);
		tree_pos (1, 1);
	}

	int lca (int a, int b)
	{
		while (top[a] != top[b])
		{
			if (dep[top[a]] > dep[top[b]])
			{
				a = fa[top[a]];
			}
			else
			{
				b = fa[top[b]];
			}
		}
		return dep[a] < dep[b] ? a : b;
	}
}

int c[maxn];
int val[maxn];

int tot[maxn];
int dis[maxn];
bool vis[maxn];

void _dfs (int now)
{
	tot[now] = c[now];
	for (int i = g.last[now]; i ; i = g.pre(i))
	{
		int t = g.to(i);
		if (vis[t]) continue;
		vis[t] = true;
		
		dis[t] = dis[now] + g.w(i); 
		val[t] = g.w(i);
		_dfs (t);
		tot[now] += tot[t];
	}
}

void dfs (int start)
{
	memset (tot, 0, sizeof (tot));
	memset (vis, 0, sizeof (vis));
	memset (dis, 0, sizeof (dis));
	vis[1] = true;
	_dfs (start); 
}

bool check (int x)
{
	int num = 0;
	int max_len = 0;
	memset (c, 0, sizeof (c));
	
	for (int i = 1; i <= m; i++)
	{
		if (p[i].len > x) 
		{
//			cout << "len > x : i = " << i << endl;
			c[p[i].a] ++;
			c[p[i].b] ++;
			c[p[i].lca] -= 2;	
			++num;
		}
		max_len = max (max_len, p[i].len);
	}
	
//	cout << "c: ";
//	for (int i = 1; i <= n; i++) cout << c[i] << " ";
//	cout << endl;
	
	dfs (1);
	for (int i = 1; i <= n; i++)
	{
//		cout << "i = " << i << " tot = " << tot[i] << endl;
		if (tot[i] == num and val[i] >= max_len - x)
		{
			return true;
		}
	}	
	return false;
}

int main ()
{
	fastread
	
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v, t;
		cin >> u >> v >> t;
		g.addEdge(u, v, t);
		g.addEdge(v, u, t);
	}
	
	dfs (1);
	LCA::lca_init (); 
	
//	for (int i = 1; i <= n; i++)
//	{
//		cout << dis[i] << " "; 
//	}
//	cout << endl;
	
	int max_len = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i].a >> p[i].b;
		p[i].lca = LCA::lca (p[i].a, p[i].b);
		p[i].len = dis[p[i].a] + dis[p[i].b] - 2 * dis[p[i].lca];
		max_len = max (max_len, p[i].len);
//		cout << "dis[a] = " << dis[p[i].a] << " dis[b] = " << dis[p[i].b] << " ";
//		cout << "len = " << p[i].len << endl;
	}
	
	int l = 0, r = max_len;
	int ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
//		cout << "l = " << l << " r = " << r << " mid = " << mid << endl;
		if (check (mid))
		{
			r = mid - 1;	
			ans = mid;
		}			
		else
		{
			l = mid + 1;
		}
	}	
	
	cout << ans << endl;
	
	return 0;
}
