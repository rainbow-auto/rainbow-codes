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

const int maxn = 2000005;

int n, m;

struct Edge {
	int u, v;
	int w;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v, int w) {
	es[++cnt] = Edge { u, v, w, last[u] };
	last[u] = cnt;
}

struct Point {
	int x, y;
	int id;
} a[maxn];

int tot;

struct Node {
	int id;
	int dis;

	friend bool operator < (Node a, Node b) { return a.dis > b.dis; }
};

int dis[maxn];
std::bitset <maxn> vis;
inline void dij (int S) {
	vis.reset ();
	memset (dis, 0x3f, sizeof (dis)); dis[S] = 0;
	std::priority_queue <Node> q; q.push (Node { S, dis[S] });
	
	while (not q.empty ()) {
		int now = q.top ().id; q.pop ();
		if (vis[now]) { continue; }
		vis.set (now);

		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (dis[t] > dis[now] + es[i].w) {
				dis[t] = dis[now] + es[i].w;
				q.push (Node { t, dis[t] });
			}
		}
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n >> m;
	rep (i, 1, m + 2) { int id = ++tot; std::cin >> a[id].x >> a[id].y; a[i].id = id; }

	int S = a[m + 1].id; 
	int T = a[m + 2].id;

	std::sort (a + 1, a + tot + 1, [](Point a, Point b) -> bool { if (a.x != b.x) { return a.x < b.x; } else { return a.y < b.y; } });
	rep (i, 2, tot) {
		if (a[i].x == a[i - 1].x) {
			int u = a[i].id;
			int v = a[i - 1].id;
			int w = ((a[i].y - a[i - 1].y) << 1);
			addEdge (u, v, w);
			addEdge (v, u, w);
		}
	}

	std::sort (a + 1, a + tot + 1, [](Point a, Point b) -> bool { if (a.y != b.y) { return a.y < b.y; } else { return a.x < b.x; } } );
	rep (i, 2, tot) {
		if (a[i].y == a[i - 1].y) {
			int u = a[i].id;
			int v = a[i - 1].id;
			int w = ((a[i].x - a[i - 1].x) << 1);
			addEdge (u + tot, v + tot, w);
			addEdge (v + tot, u + tot, w);
		}
	}

	rep (i, 1, m) { addEdge (i, i + tot, 1); addEdge (i + tot, i, 1); }

	addEdge (S, S + tot, 0); addEdge (S + tot, S, 0);
	addEdge (T, T + tot, 0); addEdge (T + tot, T, 0);

	dij (S);

	if (dis[T] == 0x3f3f3f3f) { std::cout << "-1\n"; }
	else { std::cout << dis[T] << "\n"; }

	return 0;
}
