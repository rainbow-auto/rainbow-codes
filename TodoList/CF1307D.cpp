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

struct Graph {
	struct Edge {
		int u, v;
		int w;
		int pre;
	} es[maxn << 1];

	int last[maxn], cnt;

	inline void addEdge (int u, int v, int w = 0) {
		es[++cnt] = Edge { u, v, w, last[u] };
		last[u] = cnt;
	}
} g, tr;

std::bitset <maxn> mark;

int dep[maxn];
void get_dep (int now, int fa) {
	for (int i = tr.last[now]; i; i = tr.es[i].pre) {
		int t = tr.es[i].v;
		if (t == fa) { continue; }
		dep[t] = dep[now] + 1;
		get_dep (t, now);
	}
}

inline upd (std::pair <int, int>& x, int y) {
	x.second = std::min (x.second, y);
	if (x.second < x.first) { std::swap (x.first, x.second); }
} 

int ans = 0;
std::pair <int, int> dfs (int now, int fa) {
	auto mn = std::pair <int, int> { 0x3f3f3f3f, 0x3f3f3f3f };
	if (mark[now]) { upd (mn, dep[now]); }
	for (int i = tr.last[now]; i; i = tr.es[i].pre) {
		int t = tr.es[i].v;
		if (t == fa) { continue; }

		auto t_mn = dfs (t, now);
		upd (mn, t_mn.first);
		upd (mn, t_mn.second);
	}

	if (mn.first != 0x3f3f3f3f and mn.second != 0x3f3f3f3f) {
		ans = std::min (ans, 2 * dep[now] - mn.first - mn.second);
	}
}

int dis[maxn];
void bfs (int S) {
	memset (dis, 0x3f, sizeof (dis)); dis[S] = 0; 
	std::queue <int> q; q.push (S);

	while (not q.empty ()) {
		int now = q.front (); q.pop ();

		for (int i = g.last[now]; i; i = g.es[i].pre) {
			int t = g.es[i].v;
			if (dis[t] != 0x3f3f3f3f) { continue; }

			dis[t] = dis[now] + 1;
			q.push (t);
	
			tr.addEdge (now, t);
		}
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n >> m >> k;
	rep (i, 1, k) { int x; std::cin >> x; mark[x] = true; }

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		g.addEdge (u, v, 1);
		g.addEdge (v, u, 1);
	}

	bfs (1);

	get_dep (1, 0);

	ans = 0x3f3f3f3f;
	dfs (1, 0);

	std::cout << dis[n] - ans << "\n";

	return 0;
}
