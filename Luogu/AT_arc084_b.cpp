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

const int maxn = 1200005;

struct Edge {
	int u, v;
	int w;
	int pre;
} es[maxn];

int last[maxn], cnt;

inline void addEdge (int u, int v, int w) {
	es[++cnt] = Edge { u, v, w, last[u] };
	last[u] = cnt;
}

int k;

struct Node {
	int id;
	int dis;

	friend bool operator < (Node a, Node b) {
		return a.dis > b.dis;
	}
};

int dis[maxn];
bool vis[maxn];

inline void dij (int S) {
	memset (vis, 0, sizeof (vis));
	memset (dis, 0x3f, sizeof (dis)); dis[S] = 0;
	std::priority_queue <Node> q; q.push (Node { S, dis[S] });

	while (not q.empty ()) {
		int now = q.top ().id; q.pop ();

		if (vis[now]) { continue; }
		vis[now] = true;

		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;

			if (dis[t] > dis[now] + es[i].w) { 
				dis[t] = dis[now] + es[i].w;
				q.push (Node { t, dis[t] }); 
			}
		}
	}
}

int main () {
	fastread
	
	std::cin >> k;

	int S = k;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 10; j++) {
			addEdge (i, (i * 10 + j) % k, j);
		}
	}

	for (int j = 1; j < 10; j++) { addEdge (S, j % k, j); }

	dij (S);
	std::cout << dis[0] << "\n"; // 最终 S 要求是 k 的倍数

	return 0;
}
