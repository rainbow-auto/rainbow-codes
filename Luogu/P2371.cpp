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
#define re register
using namespace std;

const int maxn = 6000010;

typedef long long ll;

int to[maxn], pre[maxn], last[maxn];
ll w[maxn];
int cnt;

inline void addEdge(ll u, ll v, ll ww)
{
	cnt ++;
	to[cnt] = v;
	w[cnt] = ww;
	pre[cnt] = last[u];
	last[u] =cnt;
}

struct Node{
	int u;
	ll dis;
	
	friend bool operator < (Node a, Node b)
	{
		return a.dis > b.dis;	
	}	
};

bool vis[maxn];
ll dis[maxn];
inline void dij (int S)
{
	memset (vis, 0, sizeof (vis));
	memset (dis, 0x3f, sizeof (dis));
	priority_queue<Node> q;
	
	dis[S] = 0;
	
	q.push(Node{S, dis[S]}); 
	
	while (not q.empty())
	{
		int u = q.top().u; q.pop();
		
//		if (vis[u]) continue;
//		vis[u] = true;
				
		for (int i = last[u]; i; i = pre[i])
		{
			int v = to[i];
			
			if (dis[v] > dis[u] + w[i])
			{
				dis[v] = dis[u] + w[i];	
				q.push (Node{v, dis[v]});
			}			
		}
	}
}

ll n, l, r;
int a[maxn];

int main ()
{
	fastread
	
	cin >> n >> l >> r;
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	
	sort (a + 1, a + n + 1);	
	
	ll m = a[1];
	
	for (int i = 0; i < m; ++i)
	{
		for (int j = 2; j <= n; ++j)
		{
			addEdge (i, (i + a[j]) % m, a[j]);
		}	
	}
	
	dij (0);
	
	ll lans = 0;
	ll rans = 0;
	for (int i = 0; i < m; ++i)
	{
		
		if (dis[i] != 0x3f3f3f3f3f3f3f3f and dis[i] <= l - 1) lans += (l - 1 - dis[i]) / m + 1;
		if (dis[i] != 0x3f3f3f3f3f3f3f3f and dis[i] <= r) rans += (r - dis[i]) / m + 1;
	}

	cout << rans - lans << endl;	
		
	return 0;
}
