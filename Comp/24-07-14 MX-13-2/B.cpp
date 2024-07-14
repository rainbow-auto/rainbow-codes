#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;

const int maxn = 3005;

int n, q;

struct Query {
    int u, v;
    i64 w;
};

std::vector<Query> qs;

i64 x[maxn], y[maxn];

inline i64 abs (i64 t) { return (t > 0) ? t : -t; }

inline i64 get_w (int u, int v) {
    return abs (x[u] - x[v]) * abs (x[u] - x[v]) * abs (x[u] - x[v]) + abs (y[u] - y[v]) * abs (y[u] - y[v]) * abs (y[u] - y[v]);
}

namespace Task1 {

    struct Edge {
        int u, v;
        i64 w;

        friend bool operator < (Edge x, Edge y) { return x.w < y.w; }
    };
    std::vector <Edge> es; 

    int fa[maxn];
    int find (int x) { return (fa[x] == x) ? fa[x] : (fa[x] = find (fa[x])); }

    inline void init () {
        for (int i = 1; i <= n; i++) { fa[i] = i; }
    }

    inline i64 kruskal () {
        init ();

        std::sort (es.begin (), es.end ());

        i64 res = 0;

        for (auto e : es) {
            int u = find (e.u);
            int v = find (e.v);

            if (u == v) { continue; }

            fa[u] = v;
            res += e.w;
        }

        return res;
    }

    inline void solve () {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                es.push_back (Edge { i, j, get_w (i, j) });
            }
        }   

        std::cout << kruskal () << "\n";
    
        for (auto now : qs) {
            es.push_back (Edge { now.u, now.v, now.w });
            std::cout << kruskal () << "\n";
        }
    }
}

int main () {

    freopen ("logistics.in", "r", stdin);
    freopen ("logistics.ans", "w", stdout);

    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) { std::cin >> x[i] >> y[i]; }

    while (q--) {
        int u, v; i64 c; std::cin >> u >> v >> c;
        qs.push_back (Query { u, v, c });
    }

    Task1::solve ();

    return 0;
}