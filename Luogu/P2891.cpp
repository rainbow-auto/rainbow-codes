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

const int maxn = 505;
const int maxm = 2000005;

int n, f, d;

struct Edge{
	int u, v, pre;
	int flow;
};

Edge es[maxm];
int last[maxn], cnt;

inline void _addEdge (int u, int v, int cap)
{
	cnt ++;
	es[cnt].u = u;
	es[cnt].v = v;
	es[cnt].flow = cap;
	es[cnt].pre = last[u];
	last[u] = cnt;
}

inline void addEdge (int u, int v, int cap)
{
	_addEdge (u, v, cap);
	_addEdge (v, u, 0);
}

int S, T;
int dis[maxm];

bool bfs ()
{
	memset (dis, 0x3f, sizeof (dis));
	dis[S] = 0; queue<int> q; q.push(S);
	
	while (not q.empty ())
	{
		int now = q.front(); q.pop();
		for (int i = last[now]; i; i = es[i].pre)
		{
			int t = es[i].v;
		
			if (dis[t] == 0x3f3f3f3f and es[i].flow != 0) // 没有被访问且还有剩流 
			{
				dis[t] = dis[now] + 1;
				q.push(t);				
			}			
		}
	}
	
	return dis[T] != 0x3f3f3f3f;
}

int cur[maxn]; // 替代last, 当前弧优化 

int dfs (int now, int flow_now) // flow_now: 到达当前点的流量 
{
	if (flow_now == 0 or now == T) return flow_now; // 没有流量了 or 到了 都直接返回 
	
	int res = 0; // 当前点能增广到t的总流量
	
	for (int &i = cur[now]; i; i = es[i].pre) // &i 当前弧优化 
	{
		int t = es[i].v;
		
		if (es[i].flow == 0 or dis[t] != dis[now] + 1) continue; // 没有流量了 or t的不是now的下一层
		
		int flow_t = dfs (t, min(es[i].flow, flow_now)); // 当前流向t的流量由 流向当前点的流量 和 now到t的边的容量 决定
		if (flow_t) // 能流到t
		{
			es[i].flow -= flow_t;     // now与t的边的容量被消耗了flow_t
			es[i ^ 1].flow += flow_t; // 相应的反悔边也要加上flow_t
			res += flow_t;
			flow_now -= flow_t;
			if (flow_now == 0) return res; // 没有容量了直接返回 
		}
	} 
	
	return res; 
}

int dinic ()
{
	int res = 0;
		
	while (bfs ())
	{
		memcpy(cur, last, sizeof (cur));
		res += dfs (S, 0x3f3f3f3f); // 源点拥有无限的流量
//		cout << "res += " << dfs (S, 0x3f3f3f3f) << endl;
	}
	
	return res;
} 

int main ()
{
	fastread
	
	cin >> n >> f >> d;
	
	cnt = 1; 
	S = 0;
	T = 2 * n + f + d + 1; // 奶牛两层 食物一层 饮料一层
	
	// 构图方式: S -> 食物 -> 奶牛入   -> 奶牛出      ->        饮料             -> T  
	//           0    1 ~ f  f+1 ~ f+n  f+n+1 ~ f+2*n   n + f + 1 ~ n + f + d   2 * n + f + d   
	for (int i = 1; i <= f; i++)
	{
		addEdge (S, i, 1); 	// S -> 食物 
	}	
	
	for (int i = 1; i <= n; i++)  
	{
		addEdge (f + i, f + n + i, 1); // 奶牛入 -> 奶牛出	
	} 
	
	for (int i = 1; i <= d; i++)
	{
		addEdge (f + n * 2 + i, T, 1); // 饮料 -> T 		
	}
	
	for (int i = 1; i <= n; i++)
	{
		int x; 
		int fn, dn;
		
		cin >> fn >> dn;
		
		for (int j = 1; j <= fn; j++)
		{
			cin >> x;
			addEdge (x, f + i, 1);
		}	
		
		for (int j = 1; j <= dn; j++)
		{
			cin >> x;
			addEdge (f + n + i, x + f + n * 2, 1); 
		}
	}	
	
	cout << dinic () << endl;
			
	return 0;
}
