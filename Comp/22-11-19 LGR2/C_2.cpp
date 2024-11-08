#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 500010;
int n, m;

struct Edge{
	int u, v;
	long long w;
	friend bool operator < (Edge a, Edge b)
	{
		return a.w < b.w;
	}
}; 
Edge es[maxn];

int main ()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> es[i].u >> es[i].v >> es[i].w;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		init ();
		int add = kruskal (i);
		ans += kruskal (i);
	}
	
	cout << ans << endl;
	
	return 0;
}

