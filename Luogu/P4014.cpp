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

const int maxn = 205;
const int maxm = 20405;

namespace Net {
	struct Edge {
		int u, v;
		int pre;
		int flow;
		int cost;
	} es[maxm];

	int last[maxn], cur[maxn], cnt;
	int S, T;
	int cost;

	inline void _addEdge (int u, int v, int cap, int cost) {
		es[++cnt] = Edge { u, v, last[u], cap, cost };
		last[u] = cnt;
	}

	inline void addEdge (int u, int v, int cap, int cost) {
		_addEdge (u, v, cap, cost);
		_addEdge (v, u, 0, -cost);
	}

	inline void clear () {
		memset (last, 0, sizeof(last));
		cnt = 1; cost = 0;
	}

	int dis[maxn];
	bool vis[maxn];

	inline bool spfa () {
		memset (dis, 0x3f, sizeof(dis));
		memset (vis, 0, sizeof(vis));
		queue<int> q; q.push (S); dis[S] = 0; vis[S] = true;
		
		while (not q.empty()) {
			int now = q.front(); q.pop();
			vis[now] = false;

			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				if (not es[i].flow) { continue; }
				if (dis[t] > dis[now] + es[i].cost) {
					dis[t] = dis[now] + es[i].cost;
					if (not vis[t]) { q.push(t); vis[t] = true; }
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
			if (vis[t]) { continue; }
			if (dis[t] != dis[now] + es[i].cost) { continue; }

			int t_flow = dfs (t, min (es[i].flow, now_flow));
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

	int dinic (int _s, int _t) {
		S = _s, T = _t;

		int max_flow = 0;
		while (spfa ()) {
			memcpy (cur, last, sizeof (last));
			max_flow += dfs (S, 0x3f3f3f3f);
		}

		return cost;
	}

}

int n;
int c[maxn][maxn];


int tot;
inline int newNode () { return ++tot; }

int aid[maxn], bid[maxn];
int S, T;

inline void buildGraph (int flag) {
	tot = 0;
	for (int i = 1; i <= n; i++) { aid[i] = newNode (); }
	for (int i = 1; i <= n; i++) { bid[i] = newNode (); }
	S = newNode (), T = newNode ();

	for (int i = 1; i <= n; i++) { Net::addEdge (S, aid[i], 1, 0); }
	for (int i = 1; i <= n; i++) { Net::addEdge (bid[i], T, 1, 0); }
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			Net::addEdge (aid[i], bid[j], 1, c[i][j] * flag);
		}
	}
}

int main () {
	fastread

	cin >> n;

	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}

	Net::clear ();
	buildGraph (1);
	int min_cost = Net::dinic (S, T);
	
	Net::clear ();
	buildGraph (-1);
	int max_cost = -Net::dinic (S, T);

	cout << min_cost << endl;
	cout << max_cost << endl;

	return 0;
}
