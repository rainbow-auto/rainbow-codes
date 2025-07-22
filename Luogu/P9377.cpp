#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxk = 18;
constexpr int maxn = (1 << maxk) + 5;

int n, k, m, s;

i64 a[maxn];

bool vis[maxn];
bool vis0[maxn][maxk][maxk];

std::vector<std::pair<int, i64>> g[maxn];
i64 dis[maxn];

struct Node {
	int id;
	i64 dis;

	friend bool operator < (Node a, Node b) {
		return a.dis > b.dis;
	}
};

void solve() {
	std::cin >> k >> m >> s;

	n = (1 << k);
	rep (i, 1, k) std::cin >> a[i];

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		i64 w; std::cin >> w;
		g[u].emplace_back((int) v, w);
		g[v].emplace_back((int) u, w);
	}

	std::fill_n(dis, n, 1e18); dis[s] = 0;
	std::priority_queue<Node> pq; pq.push(Node{s, dis[s]});

	auto trans = [&](int now, int i, int j, std::queue<std::tuple<int, int, int>> &q) -> void {
		if (vis0[now][i][j]) return;
		vis0[now][i][j] = true;
		q.push(std::tie(now, i, j));
	};

	while (not pq.empty()) {
		int now = pq.top().id; pq.pop();
		if (vis[now]) continue;
		vis[now] = true;

		for (auto [t, w] : g[now]) {
			if (dis[t] > dis[now] + w) {
				dis[t] = dis[now] + w;
				pq.push(Node { t, dis[t] });
			}
		}

		std::queue<std::tuple<int, int, int>> q; 
		trans(now, 0, 0, q);

		while (not q.empty()) {
			auto [cur, i, j] = q.front(); q.pop();
			if (i < k) {
				trans(cur, i + 1, j, q);
				trans(cur ^ (1 << i), i + 1, j + 1, q);
			} else {
				if (dis[cur] > dis[now] + a[j]) {
					dis[cur] = dis[now] + a[j];
					pq.push(Node { cur, dis[now] + a[j] });
				}
			}
		}
	}

	rep (i, 0, n - 1) std::cout << dis[i] << " ";
	std::cout << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

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
