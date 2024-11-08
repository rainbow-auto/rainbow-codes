#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;

const int maxn = 100005;

int n, m, q;

const i64 inf = (1ll << 32) + 114514;

struct Edge {
    int u, v;
    i64 w;
}; 

std::vector <Edge> org;

struct Query {
    int u, v;
};

std::vector <Query> qs;

namespace Task0 {

    int fa[maxn];
    inline void init () {
        for (int i = 1; i <= n; i++) { fa[i] = i; }
    }

    int find (int x) {
        if (fa[x] == x) { return fa[x]; }
        else { return fa[x] = find (fa[x]); }
    }

    std::vector <Edge> es;

    inline i64 get (int S) {
        init ();

        int tot = 0;

        i64 res = 0;
        for (int i = 0; i < es.size (); i++) {
            if (not (S & (1 << i))) { continue; }

            auto e = es[i];

            int u = find (e.u);
            int v = find (e.v);

            if (u == v) { return inf; }

            tot ++;

            res |= e.w;
            fa[v] = u;
        }

        return (tot == (n - 1)) ? res : inf;
    }

    inline i64 add (int u, int v) {
        es = org;
        es.push_back (Edge { u, v, 0 });   

        i64 ans = inf;
        for (int S = 0; S < (1 << es.size ()); S++) {
            ans = std::min (ans, get (S));
        }

        return ans;
    }

    inline void solve () {
        for (auto q : qs) {
            std::cout << add (q.u, q.v) << "\n";
        }
    }

}

int main () {

    freopen ("mst.in", "r", stdin);
    freopen ("mst.out", "w", stdout);

    std::cin >> n >> m >> q;

    for (int i = 1; i <= m; i++) {
        int u, v; std::cin >> u >> v;
        i64 w; std::cin >> w;

        org.push_back (Edge { u, v, w });
    }

    while (q--) {
        int u, v; std::cin >> u >> v;
        qs.push_back (Query { u, v });
    }

    Task0::solve ();

    return 0;
}