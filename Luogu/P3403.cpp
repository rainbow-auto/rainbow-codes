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

typedef long long ll;

const int maxn = 300005;

int to[maxn], pre[maxn], last[maxn];
ll w[maxn];
int cnt;

inline void addEdge (int u, int v, ll ww)
{
	cnt ++;
	to[cnt] = v;
	w[cnt] = ww;
	pre[cnt] = last[u];
	last[u] = cnt;
}

struct Node{
	int u;
	ll dis;
	
	friend bool operator < (Node a, Node b)
	{
		return a.dis > b.dis;		
	}
};

ll dis[maxn];
bool vis[maxn];

inline void dij (int S)
{
	memset (dis, 0x3f, sizeof (dis));
	dis[S] = 0;		
	priority_queue<Node> q;
	q.push(Node{S, dis[S]}); 
	
	while (not q.empty ())
	{
		int u = q.top().u; q.pop();
		
		for (int i = last[u]; i; i = pre[i])
		{
			int v = to[i];
			
			if (dis[v] > dis[u] + w[i])
			{
				dis[v] = dis[u] + w[i];
				q.push(Node{v, dis[v]});
			}
		}
	}
}

ll h;
ll a[4]; 

signed main ()
{
//	fastread
	
	cin >> h; h--; // 这里是把1 ~ h转化为0 ~ h-1 
	cin >> a[1] >> a[2] >> a[3];
	
	sort (a + 1, a + 3 + 1);
	int m = a[1]; 
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 2; j <= 3; j++)
		{
			addEdge (i, (i + a[j]-1) % m+1, a[j]);	
		}	
	}	
	
	dij (1);
	
	ll res = 0;	
	for (int i = 1; i <=m; i++)
	{
		if (h >= dis[i]) res += (h - dis[i]) / (m+1) + 1;
	}	
	
	cout << res  << endl;	
		
	return 0;
}
