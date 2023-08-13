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

const int maxn = 100005;

namespace Net {
	struct Edge {
		int u, v, pre;
		int flow;
	};
	Edge es[maxn];
	int last[maxn], cur[maxn], cnt = 1; // cnt从1开始容易求出反向边
	bool vis[maxn];

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
		_addEdge(v, u, cap);
	}

	inline void init () {
		cnt = 1;
		memset (last, 0, sizeof(last));
		memset (vis, 0, sizeof(vis));
	}

	int S, T;

	int dep[maxn]; // 分层
	inline bool bfs () {
		memset (dep, 0x3f, sizeof(dep));
		dep[S] = 0;
		queue<int> q; q.push(S);

		while (not q.empty()) {
			int now = q.front(); q.pop();

			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;

				if (dep[t] == 0x3f3f3f3f and es[i].flow != 0) { // 没被访问过且有流量
					dep[t] = dep[now] + 1;
					q.push(t);
				}
			}
		}		

		return dep[T] != 0x3f3f3f3f;
	}	

	inline int dfs (int now, int now_flow) {
		if (now_flow == 0 or now == T) { return now_flow; } // 没有流量了或者到了
		
		int res = 0;
		for (int &i = cur[now]; i; i = es[i].pre) {
			int t = es[i].v;
			
			if (es[i].flow == 0 or dep[t] != dep[now] + 1) { continue; } // 没流量了 或者 不是下一层 

			int t_flow = dfs(t, min(now_flow, es[i].flow)); // 不能超过流量限制
			if (t_flow) { // 能流到t
				es[i].flow -= t_flow; // 这条边的容量被消耗了
				es[i ^ 1].flow += t_flow; // 反悔边
				res += t_flow;
				now_flow -=  t_flow;
				if (not now_flow) { return res; } // 当前的流量被耗尽了
			}
		}

		return res;
	}

	int dinic (int _s, int _t) {
		S = _s, T = _t;
		
		int res = 0;
		while (bfs ()) {
			memcpy (cur, last, sizeof(last)); // 把
			res += dfs (S, 0x3f3f3f3f); // 源点有无限的流量
		}
		return res;
	}

	void find (int now) {
		vis[now] = true;
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (vis[t]) { continue; } // 不重复访问
			if (es[i].flow <= 0) { continue; } // 有流量的才能流

			find(t);
		}
	}	

	inline void output (vector<pair<int, int> > edges) {
		// cout << "start output" << endl;
		for (auto x : edges) {
			int u = x.first;
			int v = x.second;
			if (vis[u] ^ vis[v]) { cout << u << " " << v << endl; }
		}
		cout << endl;
	}
}

int main () {
	fastread
	
	int n, m;
	while (cin >> n >> m) {
		if (not n) { return 0; }
		Net::init();

		vector<pair<int, int> > edges;
		for (int i = 1; i <= m; i++) {
			int u, v, w; cin >> u >> v >> w;
			Net::addEdge(u, v, w);
			edges.push_back({u, v});
		}

		Net::dinic(1, 2);
		Net::find(1);
		Net::output(edges);
	}

	return 0;
}
