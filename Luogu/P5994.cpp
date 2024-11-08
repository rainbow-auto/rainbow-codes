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

typedef long long ll;

int n;

struct Edge {
	int u, v;
	ll w;
	
	friend bool operator < (Edge a, Edge b)
	{
		return a.w < b.w;
	}
};

int fa[maxn];
int find (int x)
{
	if (fa[x] != x) return fa[x] = find (fa[x]);
	return fa[x]; 
}

vector <Edge> es;

inline ll kruskal ()
{
	sort (es.begin(), es.end());
	
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	
	ll ans = 0;
	
	for (auto e : es)
	{
		int u = find(e.u), v = find(e.v);
		
		if (u == v) continue;
	
		fa[u] = v;		
		ans += e.w;
	}		
	return ans;
} 

int main ()
{
	fastread
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int w;
			cin >> w;
			es.push_back(Edge{i - 1, j, w});
		}
	}
	
	
	cout << kruskal () << endl;
		
	return 0;
}
