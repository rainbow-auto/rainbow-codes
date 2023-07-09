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

const int maxn = 1000005; 

int to[maxn], pre[maxn], last[maxn];
int cnt;
int w[maxn];

inline void addEdge (int u, int v, int ww)
{
	cnt ++;
	to[cnt] = v;
	w[cnt] = ww;
	pre[cnt] = last[u];
	last[u] = cnt;
}

int n, m, k;

struct Node{
	int u, k;
	int dis;
	
	friend bool operator < (Node a, Node b)
	{
		return a.dis > b.dis;
	}
};

bool vis[maxn][15];
int dis[maxn][15];

int dij (int s, int t)
{
	priority_queue<Node> q;
	
	memset (dis, 0x3f, sizeof (dis));
	dis[s][0] = 0; 
	q.push(Node{s, 0, dis[s][0]});
	
	while (not q.empty())
	{
		int now = q.top().u, nowk = q.top().k; q.pop();
		if (vis[now][nowk]) continue;
		vis[now][nowk] = true;
		
		for (int i = last[now]; i; i = pre[i])
		{
			int t = to[i];
			if (nowk < k and dis[t][nowk + 1] > dis[now][nowk]) // Ö±½Ó×ªÒÆ
			{
				dis[t][nowk + 1] = dis[now][nowk];	
				q.push(Node{t, nowk + 1, dis[t][nowk + 1]});
			} 
			
			if (dis[t][nowk] > dis[now][nowk] + w[i])
			{
				dis[t][nowk] = dis[now][nowk] + w[i];
				q.push(Node{t, nowk, dis[t][nowk]});
			}
		}
	}
	
	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= k; i++)
	{
		ans = min (ans, dis[t][i]);
	}
	return ans;
}

int main ()
{
	fastread
		
	cin >> n >> m >> k;
	
	int s, t;
	cin >> s >> t;
	
	for (int i = 1; i <= m; i++)
	{
		int u, v, ww;
		cin >> u >> v >> ww;
		addEdge (u, v, ww);
		addEdge (v, u, ww);
	}
	
	cout << dij (s, t) << endl;	
		
	return 0;
}
