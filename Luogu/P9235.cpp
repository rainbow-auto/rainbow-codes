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
 
int n, m;

struct Edge{
	int from, to, pre;
	int w; 
	
	friend bool operator < (Edge a, Edge b)
	{
		return a.w > b.w;
	}
}g[maxn], ng[maxn];
int last[maxn], ng_last[maxn], cnt, ng_cnt;
int val[maxn], tot; // exKruskal 新增的点 

inline void addEdge (Edge g[], int last[], int& cnt, int u, int v, int w)
{
	cnt ++;
	g[cnt].from = u;
	g[cnt].to = v;
	g[cnt].w = w;
	g[cnt].pre = last[u];
	last[u] = cnt;
}

namespace LCA{
	int fa[maxn], son[maxn], siz[maxn], dep[maxn];
	void tree_build (int now)
	{
		siz[now] = 1;
		int siz_max = 0, siz_k = -1;
		for (int i = ng_last[now]; i; i = ng[i].pre)
		{
			int t = ng[i].to;
			if (t == fa[now]) continue;			
			
			dep[t] = dep[now] + 1;
			fa[t] = now;
			tree_build (t);
			siz[now] += siz[t];
			if (siz[t] > siz_max)
			{
				siz_max = siz[t];
				siz_k = t;
			}
		}
		son[now] = siz_k;
	}
	
	int top[maxn], rnk[maxn], dfn[maxn], dpos;
	void tree_pos (int now, int topnow)
	{
		top[now] = topnow;
		dfn[now] = ++dpos; 
		rnk[dpos] = now; 
		if (son[now] == -1) return;
		
		tree_pos (son[now], topnow);
		for (int i = ng_last[now]; i ; i = ng[i].pre)
		{
			int t = ng[i].to;
			if (t == fa[now]) continue;
			if (t == son[now]) continue;
			tree_pos(t, t);
		}
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

int fa[maxn];
int find (int x)
{
	if (fa[x] != x)
	{
		return fa[x] = find (fa[x]);
	}
	return fa[x];
}


void exKruskal()
{
	sort (g + 1, g + m + 1);
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	
	tot = n;
	for (int i = 1; i <= m; i++)
	{
		int u = find (g[i].from);
		int v = find (g[i].to);	
		
		if (u == v) continue;
		
		val[++tot] = g[i].w;
		fa[u] = fa[v] = fa[tot] = tot;
		
		addEdge (ng, ng_last, ng_cnt, u, tot, 0); // 不需要边权
		addEdge (ng, ng_last, ng_cnt, v, tot, 0);
		addEdge (ng, ng_last, ng_cnt, tot, u, 0);
		addEdge (ng, ng_last, ng_cnt, tot, v, 0); 
	}
	
	for (int i = 1; i <= tot; i++)
	{
		if (LCA::siz[i]) continue;
		int curr = find (i);
		LCA::tree_build(curr); LCA::tree_pos(curr, curr);
	}
}

int main ()
{
	int q;
	cin >> n >> m >> q;
	
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		addEdge (g, last, cnt, u, v, w);
	}
	exKruskal ();
	
//	for (int i = 1; i <= ng_cnt; i++)
//	{
//		cout << "from " << ng[i].from << " to " << ng[i].to << " w: " << ng[i].w << endl;
//	}
//	
//	cout << "val: ";
//	for (int i = 1; i <= tot; i++)
//	{
//		cout << val[i] << " ";
//	}
//	cout << endl;
	
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		
		if (find(x) != find(y))
		{
			cout << -1 << endl; 
		}
		else
		{
//			cout << LCA::lca(x, y) << endl;
			cout << val[LCA::lca(x, y)] << endl;
		}
	}
	
	return 0;
}
