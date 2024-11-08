#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 200005;

int n, m, k;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int a[maxn];

int dis[2][maxn];
inline void bfs (int S, int id) {
	rep (i, 1, n) { dis[id][i] = 0x3f3f3f3f; } dis[id][S] = 0;
	std::queue <int> q; q.push (S);

	while (not q.empty ()) {
		int now = q.front (); q.pop ();
		
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (dis[id][t] != 0x3f3f3f3f) { continue; }
			q.push (t);
			dis[id][t] = dis[id][now] + 1;
		}
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n >> m >> k;
	rep (i, 1, k) { std::cin >> a[i]; }

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
	}

	bfs (1, 0); bfs (n, 1);

	std::sort (a + 1, a + k + 1, [&](int u, int v) -> bool { return dis[0][u] < dis[0][v]; });

	int ans = 0;
	rep (i, 2, k) { ans = std::max (ans, dis[0][a[i - 1]] + dis[1][a[i]] + 1); }

	ans = std::min (ans, dis[0][n]);

	std::cout << ans << "\n";

	return 0;
}
