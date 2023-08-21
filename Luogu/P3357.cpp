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

const int maxn = 1005;
const int maxm = 40005;

namespace Net {
	struct Edge {
		int u, v;
		int pre;
		int flow;
		int cost;
	} es[maxm];

	int S, T;
	int last[maxn], cur[maxn], cnt;

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
		cnt = 1;
	} 

	int dis[maxn];
	bool vis[maxn];

	bool spfa () {
		memset (dis, 0x3f, sizeof(dis));
		memset (vis, 0, sizeof(vis));
		queue<int> q; q.push(S); vis[S] = true; dis[S] = 0;

		while (not q.empty()) {
			int now = q.front(); q.pop ();
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

			int t_flow = dfs (t, min (now_flow, es[i].flow));
			if (t_flow) {
				es[i].flow -= t_flow;
				es[i ^ 1].flow += t_flow;
				now_flow -= t_flow;
				res += t_flow;

				cost += es[i].cost * t_flow;

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
			memcpy (cur, last, sizeof(last));
			max_flow += dfs (S, 0x3f3f3f3f);
		}

		return cost;
	}
}

int n, k;
struct Segment {
	int l, r;
	int len;
} a[maxn];

inline int clac (int x0, int y0, int x1, int y1) { return (int)sqrt((long long)(x1 - x0) * (x1 - x0) + (long long)(y1 - y0) * (y1 - y0)); }

int tot; // 点的数量
int S, T; // 建出来图的源点与汇点

inline void descrete () {
	vector<int> b;
	for (int i = 1; i <= n; i++) { b.push_back (a[i].l); b.push_back(a[i].r); }

	sort (b.begin(), b.end());
	unique (b.begin(), b.end());	
	tot = b.size() + 1;

	for (int i = 1; i <= n; i++) {
		a[i].l = lower_bound (b.begin(), b.end(), a[i].l) - b.begin() + 1;
		a[i].r = lower_bound (b.begin(), b.end(), a[i].r) - b.begin() + 1;
	}
}

inline void buildGraph () {
	S = 0, T = tot + 1;
	Net::addEdge (S, 1, k, 0);
	for (int i = 1; i <= tot; i++) { Net::addEdge (i, i + 1, k, 0); } // 会多出一条从 tot 到 tot + 1 的边, 正好是到汇点的
	for (int i = 1; i <= n; i++) { Net::addEdge (a[i].l, a[i].r, 1, -a[i].len); }
}

int main () {
	fastread
	
	Net::clear ();

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
		int len = clac (x0, y0, x1, y1);

		// 扩域	
		x0 <<= 1; x1 <<= 1;
		if (x0 == x1) { x1 |= 1; }
		else { x0 |= 1; }

		a[i] = Segment { x0, x1, len };
	}

	descrete ();
	buildGraph ();

	int max_cost = - Net::dinic (S, T);

	cout << max_cost << endl;

	return 0;
}
