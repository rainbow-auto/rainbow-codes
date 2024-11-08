#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

const int maxn = 200005;

int n, m;

struct Edge {
	int u, v;
	int pre;
	i64 w;
} es[maxn << 1];

int last[maxn], cnt;
inline void addEdge (int u, int v, i64 w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

i64 val[maxn];

struct Node {
	int id;
	i64 dis;

	friend bool operator < (Node a, Node b) { return a.dis > b.dis; }
};

std::priority_queue <Node> q;
std::bitset <maxn> vis;

i64 dis[maxn];
inline void dij () {
	dis[1] = 0; rep (i, 2, n) { dis[i] = 1e18; }
	vis.reset ();
	q.push (Node { 1, dis[1] });

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

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n >> m;
	rep (i, 1, n) { std::cin >> val[i]; }
	
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		i64 w; std::cin >> w;
		addEdge (u, v, w + val[v]);
		addEdge (v, u, w + val[u]);
	}

	dij ();

	rep (i, 2, n) {
		std::cout << dis[i] + val[1] << " ";
	}

	return 0;
}
