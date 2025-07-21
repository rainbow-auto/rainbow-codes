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

constexpr int maxn = (1 << 19) + 5;

int k, m, s;
int n;

int a[maxn], b[maxn], c[maxn];

i64 p[maxn];

struct Edge {
    int u, v;
    i64 w;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v, i64 w) {
    es[++cnt] = Edge { u, v, w, last[u] };
    last[u] = cnt;
}

struct Node {
    int id;
    i64 dis;

    friend bool operator < (Node a, Node b) {
        return a.dis > b.dis;
    }
};

std::priority_queue<Node> q;

i64 dis[maxn];
bool vis[maxn];
inline void dij (int S) {
    memset (vis, 0, sizeof (vis));
    memset (dis, 0x3f, sizeof (dis)); dis[S] = 0;
    q.push (Node { S, dis[S] });

    while (not q.empty()) {
        int now = q.top().id; q.pop ();

        if (vis[now]) { continue; }
        vis[now] = true;

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;

            if (dis[t] > dis[now] + es[i].w) {
                dis[t] = dis[now] + es[i].w;
                q.push (Node { t, dis[t] });
            }
        }
    }
}

namespace Task1 {
    int tot;
    int bel[maxn];
    int id[maxn];

    inline void solve() {
        tot = k;
        rep (i, 0, n - 1) bel[i] = (__builtin_popcount(i));
        rep (i, 0, n - 1) id[bel[i]] = i;

        rep (i, 0, k) rep (j, 0, k) {
            if (i != j) addEdge(i, j, p[std::abs(i - j)]);
        }

        tot++;
        rep (j, 0, k) {
            addEdge(bel[s], j, p[std::abs(bel[s] - j)]);
            addEdge(j, bel[s], p[std::abs(bel[s] - j)]);
        }

        dij(bel[s]);

        rep (i, 0, n - 1) {
            if (bel[i] != bel[s]) {
                std::cout << dis[bel[i]] << " ";
            } else {
                std::cout << dis[tot] << " ";
            }
        }
    }
}

namespace Task2 {
    inline void solve() {
        rep (i, 1, m) addEdge(a[i], b[i], c[i]);
        rep (i, 1, m) addEdge(b[i], a[i], c[i]);

        rep (i, 0, n - 1) {
            rep (j, 0, i - 1) {
                addEdge(i, j, p[__builtin_popcount(i ^ j)]);
                addEdge(j, i, p[__builtin_popcount(i ^ j)]);
            }
        }
     
        dij(s);

        rep (i, 0, n - 1) std::cout << dis[i] << " ";
    }
}

void solve() {
    std::cin >> k >> m >> s;
    n = (1 << k);

    p[0] = 0x3f3f3f3f3f3f3f3f; 
    rep (i, 1, k) std::cin >> p[i];
    rep (i, 1, m) {
        std::cin >> a[i] >> b[i] >> c[i];
    }

    // if (m == 0) return Task1::solve(), void(0);
    Task2::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    // file("path")

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
