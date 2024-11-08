#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 200005;
int n, m, q;

bool ex[maxn];

int cnt;
int to[maxn], pre[maxn], last[maxn];

inline void addEdge (int u, int v)
{
	cnt ++;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt;
	ex[cnt] = true;
}

namespace Sub1{
	bool vis[maxn];
	void dfs (int now)
	{
		for (int i = last[now]; i; i = pre[i])
		{
			if (not ex[i]) continue;
			int t = to[i];
			if (vis[t]) continue;
			vis[t] = true;
			dfs (t);
		}
	}
	void solve ()
	{
		for (int i = 1; i <= q; i++)
		{
			int d;
			cin >> d;
			if (ex[d] == false)
			{
				cout << 0 << endl;
				continue;
			}
			ex[d] = false;
			memset (vis, 0, sizeof (vis));
			dfs (1);
			if (vis[n])
			{
				ex[d] = false;
				cout << 1 << endl;
			}
			else
			{
				ex[d] = true;
				cout << 0 << endl;
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio (false); 
	cin.tie(0); cout.tie(0);
	 
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		addEdge (u, v);
	}
	
	if (q <= 1000)
	{
		Sub1::solve (); 
	}
		
	return 0;
}

