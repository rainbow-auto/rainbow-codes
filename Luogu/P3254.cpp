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

const int maxn = 60505;

namespace Net {
	struct Edge {
		int u, v;
		int pre;
		int flow;
	} es[maxn << 1];

	int last[maxn], cur[maxn], cnt;

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

	inline void init () {
		cnt = 1;
		memset (last, 0, sizeof(last));
	}

	int S, T;

	int dep[maxn];
	bool bfs () {
		// cout << "start bfs" << endl;
		
		memset (dep, 0, sizeof(dep)); dep[S] = 1;
		queue<int> q; q.push(S);
		
		while (not q.empty()) {
			int now = q.front(); q.pop();
			
			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				if ((not dep[t]) and es[i].flow) {
					dep[t] = dep[now] + 1;
					q.push(t);	
				}
			}
		}

		// cout << "end bfs" << endl;
		return dep[T];
	}

	int dfs (int now, int now_flow) {
		if (now == T) { return now_flow; }
		
		int res = 0;
		for (int &i = cur[now]; i and now_flow; i = es[i].pre) {
			int t = es[i].v;
			if (dep[t] != dep[now] + 1) { continue; }

			int t_flow = dfs (t, min(es[i].flow, now_flow));
			if (not es[i].flow) { continue; }
			if (t_flow) {
				es[i].flow -= t_flow;
				es[i ^ 1].flow += t_flow;
				now_flow -= t_flow;
				res += t_flow;
			}
		}
		return res;
	}

	inline int dinic (int _s, int _t) {
		S = _s; T = _t;
		int ans = 0;
		while (bfs()) {
			memcpy (cur, last, sizeof(last));
			ans += dfs(S, 0x3f3f3f3f);
		}
		return ans;
	}
}

int m, n;

int main () {
	// fastread

	Net::init();

	cin >> m >> n;

	int sum = 0;

	int S = 0, T = n + m + 1;
	for (int i = 1; i <= m; i++) {
		int r; cin >> r;
		Net::addEdge(S, i, r);
		sum += r;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			Net::addEdge(i, j + m, 1);
		}
 	}


	for (int i = 1; i <= n; i++) {
		int c; cin >> c;
		Net::addEdge(i + m, T, c);
	}

	int res = Net::dinic(S, T);

	if (res == sum) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl; return 0;
	}
	
	// 输出
	for (int i = 1; i <= m; i++) {
		for (int j = Net::last[i]; j; j = Net::es[j].pre) {
			int t = Net::es[j].v;
			if (t <= m) { continue; }
			if (t > n + m) { continue; }
			if (not Net::es[j].flow) { cout << t - m << " "; }
		}
		cout << endl;
	}

	return 0;
}
