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

const int maxn = 1365 + 5;
const int maxm = 800005; // 366365 * 2

namespace Net {
	struct Edge {
		int u, v;
		int pre;
		int flow;
	} es[maxm];

	int last[maxn], cur[maxn], cnt;
	int in[maxn], out[maxn];
	int S, T;

	inline void _addEdge (int u, int v, int cap) {
		es[++cnt] = Edge { u, v, last[u], cap };
		last[u] = cnt;
	}

	inline void addEdge (int u, int v, int l, int r) {
		_addEdge (u, v, r - l); in[v] += l;
		_addEdge (v, u, 0); out[u] += l;
	}

	int tot = 0;
	inline int newNode () { return ++tot; }

	int dep[maxn];
	inline bool bfs () {
		queue<int> q; q.push(S);
		memset (dep, 0, sizeof(dep)); dep[S] = 1;

		while (not q.empty()) {
			int now = q.front(); q.pop();

			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				if (not es[i].flow) { continue; }
				if (dep[t]) { continue; }

				dep[t] = dep[now] + 1;
				q.push(t);
			}
		}

		return dep[T];
	}

	int dfs (int now, int now_flow) {
		if (now == T or not now_flow) { return now_flow; }

		int res = 0;
		for (int &i = cur[now]; i; i = es[i].pre) {
			int t = es[i].v;

			if (not es[i].flow) { continue; }
			if (dep[t] != dep[now] + 1) { continue; }

			int t_flow = dfs (t, min (now_flow, es[i].flow));
			if (t_flow) {
				es[i].flow -= t_flow;
				es[i ^ 1].flow += t_flow;
				now_flow -= t_flow;
				res += t_flow;

				if (not now_flow) { break; }
			}
		}

		return res;
	}

	int dinic (int _s, int _t) {
		S = _s, T = _t;

		int maxFlow = 0;
		while (bfs ()) {
			memcpy (cur, last, sizeof(last));
			int x; while (x = dfs (S, 0x3f3f3f3f)) { maxFlow += x; }
		}
		return maxFlow;
	}

	inline int balance (int ss, int tt) {
		int sum = 0;
		for (int i = 1; i <= tot; i++) {
			if (in[i] - out[i] > 0) {
				addEdge (ss, i, 0, in[i] - out[i]);
				sum += in[i] - out[i];
			} else if (out[i] - in[i] > 0) {
				addEdge (i, tt, 0, out[i] - in[i]);
			}
		}
		return sum;
	}

	int getMaxFlow (int s, int t) {
		int ss = newNode ();
		int tt = newNode ();
		int sum = balance (ss, tt);

		addEdge (t, s, 0, 0x3f3f3f3f);
		int flow1 = dinic (ss, tt);

		if (flow1 != sum) { return -1; }

		es[cnt].flow = es[cnt ^ 1].flow = 0;
		int flow2 = dinic (s , t );

		return flow1 + flow2;
	}

	inline void clear () {
		cnt = 1, tot = 0;
		memset (last, 0, sizeof (last));
		memset (in, 0, sizeof (in));
		memset (out, 0, sizeof (out));
	}
}

int n, m;
int g[maxn], d[maxn];

struct Girl {
	int id;
	int l, r;
};
vector<Girl> a[maxn];

int aid[maxn], bid[maxn];
inline auto buildGraph () {
	for (int i = 1; i <= n; i++) { aid[i] = Net::newNode (); }
	for (int i = 0; i < m; i++) { bid[i] = Net::newNode (); }
	int S = Net::newNode ();
	int T = Net::newNode ();

	for (int i = 1; i <= n; i++) { Net::addEdge (S, aid[i], 0, d[i]); }
	for (int i = 0; i < m; i++) { Net::addEdge (bid[i], T, g[i], 0x3f3f3f3f); }

	for (int i = 1; i <= n; i++) {
		for (auto girl : a[i]) {
			Net::addEdge (aid[i], bid[girl.id], girl.l, girl.r);
		}
	}

	return pair <int, int> { S, T };
}

int main () {
	fastread
	
	while (cin >> n >> m) {
		Net::clear ();
		for (int i = 1; i <= n; i++) { a[i].clear (); }

		for (int i = 0; i < m; i++) { cin >> g[i]; }

		for (int i = 1; i <= n; i++) {
			int cnt; cin >> cnt;
			cin >> d[i];

			for (int j = 1; j <= cnt; j++) {
				int id, l, r; cin >> id >> l >> r;
				a[i].push_back (Girl { id, l, r });
			}
		}

		auto st = buildGraph ();

		int ans = Net::getMaxFlow (st.first, st.second);
		cout << ans << endl;
		cout << endl;
	}	

	return 0;
}
