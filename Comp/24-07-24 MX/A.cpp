#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 200005;

struct Edge {
    int u, v;
    int w;

    friend bool operator < (Edge a, Edge b) { return a.w < b.w; }
};

std::vector <Edge> es;

int n, m, q;

namespace Solution {

    struct Edge {
        int u, v;
        int pre;
    } es[maxn << 1];

    int last[maxn], cnt;

    inline void addEdge (int u, int v) {
        es[++cnt] = Edge { u, v, last[u] };
        last[u] = cnt;
    }

    struct Set {
        int fa[maxn];
        inline void init () {
            for (int i = 1; i <= n + m; i++) { fa[i] = i; }
        }

        int find (int x) {
            if (fa[x] == x) { return x; }
            else { return fa[x] = find (fa[x]); }
        }
    } st;

    int val[maxn << 1], tot;

    inline void exKruskal () {
        std::sort ((::es).begin (), (::es).end ());
        st.init ();

        tot = n;

        for (auto e : (::es)) {
            int u = st.find (e.u);
            int v = st.find (e.v);

            if (u == v) { continue; }

            val[++tot] = e.w;
            st.fa[u] = st.fa[v] = st.fa[tot] = tot;
        
            addEdge (tot, u); addEdge (tot, v); // 必然从上往下遍历
        }
    }

    int belong[maxn], bcnt;

    int fa[maxn], son[maxn], siz[maxn], dep[maxn];
    void tree_build (int now) {
        belong[now] = bcnt;

        siz[now] = 1;
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa[now]) { continue; }

            fa[t] = now;
            dep[t] = dep[now] + 1;
            tree_build (t);
            siz[now] += siz[t];

            if (siz[t] > siz[son[now]]) { son[now] = t; }
        }
    }

    int dfn[maxn], top[maxn], dpos;
    void tree_decomp (int now, int topnow) {
        dfn[now] = ++dpos;
        top[now] = topnow;

        if (not son[now]) { return; }

        tree_decomp (son[now], topnow);   

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;

            if (t == fa[now]) { continue; }
            if (t == son[now]) { continue; }

            tree_decomp (t, t);
        }
    }

    inline void init_tree () {
        exKruskal ();

        for (int i = 1; i <= tot; i++) {
            if (not belong[i]) {
                bcnt ++;
                tree_build (i);
                tree_decomp (i, i);
            }
        }
    }

    inline int lca (int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = fa[top[u]];
            } else {
                v = fa[top[v]];
            }
        }
        
        return (dep[u] < dep[v]) ? u : v; 
    }

    inline void solve () {
        init_tree ();

        while (q--) {
            int u, v; std::cin >> u >> v;

            if (belong[u] != belong[v]) {
                std::cout << -1 << "\n";
            } else {
                std::cout << val[lca (u, v)] << "\n";
            }
        }
    }
}   

int main () {

    freopen ("package.in", "r", stdin);
    freopen ("package.out", "w", stdout);

    std::cin >> n >> m >> q;

    for (int i = 1; i <= m; i++) {
        int u, v, w; std::cin >> u >> v >> w;
        es.push_back (Edge { u, v, w });
    }

    Solution::solve ();

    return 0;
}