// P3953
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

const int maxn = 100005;
const int maxm = 200005;
const int maxk = 55;

int T;
int n, m, K, p;

struct Graph{
	int to[maxm], pre[maxm], last[maxn];
	int w[maxm];
	int cnt;
	
	inline void addEdge (int u, int v, int wnow)
	{
		cnt++;
		to[cnt] = v;
		pre[cnt] = last[u];
		last[u] = cnt;
		w[cnt] = wnow;	
	}
	
	inline void clear ()
	{
		memset (to, 0, sizeof (to));
		memset (pre, 0, sizeof (pre));
		memset (last, 0, sizeof (last));
		cnt = 0;
	}	
};
Graph G, dpG; // ·´Í¼ 

struct Node{
	int id;
	int dis;
	friend bool operator < (Node a, Node b)
	{
		return a.dis > b.dis; // priority_queue 
	}
};

int d[maxn];
bool vis[maxn];
void dij ()
{
	priority_queue<Node> q;
	
	memset (vis, 0, sizeof (vis));
	memset (d, 0x3f, sizeof (d));
	d[1] = 0;
	q.push(Node{1, d[1]});
	
	while (not q.empty())
	{
		int u = q.top().id;
		q.pop();
		
		if (vis[u]) continue;
		vis[u] = true; 
		
		for (int i = G.last[u]; i; i = G.pre[i])
		{
			int v = G.to[i];
			if (d[v] > d[u] + G.w[i])
			{
				d[v] = d[u] + G.w[i];
				q.push(Node{v, d[v]});
			}
		}
	}
}

bool flag = false;
bool inPath[maxn][maxk];
int dp[maxn][maxk];

int solve (int u, int k)
{
	if (k < 0) return 0;
	if (inPath[u][k])
	{
		flag = true;
		return 0;
	}
	
	if (dp[u][k] != 0) return dp[u][k];
	
	inPath[u][k] = true;
			
	for (int i = dpG.last[u]; i; i = dpG.pre[i])
	{
		int v = dpG.to[i];
		dp[u][k] = ( dp[u][k] + solve (v, d[u] - d[v] + k - dpG.w[i]) ) % p;
		if (flag) return 0;
	}
	
	inPath[u][k] = false;
	
	return dp[u][k];		
}

int main ()
{
	cin >> T;
	while (T--)
	{
		G.clear();
		dpG.clear();
		
		cin >> n >> m >> K >> p;
		for (int i = 1; i <= m; i++)
		{
			int u, v, wnow;
			cin >> u >> v >> wnow;
			G.addEdge(u, v, wnow);
			dpG.addEdge(v, u, wnow); // ·´Í¼	
		}
		dij ();
		
		memset (inPath, 0, sizeof (inPath));
		memset (dp, 0, sizeof (dp));
		dp[1][0] = 1;
		
		int ans = 0;	
		for (int i = 0; i <= K; i++)
		{
			flag = false;
			ans = (ans + solve (n, i)) % p;
			
			if (flag)
			{
				cout << -1 << endl;
				break;
			}
		}
		flag = false;
		solve (n, K + 1);
		if (flag)
		{
			cout << -1 << endl;
		}
		
		if (flag) continue;
			
		cout << ans << endl;
	}
			
	return 0;
}
