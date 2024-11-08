#include <iostream>

using i64 = long long;

int id, T;
int n, m;
i64 k;

struct Graph {
    struct GraphEdge {
        int u, v;
        int pre;
    } es[maxn << 1];

    int last[maxn], cnt;

    inline void addEdge (int u, int v, i64 w) {
        es[++cnt] = GraphEdge { u, v, last[u] };
        last[u] = cnt;
    }

    inline void clear () {
        for (int i = 1; i <= n; i++) { last[i] = 0; }
        cnt = 0;
    }
} g;

struct Edge {
    int u, v;
    i64 w;

    bool flag;
    friend bool operator < (Edge a, Edge b) { return a.w > b.w; }
};

std::vector <Edge> es;

namespace Solution {

    std::vector <Edge> circle;

    std::pair <int, int> stk[maxn], spos;
    bool vis[maxn];
    void dfs (int now, int fa, int eid) {
        stk[++spos] = { now, eid };
        vis[now] = true;

        for (int i = g.last[now]; i; i = g.es[i].pre) {
            int t = g.es[i].v;

            if (t == fa) { continue; }

            if (vis[t]) {
                circle.push_back (Edge { es[i].u, es[i].v, es[i].w });
                while (stk[spos].first != t) {
                    circle.push_back (Edge { es[stk[spos].second].u, es[stk[spos].second].v, es[stk[spos].second].w });
                    spos --;
                }
                continue;        
            }

            dfs (t, now, i);
        } 
    }
    
    inline void clear () {
        for (int i = 1; i <= n; i++) { vis[i] = 0; }
        spos = 0;
        circle.clear ();
    }

    inline void solve () {
        dfs (1, 0, 0);


    }
}

int main () {

    std::cin >> id >> T;
    
    while (T--) {
        std::cin >> n >> m >> k;

        for (int i = 1; i <= m; i++) {
            int u, v; i64 w; std::cin >> u >> v >> w;
            g.addEdge (u, v, w);
            g.addEdge (v, u, w);
            es.push_back (Edge { u, v, w });
        }
        
        Solution::solve ();

        es.clear ();
        g.clear ();
        Solution::clear ();
    }

    return 0;
}