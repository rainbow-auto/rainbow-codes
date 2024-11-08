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

const int maxn = 105;
const int maxm = 2040205;

namespace Net {
	struct Edge {
		int u, v;
		int pre;
		int flow;
		int cost;
	} es[maxm];

	int last[maxn], cur[maxn], cnt;

	inline void _addEdge (int u, int v, int cap, int cost) {
		es[++cnt] = Edge { u, v, last[u], cap, cost };
		last[u] = cnt;
	}

	inline void addEdge (int u, int v, int cap, int cost) {
		cout << u << " " << v << " " << cap << "," << cost << endl;
		_addEdge (u, v, cap, cost);
		_addEdge (v, u, 0, -cost);
	}

	int tot = 0;
	inline int newNode () { return ++tot; }

	int S, T;
	int cost;

	bool vis[maxn];
	int dis[maxn];
	inline bool spfa () {
		memset (vis, 0, sizeof (vis));
		memset (dis, 0x3f, sizeof (dis));
		queue<int> q; q.push (S); dis[S] = 0; vis[S] = true;

		while (not q.empty()) {
			int now = q.front (); q.pop ();
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
	
	int dfs (int now, int now_flow) {
		if (now == T or not now_flow) { return now_flow; }

		vis[now] = true;

		int res = 0;
		for (int &i = cur[now]; i; i = es[i].pre) {
			int t = es[i].v;

			if (not es[i].flow) { continue; }
			if (dis[t] != dis[now] + es[i].cost) { continue; }
			if (vis[t]) { continue; }

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

	struct MCMF {
		int minCost, maxFlow;
	};

	inline MCMF dinic (int _s, int _t) {
		S = _s, T = _t;

		int maxFlow = 0;
		while (spfa ()) {
			cout << "dinic" << endl;

			memcpy (cur, last, sizeof (last));
			maxFlow += dfs (S, 0x3f3f3f3f);
		}

		return MCMF { cost, maxFlow };
	}

	inline void clear () {
		cnt = 1; tot = 0; 
		memset (last, 0, sizeof (last));
		cost = 0;
	}
}

int n;

int a[maxn][maxn];

int aid[maxn]; // 点在网络上的编号

struct Edge {
	int id; // 边在网络上的编号
	int u, v;
	int uid, vid;
};
vector<Edge> es;
int eid[maxn][maxn];

inline auto buildGraph () {
	for (int i = 1; i <= n; i++) { aid[i] = Net::newNode (); }

	int S = Net::newNode ();
	int T = Net::newNode ();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 1) { Net::addEdge (S, aid[i], 1, 0); }
			if (a[i][j] == 2) { eid[i][j] = es.size (); es.push_back (Edge { Net::newNode (), i, j, 0, 0 }); }
		}
	}

	for (auto &edge : es) {
		Net::addEdge (S, edge.id, 1, 0);
		edge.uid = Net::cnt + 1; Net::addEdge (edge.id, aid[edge.u], 1, 0);
		edge.vid = Net::cnt + 1; Net::addEdge (edge.id, aid[edge.v], 1, 0);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			Net::addEdge (aid[i], T, 1, j);
		}
	}

	return pair <int, int> { S, T };
}

int res[maxn][maxn];

int main () {
	// fastread
	
	Net::clear ();

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j]; 
			res[i][j] = a[i][j];
		}
	}

	auto st = buildGraph ();
	int ans = Net::dinic (st.first, st.second).minCost;
	cout << "minCost = " << ans << endl;

	ans = n * (n - 1) * (n - 2) / 6 - ans;
	cout << ans << endl;

	for (auto edge : es) {
		res[edge.u][edge.v] = Net::es[edge.uid ^ 1].flow == 1 ? 1 : 0;
		res[edge.v][edge.u] = Net::es[edge.vid ^ 1].flow == 1 ? 1 : 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
