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
        
        friend bool operator < (Edge a, Edge b)
        {
        	return a.w > b.w;
		}
    }e[maxn];
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

    inline int from (int i)
    {
        return e[i].from;
    }
    inline int to (int i)
    {
        return e[i].to;
    }
    inline int pre (int i)
    {
        return e[i].pre;
    }
    inline int w (int i)
    {
    	return e[i].w;
	}
    
    inline void sort_edge ()
    {
    	sort (e + 1, e + cnt + 1); 
	}
};

Graph g, ng;

int n, m, q;

namespace LCA {
	int siz[maxn], son[maxn], fa[maxn], dep[maxn];
	void tree_build (int now)
	{
		if (siz[now]) return;
		siz[now] = 1;
		
		int siz_k = -1, siz_t = 0;		
		for (int i = ng.last[now]; i; i = ng.pre(i))
		{
			int t = ng.to(i);
			if (siz[t]) continue;
			
			fa[t] = now;
			dep[t] = dep[now] + 1;
			tree_build (t);
			siz[now] += siz[t];
			
			if (siz_t < siz[t])
			{
				siz_t = siz[t];
				siz_k = t;
			}			
		}
		son[now] = siz_k;
	}
	
	int top[maxn], dfn[maxn], dpos;
	void tree_pos (int now, int topnow)
	{
		dfn[now] = ++dpos;
		top[now] = topnow;
		
		if (son[now] == -1) return;
		tree_pos (son[now], topnow);
		
		for (int i = ng.last[now]; i; i = ng.pre(i))
		{
			int t = ng.to(i);
			if (t == fa[now] or t == son[now]) continue;
			tree_pos (t, t);
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

namespace exKruskal {
	int fa[maxn];
	int find (int x)	
	{
		if (fa[x] != x) return fa[x] = find (fa[x]);
		return fa[x];
	}
	
	int val[maxn];
	void exKruskal ()
	{
		int tot = n;
		for (int i = 1; i <= n; i++)
		{
			fa[i] = i;
		}
		
		g.sort_edge ();
		for (int i = 1; i <= g.cnt; i++)
		{
			int u = find (g.from(i));
			int v = find (g.to(i));
			if (u == v) continue;
				
			val[++tot] = g.w(i);
			fa[u] = fa[v] = fa[tot] = tot;
				
			ng.addEdge(u, tot, 0);
			ng.addEdge(v, tot, 0);			
			ng.addEdge(tot, u, 0);
			ng.addEdge(tot, v, 0);
		}
		
		for (int i = 1; i <= tot; i++)
		{
			if (LCA::siz[i]) continue;
			int curr = find (i); // ¶¥²ã 
			LCA::tree_build (curr); 
			LCA::tree_pos (curr, curr);
		}		
	}
}

int main ()
{
	fastread
	
	cin >> n >> m >> q;
	
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}
	
	exKruskal::exKruskal ();
	
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		if (exKruskal::find(x) != exKruskal::find(y)) cout << -1 << endl;
		else cout << exKruskal::val[LCA::lca(x, y)] << endl;
	}
		
	return 0;
}
