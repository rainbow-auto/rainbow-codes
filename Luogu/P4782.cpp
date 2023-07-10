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

const int maxn = 4000005;

int n, m;

int to[maxn], pre[maxn], last[maxn];
int cnt;

inline void addEdge (int u, int v)
{
	cnt ++;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt;
}

int low[maxn], dfn[maxn], dpos; 
stack<int> stk;
bool ins[maxn];

int scc[maxn], scc_cnt;

void tarjan (int now)
{
	low[now] = dfn[now] = ++dpos;
	stk.push(now);
	ins[now] = true;
	
	for (int i = last[now]; i; i = pre[i])
	{
		int t = to[i];
		if (not dfn[t])
		{
			tarjan (t);
			low[now] = min (low[now], low[t]);
		}
		else if (ins[t])
		{
			low[now] = min (low[now], dfn[t]);
		}
	}
	
	if (low[now] == dfn[now])
	{
		scc_cnt++; 
		do{
			scc[now] = scc_cnt;
			now = stk.top(); stk.pop(); ins[now] = false;	
		} while (low[now] != dfn[now]); 
	}
}

int main ()
{
	fastread
	
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++)
	{
		int a, x;
		int b, y;
		cin >> a >> x >> b >> y;
		
		if (x == 1 and y == 1)
		{
			addEdge (a + n, b);
			addEdge (b + n, a);	
		}	
		if (x == 0 and y == 1)
		{
			addEdge (a, b);
			addEdge (b + n, a + n);
		}
		if (x == 1 and y == 0)
		{
			addEdge (a + n, b + n);
			addEdge (b, a);
		}
		if (x == 0 and y == 0)
		{
			addEdge (a, b + n);
			addEdge (b, a + n);
		}
	}

	for (int i = 1; i <= (n << 1); i++)
	{
		if (not dfn[i]) tarjan (i);
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (scc[i] == scc[i + n])
		{
			cout << "IMPOSSIBLE" << endl;
			return 0;	
		}	
	} 
	
	cout << "POSSIBLE" << endl;
	
	for (int i = 1; i <= n; i++)
	{
		cout << (scc[i] < scc[i + n]) << " "; 
	}
	
	return 0;
}
