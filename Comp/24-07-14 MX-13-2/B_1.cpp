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

namespace Task2 {
    
    struct Node {
        int ch[2], fa;
        bool tag;
        i64 val, mx;
    } tr[maxn];

    inline bool notRoot (int now) { return now == tr[tr[now].fa].ch[0] or now == tr[tr[now].fa].ch[1]; }
    
    inline bool chk (int now) { return now == tr[tr[now].fa].ch[1]; }

    inline void pushUp (int now) { tr[now].mx = std::max (tr[now].mx, std::max (tr[tr[now].ch[0]], tr[tr[now].ch[1]])); }

    inline void rev (int now) { std::swap (tr[now].ch[0], tr[now].ch[1]); tr[now].tag ^= 1; }

    inline void pushDown (int now) {
        if (not tr[now].tag) { return; }
        tr[now] = false;
        if (tr[now].ch[0]) { rev (tr[now].ch[0]); }
        if (tr[now].ch[1]) { rev (tr[now].ch[1]); }
    }

    void pushAll (int now) {
        if (notRoot (now)) { pushAll (tr[now].fa); }
        pushDown (now);
    }

    inline void connect (int fa, int t, int p) { tr[fa].ch[p] = t; tr[t].fa = fa; }

    inline void rotate (int now) {
        int f = tr[now].fa; int ff = tr[f].fa;
        int p = chk (now); int pp = chk (f);
        pushDown (f); pushDown (now);

        if (notRoot (f)) { connect (ff, now, pp); }
        connect (f, tr[now].ch[p ^ 1], p);
        connect (now, f, p ^ 1);
        
        pushUp (f); pushUp (now);
    }

    inline void splay (int now) {
        pushAll (now);

        for (; notRoot (now); rotate (x)) {
            if (notRoot (tr[now].fa)) { rotate (chk (tr[now].fa) == chk (now) ? tr[now].fa : now) }
        }

        pushUp (now);
    }

    inline void solve () {
        
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

    // Task1::solve ();
    Task2::solve ();

    return 0;
}