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

const int maxn = 1000005;

int n, m;
i64 A, B;
i64 w[maxn];

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

inline void clear () {
	rep (i, 1, n) { last[i] = 0; }
	cnt = 0;
}

inline i64 calc (int u, int v) {
	i64 d = A - B;
	if (d == 0) { return 0; }
	if (d > 0) { return (w[v] - w[1]) / d; }
	if (d < 0) { return -(w[v] - w[1]) / d; }
}

bool vis[maxn];

struct Node {
	int id;
	i64 dis;

	friend bool operator < (Node x, Node y) {
		return x.dis > y.dis;
	}
};

const i64 inf = 0x3f3f3f3f3f3f3f3f;

i64 f[maxn];
void dij () {
	rep (i, 1, n) { memset (f + i, 0x3f, sizeof (f + i)); vis[i] = false; }
	f[1] = 0;

	std::priority_queue <Node> q;
	q.push(Node { 1, f[1] });

	while (not q.empty ()) {
		int now = q.top ().id; q.pop ();
		if (vis[now]) { continue; }
		vis[now] = true;

		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			i64 d = A - B;
			i64 c = w[t] - w[1];

			i64 curr;
			if (d == 0) {
				curr = (w[t] < w[1] + f[now] * A) ? f[now] + 1 : inf;
			} else if (d > 0) {
				curr = std::max (c / d + (c % d == 0), f[now] + 1);
			} else {
				curr = std::max (c / d - (c % d == 0), f[now] + 1);
			}

			if (f[t] > curr) { 
				f[t] = curr; 
				q.push (Node { t, f[t] });
			}
		}
	}
}

inline void solve () {
	std::cin >> n >> m;
	std::cin >> A >> B;

	clear ();
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
	}

	rep (i, 1, n) { std::cin >> w[i]; }

	dij ();

	std::cout << (f[n] == inf ? -1 : f[n]) << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _; std::cin >> _;
	while (_--) {
		solve ();
	}

	return 0;
}
