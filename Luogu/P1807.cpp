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

const int maxn = 1005;

int n, m;
int dis[maxn];

int ind[maxn];
int g[maxn][maxn];

inline void addEdge(int u, int v, int ww) {
	g[u][v] = max (g[u][v], ww);
	ind[v] ++;
}

inline void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) g[i][j] = 0;
			else g[i][j] = -1e6;
		}
		dis[i] = -1e6;
	}
}

void topoSort() {
	queue<int> q;
	
	dis[1] = 0;
	q.push(1);
		
	while (not q.empty()) {
		int u = q.front(); q.pop();
	
		for (int v = 1; v <= n; v++) {
			if (g[u][v] == -1e6) continue;
			
			if (dis[v] < dis[u] + g[u][v]) {
				dis[v] = dis[u] + g[u][v];
				q.push(v);
			}
		}		
	}
}

int main () {
	fastread
	
	cin >> n >> m;
	
	init ();
	
	for (int i = 1; i <= m; i++) {
		int u, v, ww;
		cin >> u >> v >> ww;
		
		addEdge(u, v, ww);
		
	}

	topoSort();
	
	if (dis[n] == -1e6) {
		cout << -1 << endl;
	}
	else
	{
		cout << dis[n] << endl;
	}
		
	return 0;
}
