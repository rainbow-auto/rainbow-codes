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

const int maxn = 80005;
const int maxm = 400005;

struct Graph{
	int from[maxm], to[maxm], pre[maxm], last[maxn];
	int cnt;
	
	int w[maxm], p[maxm]; // 计算好p 
	inline void addEdge (int u, int v, int wnow, int pnow)
	{
		++ cnt;
		from[cnt] = u;
		to[cnt] = v;	
		
		w[cnt] = wnow;
		p[cnt] = pnow;
			
		pre[cnt] = last[u];
		last[u] = cnt;
	}	
	
	inline int count (int w, long double p)
	{
		int res = 0;
		while (w)
		{
			res += w;
			w *= p;			
		}
		return res;
	}
};

Graph G, NewG;

int n, m;
int s;

int belong[maxn], bcnt;
int nw[maxn]; // node_weight

namespace Tarjan{
	int dfn[maxn], low[maxn], dpos;
	int stk[maxn], spos;
	bool vis[maxn];
	
	void tarjan (int now)
	{
		low[now] = dfn[now] = ++dpos;
		stk[++spos] = now;
		
		for (int i = G.last[now]; i; i = G.pre[i])
		{
			int t = G.to[i];
			if (vis[t])
			{
				continue;
			}
			if (dfn[t])
			{
				low[now] = min (low[now], dfn[t]);
			} 
			else
			{
				tarjan (t);
				low[now] = min (low[now], low[t]);
			}
		}
		
		if (low[now] == dfn[now])
		{
			bcnt ++;
			while (true)
			{
				int top = stk[spos --];
			
				belong[top] = bcnt;
				vis[top] = true;
				
				if (top == now)
				{
					break;
				}
			}
		}		
	}
	
	void uni (int s)
	{
		tarjan (s);
		
		for (int i = 1; i <= G.cnt; i++)
		{
			int u = belong[G.from[i]], v = belong[G.to[i]];
			
			if (u == v)
			{
				nw[u] += G.p[i];
			}
			else
			{
				NewG.addEdge(u, v, G.w[i], 0); // 只有边权 
			}	
		}		
	}
}

int dp[maxn];
void dfs (int now)
{
	if (dp[now])
	{
		return;
	}
	
	int resnow = 0;
	for (int i = NewG.last[now]; i; i = NewG.pre[i])
	{
		int t = NewG.to[i];
		dfs (t);
		resnow = max (resnow, dp[t] + NewG.w[i]);		
	}
	dp[now] = resnow + nw[now];
} 

namespace Solution{
	int solve(int s)
	{
		Tarjan::uni (s);
		s = belong[s];
		dfs (s);
		return dp[s];
	}
}

int main ()
{
	fastread
	
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++)
	{
		int u, v, wnow;
		long double pnow;
		cin >> u >> v >> wnow >> pnow;
		
		G.addEdge(u, v, wnow, G.count(wnow, pnow));
	}
	
	cin >> s;
	
	cout << Solution::solve (s) << endl;
	
	return 0;
}
