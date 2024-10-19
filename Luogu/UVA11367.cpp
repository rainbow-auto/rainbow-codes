#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 1005;
const int maxf = 105;
const int maxm = 10005;

int n, m;
int p[maxn];

struct Edge {
	int u, v;
	int pre;
	int w;
} es[maxm << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v, int w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

struct Node {
	int id;
	int cost;
	int rst;

	friend bool operator < (Node a, Node b) {
		return a.cost > b.cost;
	}
};

int dis[maxn][maxf];
bool vis[maxn][maxf];

inline int dij(int c, int st, int ed) {
	std::memset(vis, 0, sizeof vis);

	std::memset(dis, 0x3f, sizeof dis);
	dis[st][0] = 0;

	std::priority_queue<Node> q;
	q.push(Node { st, dis[st][0], 0 });

	while (not q.empty()) {
		int now = q.top().id;
		int rst = q.top().rst;
		int cost = q.top().cost;
		q.pop();

		if (now == ed) return cost;

		if (vis[now][rst]) continue;
		vis[now][rst] = true;

		if (rst + 1 <= c) {
			if (dis[now][rst + 1] > cost + p[now]) {
				dis[now][rst + 1] = cost + p[now];
				q.push(Node { now, cost + p[now], rst + 1 });
			}
		}

		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (rst - es[i].w < 0) continue;

			if (dis[t][rst - es[i].w] > cost) {
				dis[t][rst - es[i].w] = cost;
				q.push(Node { t, cost, rst - es[i].w });
			}
		}
	}

	return -1;
}

void solve() {
	rep (i, 1, n) std::cin >> p[i];

	rep (i, 1, m) {
		int u, v, w; std::cin >> u >> v >> w;
		u++; v++;
		addEdge(u, v, w); addEdge(v, u, w);
	}

	int q; std::cin >> q;
	while (q--) {
		int c, st, ed; std::cin >> c >> st >> ed;
		st ++; ed ++;
		int res = dij(c, st, ed);
		if (~res) std::cout << res << "\n";
		else std::cout << "impossible\n"; 
	}
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (std::cin >> n >> m) {
		solve();
	}

	return 0;
}
