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

int n;

int S, T;
int col[maxn], row[maxn], tot;

struct Edge {
	int u, v;
	int flow;
	int pre;
} es[maxn];

int last[maxn], cnt = 1;
int cur[maxn];

inline void _addEdge (int u, int v, int cap) {
	es[++cnt] = Edge { u, v, cap, last[u] };
	last[u] = cnt;
}

inline void addEdge (int u, int v, int cap) {
	_addEdge (u, v, cap);
	_addEdge (v, u, 0);
}

int inf;
int dis[maxn];
bool bfs () {
	memset (&inf, 0x3f, sizeof (&inf));
	memset (dis, 0x3f, sizeof (dis)); dis[S] = 1;
	std::queue <int> q; q.push (S);

	while (not q.empty ()) {
		int u = q.front (); q.pop ();
		for (int i = last[u]; i; i = es[i].pre) {
			int v = es[i].v;

			if (not es[i].flow) { continue; }
			if (dis[v] != inf) { continue; }

			dis[v] = dis[u] + 1;
			q.push (v);
		}
	}

	return dis[T] != inf;
}

int dfs (int now, int now_flow) {
	if (now == T or now_flow == 0) { return now_flow; }
	
	int res = 0;
	for (int& i = cur[now]; i; i = es[i].pre) {
		int t = es[i].v;

		if (dis[t] != dis[now] + 1) { continue; }
		if (not es[i].flow) { continue; }

		int t_flow = dfs (t, std::min (es[i].flow, now_flow));

		if (t_flow) {
			es[i].flow -= t_flow;
			es[i ^ 1].flow += t_flow;
			now_flow -= t_flow;
			res += t_flow;
			
			if (not now_flow) { return res; }
		}
	}
	return res;
}

int dinic () {
	int res = 0;
	while (bfs ()) {
		memcpy (cur, last, sizeof (last));
		res += dfs (S, inf);
	}
	return res;
}

inline void clear () {
	tot = 0; cnt = 1;
	memset (last, 0, sizeof (last));
	memset (cur, 0, sizeof (cur));
}

int main () {
	fastread
	
	int tt; std::cin >> tt;
	while (tt--) {
		clear ();

		std::cin >> n;

		S = ++tot; T = ++tot; 

		for (int i = 1; i <= n; i++) { col[i] = ++tot; }
		for (int i = 1; i <= n; i++) { row[i] = ++tot; }

		for (int i = 1; i <= n; i++) { addEdge (S, col[i], 1); }
		for (int i = 1; i <= n; i++) { addEdge (row[i], T, 1); }

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int val; std::cin >> val;
				if (val) { addEdge (col[i], row[j], 1); }
			}
		}

		std::cout << (dinic () >= n ? "Yes\n" : "No\n");
	}


	return 0;
}
