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

const int maxn = 505;
const int maxe = maxn * maxn * 2;

int n, m;

struct Edge {
	int u, v;
	int pre;
	int w;
} es[maxe << 2];

int last[maxe], cnt;

inline void addEdge(int u, int v, int w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

struct Node {
	int id;
	int dis;

	friend bool operator < (Node a, Node b) {
		return a.dis > b.dis;
	}
};

int dis[maxe];
std::bitset<maxe> vis;

inline void dij(int S) {
	std::memset(dis, 0x3f, sizeof dis);
	dis[S] = 0;
	std::priority_queue<Node> q;
	q.push(Node { S, dis[S] });
	vis.reset();

	while (not q.empty()) {
		int now = q.top().id; q.pop();
		if (vis[now]) continue;
		vis.set(now);

		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (dis[t] > dis[now] + es[i].w) {
				dis[t] = dis[now] + es[i].w;
				q.push(Node { t, dis[t] });
			}
 		}
	}
}

int id[maxn][maxn], tot;

void solve() {
	std::cin >> n >> m;
	tot = 0;
	rep (i, 1, n + 1) {
		rep (j, 1, m + 1) {
			id[i][j] = ++tot;
		}
	}

	auto addDoubleEdge = [&](int u, int v, int w) -> void {
		addEdge(u, v, w);
		addEdge(v, u, w);
	};

	rep (i, 1, n) {
		rep (j, 1, m) {
			char c; std::cin >> c;
			if (c == '/') {
				addDoubleEdge(id[i][j + 1], id[i + 1][j], 0);
				addDoubleEdge(id[i][j], id[i + 1][j + 1], 1);
			} else {
				addDoubleEdge(id[i][j + 1], id[i + 1][j], 1);
				addDoubleEdge(id[i][j], id[i + 1][j + 1], 0);
			}
		}
	}

	dij(id[1][1]);

	int res = dis[id[n + 1][m + 1]];
	if (res == 0x3f3f3f3f) std::cout << "NO SOLUTION\n";
	else std::cout << res << "\n";
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
	
	while (_--) {
		solve();
	}

	return 0;
}
