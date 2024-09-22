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

const int maxn = 800005;

int n, m, k;

struct Edge {
    int u, v;
    i64 w;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v, i64 w) {
    es[++cnt] = Edge { u, v, w, last[u] };
    last[u] = cnt;
}

inline void clear () { 
    rep (i, 1, n << 1) { last[i] = 0; }
    cnt = 0;
}

struct Node {
    int id;
    i64 dis;

    friend bool operator < (Node x, Node y) { return x.dis > y.dis; }
};

i64 dis[2][maxn];
inline void dij (int S, int id) {
    rep (i, 1, n << 1) { dis[id][i] = 1e14; }
    dis[id][S] = 0;

    std::bitset <maxn> vis;
    std::priority_queue <Node> q;
    q.push ({ S, dis[id][S] });

    while (not q.empty ()) {
        int now = q.top ().id; q.pop ();

        if (vis[now]) { continue; }
        vis.set (now);

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;

            if (dis[id][t] > dis[id][now] + es[i].w) {
                dis[id][t] = dis[id][now] + es[i].w;
                q.push (Node { t, dis[id][t] });
            }
        }
    }
}

inline void solve () {
    std::cin >> n >> m >> k;

    std::set <int> ps;
    rep (i, 1, k) { int x; std::cin >> x; ps.insert (x); }

    rep (i, 1, m) {
        int u, v; std::cin >> u >> v;
        i64 w; std::cin >> w;
        addEdge (u, v, w);
        addEdge (v, u, w);
        addEdge (u + n, v + n, w >> 1);
        addEdge (v + n, u + n, w >> 1);
    }

    for (auto x : ps) {
        addEdge (x, x + n, 0);
    }

    dij (1, 0);
    dij (n, 1);

    i64 ans = 1e14;
    rep (i, 1, n) {
        ans = std::min (ans, std::max (dis[0][i], dis[1][i + n]));
        ans = std::min (ans, std::max (dis[0][i + n], dis[1][i]));
        ans = std::min (ans, std::max (dis[0][i], dis[1][i]));
        ans = std::min (ans, std::max (dis[0][i + n], dis[1][i + n]));
    }

    if (ans == 1e14) { std::cout << "-1\n"; }
    else { std::cout << ans << "\n"; }

    clear ();    
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve ();
	}

	return 0;
}
