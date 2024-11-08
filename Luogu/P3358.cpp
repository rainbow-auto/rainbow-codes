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
#include <unordered_map>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 1005;
const int maxm = 502010;

namespace Net {
	struct Edge {
		int u, v, pre;
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
		queue<int> q; q.push(S); vis[S] = true; dis[S] = 0;

		while (not q.empty()) {
			int now = q.front(); q.pop(); vis[now] = false;

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

/* 
神秘写法 遇到了未知问题 -> 10 pts
int tot = 0;
inline int newNode () { return ++tot; }

struct Segment {
	int l, r;
	int len;

	int x, y; // 两个点

	friend bool operator < (Segment a, Segment b) {
		if (a.l != b.l) { return a.l < b.l; }
		else { return a.r < b.r; }
	}
} a[maxn];

bool check (Segment x, Segment y) {
	if (x.r > y.l) { return true; }
	else { return false; };
}

int S, SS, T;
inline void buildGraph () {
	S = newNode(), T = newNode(), SS = newNode();
	Net::addEdge (SS, S, k, 0);

	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (check (a[i], a[j])) { Net::addEdge (a[i].y, a[j].x, 1, 0); }
		}
	}

	for (int i = 1; i <= n; i++) { Net::addEdge (S, a[i].x, 1, 0); }
	for (int i = 1; i <= n; i++) { Net::addEdge (a[i].y, T, 1, 0); }

	for (int i = 1; i <= n; i++) { Net::addEdge (a[i].x, a[i].y, 1, -a[i].len); }
}
*/

struct Segment {
	int l, r;
	int len;
} a[maxn];

int tot; // 点的数量
int S, T;

inline void descrete () {
	vector<int> b;
	for (int i = 1; i <= n; i++) { b.push_back (a[i].l); b.push_back (a[i].r); }
	
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
	for (int i = 1; i <= tot; i++) { Net::addEdge (i, i + 1, k, 0); }
	for (int i = 1; i <= n; i++) { Net::addEdge (a[i].l, a[i].r, 1, -a[i].len); }
}

signed main () {
	fastread
	
	Net::clear ();

	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		int l, r; cin >> l >> r; 
		a[i] = Segment { l, r, r - l };
	}	

	descrete ();
	
	buildGraph ();

	int max_cost = -Net::dinic(S, T); // 费用流

	cout << max_cost << endl;

	return 0;
}
