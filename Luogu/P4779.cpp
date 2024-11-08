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

const int maxn = 200005;

int n, m;

struct Node{
	int t;
	int dis;
	
	friend bool operator < (Node a, Node b)
	{
		return a.dis > b.dis; // priority_queue 运算符变方向 
	}
}; 

int to[maxn], pre[maxn], last[maxn];
int w[maxn];
int cnt;

inline void addEdge (int u, int v, int ww)
{
	cnt ++;
	to[cnt] = v;
	w[cnt] = ww;
	pre[cnt] = last[u];
	last[u] = cnt;
}

int dis[maxn];
bool vis[maxn]; 

void dij (int s)
{
	priority_queue<Node> q;
	
	memset (vis, 0, sizeof (vis));
	memset (dis, 0x3f, sizeof (dis));
	dis[s] = 0;
	q.push(Node{s, dis[s]});
			
	while (not q.empty())
	{
		int now = q.top().t; q.pop();
		if (vis[now]) continue;
		vis[now] = true;
		
		for (int i = last[now]; i; i = pre[i])
		{
			int t = to[i];
			if (dis[t] > dis[now] + w[i])
			{
				dis[t] = dis[now] + w[i];
				q.push({t, dis[t]});
			}
		}
	}
}

int main ()
{
	fastread

	int s;
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++)
	{
		int u, v, ww;
		cin >> u >> v >> ww;
		addEdge (u, v, ww);
	}
	
	dij (s);
	
	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << " ";
	}	
	
	return 0;
}
