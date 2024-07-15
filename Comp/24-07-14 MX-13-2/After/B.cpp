#include <iostream>
#include <algorithm>
#include <vector>

using i64 = long long;

const int maxn = 5005;

i64 read () {
    i64 res = 0, flag = 1;

    char ch = getchar ();
    while (not isdigit (ch)) { if (ch == '-') { flag = -1ll; } ch = getchar (); }
    while (isdigit (ch)) { res = res * 10ll + ch - '0'; ch = getchar (); }

    return flag * res;
}

int n, q;
i64 x[maxn], y[maxn];

inline i64 abs (i64 t) { return (t > 0ll) ? t : -t; }

inline i64 getval (int i, int j) { 
    i64 xx = abs (x[i] - x[j]);
    i64 yy = abs (y[i] - y[j]);
    return xx * xx * xx + yy * yy * yy;
}

struct Edge {
    int u, v;
    i64 w;

    friend bool operator < (Edge a, Edge b) { return a.w < b.w; }
};

int fa[maxn];

inline void init () {
    for (int i = 1; i <= n; i++) { fa[i] = i; }
}

int find (int x) { return (fa[x] == x) ? fa[x] : (fa[x] = find (fa[x])); }

std::vector <Edge> g[2];
bool curr = true;

inline i64 kruskal (bool flag = false) {
    init ();

    std::sort (g[curr].begin (), g[curr].end ());

    i64 res = 0;
    for (auto e : g[curr]) {
        if ()

        int u = find (e.u);
        int v = find (e.v);

        if (u == v) { continue; }

        fa[u] = v;
        res += e.w;

        g[curr ^ 1].push_back (e);
    }

    g[curr].clear ();

    return res;
}

int main () {

    freopen ("logistics.in", "r", stdin);
    freopen ("logistics.ans", "w", stdout);

    n = read (); q = read ();

    for (int i = 1; i <= n; i++) {
        x[i] = read (); y[i] = read ();
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            g[curr].push_back (Edge { i, j, getval (i, j) });
        }
    }

    std::cout << kruskal () << "\n";
    
    while (q--) {
        curr ^= 1;
        g[curr].push_back (Edge { int (read ()), int (read ()), read () });

        std::cout << kruskal () << "\n";
    }

    return 0;
}