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

const int maxn = 5005;
const int maxm = 2 * 50005;

namespace Net {
	struct Edge {
		int u, v;
		int pre;
		int flow, cost;
	} es[maxm];

	int cur[maxn], last[maxn], cnt;
	int S, T;
	int cost;
	
	inline void clear () {
		cnt = 1, cost = 0;
		memset (last, 0, sizeof(last));
	}

	inline void _addEdge (int u, int v, int cap, int cost) {
		es[++cnt] = Edge {u, v, last[u], cap, cost};
		last[u] = cnt;
	}

	inline void addEdge (int u, int v, int cap, int cost) {
		_addEdge (u, v, cap, cost);
		_addEdge (v, u, 0, -cost); // 反悔边
	}

	int dis[maxn];
	bool vis[maxn];
	inline bool spfa () {
		memset (vis, 0, sizeof (vis));
		memset (dis, 0x3f, sizeof (dis));
		queue<int> q; q.push(S); vis[S] = true; dis[S] = 0;

		while (not q.empty()) {
			int now = q.front(); q.pop();
			vis[now] = false;

			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				if (not es[i].flow) { continue; }
				if (dis[t] > dis[now] + es[i].cost) {
					dis[t] = dis[now] + es[i].cost;
					if (not vis[t]) { q.push (t); vis[t] = true; }
				}
			}
		}

		return dis[T] != 0x3f3f3f3f;
	}

	inline int dfs (int now, int now_flow) {
		if (now == T or not now_flow) { return now_flow; }

		vis[now] = true;
		
		int res = 0;
		for (int &i = cur[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (not es[i].flow) { continue; }
			if (vis[t]) { continue;}
			if (dis[t] != dis[now] + es[i].cost) { continue; }
		
			int t_flow = dfs (t, min (now_flow, es[i].flow));
			if (t_flow) {
				es[i].flow -= t_flow;
				es[i ^ 1].flow += t_flow;
				now_flow -= t_flow;
				res += t_flow;
				cost += t_flow * es[i].cost;

				if (not now_flow) { break; }
			}		
		}
		vis[now] = false; 
		return res;
	}

	inline int dinic (int _s, int _t) {
		S = _s, T = _t;

		int ans = 0;
		while (spfa ()) {
			memcpy (cur, last, sizeof(last));
			int x; while ((x = dfs (S, 0x3f3f3f3f))) { ans += x; }
		}

		return ans;
	}

}

int main () {
	fastread

	Net::clear();

	int n, m, s, t; cin >> n >> m >> s >> t;

	for (int i = 1; i <= m; i++) {
		int u, v, w, c; cin >> u >> v >> w >> c;
		Net::addEdge (u, v, w, c);
	}

	int max_flow = Net::dinic(s, t);
	int min_cost = Net::cost;
	
	cout << max_flow << " " << min_cost << endl;

	return 0;
}
