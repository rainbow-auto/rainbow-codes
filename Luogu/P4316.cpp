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

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 100005;
const int maxm = 200005;

int n, m;

struct Edge {
	int u, v;
	int pre;
	int w;
} es[maxm << 1];

int last[maxn], cnt;

int deg[maxn];

inline void addEdge (int u, int v, int w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
	deg[u] ++;
}


double dp[maxn];
bool vis[maxn];

void dfs (int now) {
	if (now == n) { return; }
	if (vis[now]) { return; }
	vis[now] = true;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		dfs (t);
		dp[now] += (dp[t] + es[i].w) / deg[now];
	}
}

int main () {
	fastread
	
	std::cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int u, v, w; std::cin >> u >> v >> w;
		addEdge (u, v, w);
	}

	memset (vis, 0, sizeof (vis));
	dfs (1);

	printf ("%.2lf", dp[1]);

	return 0;
}
