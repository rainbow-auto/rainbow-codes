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

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 100005;

int n, k;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;
int deg[maxn];

bool vis[maxn];

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int dis[maxn];

int main () {
	fastread
	
	std::cin >> n >> k;

	for (int i = 1; i <= n - 1; i ++) {
		int u, v; std::cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
		deg[u] ++; deg[v] ++;
	}

	std::queue <int> q;
	int tot = 0;
	int ans = 0;

	for (int i = 1; i <= n; i++) { 
		if (deg[i] == 1) { 
			q.push (i); dis[i] = 1; tot ++; deg[i] --;
			ans = std::max (ans, dis[i]);
		} 
	}

	if (tot >= n - k) { std::cout << ans << "\n"; return 0; }

	while (not q.empty ()) {
		int u = q.front (); q.pop ();

		for (int i = last[u]; i; i = es[i].pre) {
			int v = es[i].v;
			
			--deg[v];
			if (deg[v] != 1) { continue; }
			
			q.push (v);
			dis[v] = dis[u] + 1;

			ans = std::max (ans, dis[v]);	
			
			tot ++;
			if (tot >= n - k) { std::cout << ans << "\n"; return 0; }
		}
	}

	std::cout << ans << "\n";

	return 0;
}
