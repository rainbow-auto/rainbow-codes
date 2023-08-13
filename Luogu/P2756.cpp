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

const int maxn = 20405;

int n, m;

namespace Net {
	struct Edge {
		int u, v;
		int flow;
		int pre;
	} es[maxn];

	int cur[maxn], last[maxn], cnt;
	int dep[maxn];

	int S, T;

	inline void _addEdge(int u, int v, int cap) {
		cnt ++;
		es[cnt].u = u;
		es[cnt].v = v;
		es[cnt].flow = cap;
		es[cnt].pre = last[u];
		last[u] = cnt;
	}

	inline void addEdge(int u, int v, int cap) {
		_addEdge(u, v, cap);
		_addEdge(v, u, 0);
	}

	inline void init() {
		cnt = 1;
		memset(last, 0, sizeof(last));
	}

	bool bfs() {
		memset(dep, 0, sizeof(dep)); dep[S] = 1;
		queue<int> q; q.push(S);

		while (not q.empty()) {
			int now = q.front(); q.pop();

			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				if (not es[i].flow) { continue; }
				if (not dep[t]) {
					dep[t] = dep[now] + 1;
					q.push (t);
				}
			}
		}

		return dep[T];
	}

	int dfs(int now, int now_flow) {
		if (now == T) { return now_flow; }
		
		int res = 0;
		for (int i = last[now]; i and now_flow; i = es[i].pre) {
			int t = es[i].v;
			if (not es[i].flow or dep[t] != dep[now] + 1) { continue; }

			int t_flow = dfs(t, min(now_flow, es[i].flow));
			if (t_flow) {
				es[i].flow -= t_flow;
				es[i ^ 1].flow += t_flow;
				now_flow -= t_flow;
				res += t_flow;
			}
		}

		return res;
	}
	
	int dinic(int _s, int _t) {
		S = _s, T = _t;
		int res = 0;

		while (bfs()) {
			memcpy(cur, last, sizeof(last));
			res += dfs(S, 0x3f3f3f3f);
		}

		return res;
	}

	inline void output() {
		for (int u = 1; u <= m; u++) {
			int res = -1;
			for (int i = last[u]; i; i = es[i].pre) {
				int v = es[i].v;
				if (es[i].flow == 0 and v != S) { res = v; break; }
			}

			if (res != -1) {
				cout << u << " " << res << endl;	
			}
		}
	}
}


int main () {
	fastread

	Net::init();
	cin >> m >> n;

	int S = 0, T = n + 1;

	for (int i = 1; i <= m; i++) { Net::addEdge (S, i, 1); }
	for (int i = m + 1; i <= n; i++) { Net::addEdge (i, T, 1); }

	while (true) {
		int u, v; cin >> u >> v;
		if (u == -1 and v == -1) { break; }
		Net::addEdge (u, v, 1);
	}

	cout << Net::dinic(S, T) << endl;
	Net::output();

	return 0;
}
