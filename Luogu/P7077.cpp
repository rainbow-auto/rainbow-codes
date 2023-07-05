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

const int maxn = 500010;
const int mod = 998244353;

long long a[maxn];
long long pos[maxn], val[maxn];
int type[maxn];

int n, m, q;
int query[maxn];
long long k[maxn]; // k[i]: 第i个函数的乘法系数 
long long tag[maxn]; // tag[i]: 第i个函数的加法前的系数 

int to[maxn << 1], pre[maxn << 1], last[maxn];
int cnt;

inline void addEdge (int u, int v)
{
	cnt ++;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt;	
}

int ind[maxn];

bool vis[maxn]; 
void dfs (int now) // dfs 求k 
{
	if (vis[now]) return;
	vis[now] = true;
	for (int i = last[now]; i; i = pre[i])
	{
		int t = to[i];
		ind[t] ++;
		dfs (t);
		k[now] = (k[now] * k[t]) % mod;
	}
}

queue<int> que;
void topSort()
{
	memset (vis, 0, sizeof (vis));
	for (int i = 1; i <= m; i++)
	{
		if (ind[i] == 0) que.push(i);
	}
	while (not que.empty())
	{
		int now = que.front();
		que.pop();
		
		if (vis[now]) continue;
		vis[now] = true;
	
		long long tempk = 1;	
		for (int i = last[now]; i; i = pre[i])
		{
			int t = to[i];
			tag[t] = ( tag[t] + (tempk * tag[now]) % mod ) % mod;
			tempk = (tempk * k[t]) % mod;
			
			ind[t] --;
			if (ind[t] == 0) que.push(t);
		}		
	}
}

int main ()
{
//	fastread
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		k[i] = 1; // 系数至少是1 
		cin >> type[i];
		if (type[i] == 1)
		{
			cin >> pos[i] >> val[i];
		}		
		else if (type[i] == 2)
		{
			cin >> k[i];
		}
		else if (type[i] == 3)
		{
			int c;
			cin >> c;
			for (int j = 1; j <= c; j++)
			{
				int t;
				cin >> t;
				addEdge(i, t);
			}
		}
	}
	
	cin >> q;
	for (int i = 1; i <= q; i++) cin >> query[i];
	
	memset (vis, 0, sizeof (vis));
	for (int i = 1; i <= m; i++) dfs (i);
	
	long long k_mul = 1;
	long long tempk = 1;
	
	for (int i = q; i >= 1; i--)
	{
		int t = query[i];
		k_mul = (k_mul * k[t]) % mod;
		
		tag[t] = (tag[t] + tempk) % mod;
		tempk = (tempk * k[t]) % mod;
	} 
	
	topSort();
	
	for (int i = 1; i <= n; i++)
	{
		a[i] = (a[i] * k_mul) % mod;
	}
	
	for (int i = 1; i <= m; i++)
	{
		if (type[i] != 1) continue;
		a[pos[i]] = (a[pos[i]] + (tag[i] * val[i]) % mod ) % mod; 
	}
	
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;
	
	return 0;
}
