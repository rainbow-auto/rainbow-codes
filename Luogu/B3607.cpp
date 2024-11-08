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

#define int long long

const int maxn = 10005;

int n, m, S, T;

namespace Net {
	struct Edge {
		int u, v;
		int pre;
		int flow;
	} es[maxn];
	int last[maxn], cur[maxn], cnt = 1;

	inline void _addEdge (int u, int v, int cap) {
		cnt ++;
		es[cnt].u = u;
		es[cnt].v = v;
		es[cnt].flow = cap;
		es[cnt].pre = last[u];
		last[u] = cnt;
	}

	inline void addEdge (int u, int v, int cap) {
		_addEdge(u, v, cap);
		_addEdge(v, u, 0);
	}

	int dep[maxn];
	inline bool bfs () {
		queue<int> q; q.push(S);
		memset (dep, 0, sizeof(dep)); dep[S] = 1;

		while (not q.empty()) {
			int now = q.front(); q.pop();

			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				if (not dep[t] and es[i].flow) {
					dep[t] = dep[now] + 1;
					q.push(t);
				} 
			}
		}
		return dep[T];
	}

	int dfs (int now, int now_flow) {
		if (now == T) { return now_flow; }

		int res = 0;
		for (int &i = cur[now]; i and now_flow; i = es[i].pre) {
			int t = es[i].v;
			if (not es[i].flow) { continue; }
			if (dep[t] != dep[now] + 1) { continue; }

			int t_flow = dfs (t, min(es[i].flow, now_flow));
			
			if (t_flow) {
				es[i].flow -= t_flow;
				es[i ^ 1].flow += t_flow;
				now_flow -= t_flow;
				res += t_flow;
			}
		}
		return res;
	}

	void dinic () {
		int res = 0;
		while (bfs()) {
			memcpy (cur, last, sizeof(last));
			res += dfs(S, 0x3f3f3f3f);
		}
		cout << res << endl;
	}
}

namespace Reader {
	int g[105][105];

	inline void read() {
		cin >> n >> m >> S >> T;
		for (int i = 1; i <= m; i++) {
			int u, v, cap; cin >> u >> v >> cap;
			g[u][v] += cap;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (g[i][j]) { Net::addEdge (i, j, g[i][j]); }
			}
		}
	}
}

signed main () {
	fastread
	
	Reader::read();
	Net::dinic();

	return 0;
}
