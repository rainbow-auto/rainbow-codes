#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;
const int maxn = 2005;
const int maxm = 1005 * 1005 * 2;

i64 n, m, X;

struct Node {
    i64 x, y;
} ns[maxn];
int tot;

struct Edge {
    int u, v;
    i64 w;

    friend bool operator < (Edge a, Edge b) { return a.w < b.w; }
};

std::vector <Edge> es;

inline i64 abs (i64 t) { return (t > 0ll) ? t : (-t); }

inline i64 getw (Node a, Node b) {
    return abs (a.x - b.x) + abs (a.y - b.y);
}

namespace Tree {
    struct Edge {
        int u, v;
        i64 w;
        int pre;
    } es[maxm];

    int last[maxn], cnt;

    inline void addEdge (int u, int v, i64 w) {
        es[++cnt] = Edge { u, v, w, last[u] };
        last[u] = cnt;
    }

    int fa[maxn];
    i64 fa_w[maxn];
    void dfs (int now) {
        for (int i = last[now]; i ; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa[now]) { continue; }

            fa[t] = now;
            fa_w[t] = es[i].w;
            dfs (t);
        }
    }

    void init () { fa[2] = 0; dfs (2); }

    inline bool chk (i64 lim) {
        i64 rest = X;

        int now = 1;
        while (fa[now]) {
            if (fa_w[now] > lim) { 
                rest -= fa_w[now] / lim;
                if (fa_w[now] % lim == 0) { rest ++; } // 多减了一个
            } 
            now = fa[now];
        }

        return rest >= 0;
    }
}

namespace Kruskal {
    int fa[maxn];
    inline void init () {
        for (int i = 1; i <= tot; i++) { fa[i] = i; }
    }

    int find (int x) {
        if (fa[x] != x) { return fa[x] = find (fa[x]); }
        else { return x; }
    } 

    inline void kruskal () {
        init ();
        std::sort (es.begin (), es.end ());

        for (auto e : es) {
            int u = find (e.u);
            int v = find (e.v);

            if (u == v) { continue; }

            fa[v] = u;
            Tree::addEdge (u, v, e.w);
            Tree::addEdge (v, u, e.w);
        }

    }
}

int main () {

    freopen ("road.in", "r", stdin);
    freopen ("road.out", "w", stdout);

    std::cin >> n >> m >> X;

    for (int i = 1; i <= m + 2; i++) {
        i64 x, y; std::cin >> x >> y;
        ns[++tot] = Node { x, y };
    }

    for (int i = 1; i <= tot; i++) {
        for (int j = i + 1; j <= tot; j++) {
            es.push_back (Edge { i, j, getw (ns[i], ns[j]) });
        }
    }

    Kruskal::kruskal ();
    Tree::init ();

    // std::cerr << Tree::chk (8419314) << "\n";

    i64 l = 1, r = 1e18;
    i64 res = 0;

    while (l <= r) {
        i64 mid = (l + r) >> 1;

        if (Tree::chk (mid)) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }

    std::cout << res << "\n";

    return 0;
}