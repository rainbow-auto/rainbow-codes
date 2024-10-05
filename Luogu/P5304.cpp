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

const int maxn = 500005;

int n, m, k;
int p[maxn];

struct Graph {
	struct Edge {
		int u, v;
		int pre;
		i64 w;
	} es[maxn];

	int last[maxn], cnt;

	void addEdge(int u, int v, i64 w) {
		es[++cnt] = Edge { u, v, last[u], w };
		last[u] = cnt;
	}

	i64 dis[maxn];
	int col[maxn];

	struct Node {
		int id;
		i64 dis;

		friend bool operator < (Node a, Node b) {
			return a.dis > b.dis;
		}
	};

	void dij() {
		std::priority_queue<Node> q;
		rep (i, 1, n) memset(dis + i, 0x3f, sizeof dis[i]);
		
		rep (i, 1, k) {
			int cur = p[i];
			col[cur] = cur; dis[cur] = 0; 
			q.push(Node { cur, dis[cur] });
		}

		std::bitset<maxn> vis;

		while (not q.empty()) {
			int now = q.top().id; q.pop();
			if (vis[now]) continue;
			vis.set(now);

			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				if (dis[t] > dis[now] + es[i].w) {
					dis[t] = dis[now] + es[i].w;
					col[t] = col[now];
					q.push(Node { t, dis[t] });
				}
			}
		}
	}

	void clear() {
		rep (i, 1, n) last[i] = col[i] = dis[i] = 0;
		cnt = 0;
	}

} g, rg;

void solve() {
	std::cin >> n >> m >> k;
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		i64 w; std::cin >> w;
		g.addEdge(u, v, w); rg.addEdge(v, u, w);
	}

	rep (i, 1, k) std::cin >> p[i];

	g.dij(); rg.dij();

	i64 ans; std::memset(&ans, 0x3f, sizeof ans);

	rep (i, 1, g.cnt) {
		auto cur = g.es[i];
		if (g.col[cur.u] == rg.col[cur.v]) continue;
		ans = std::min(ans, g.dis[cur.u] + cur.w + rg.dis[cur.v]);
		// g.dis  : 到达 cur.u 的最近的关键点
		// rg.dis : 从 cur.u 出发的最近的关键点
	}

	std::cout << ans << "\n";

	g.clear(); rg.clear();
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
