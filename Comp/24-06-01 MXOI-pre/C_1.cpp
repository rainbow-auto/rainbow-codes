#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

const int maxn = 5005;
const int maxk = 105;

int n, k;

int g[maxn][maxn];

struct Edge {
    int u, v;
};

std::vector<Edge> es[maxk];
int curr;

// 假的
namespace Policy1 {
    bool vis[maxn];
    void dfs (int now) {
        vis[now] = true;

        for (int t = 1; t <= n; t++) {
            if (g[now][t] == 0) { continue; }
            if (vis[t]) { continue; }

            g[now][t] = 0; g[t][now] = 0;

            es[curr].push_back (Edge { now, t });

            dfs (t);
        }
    }

    inline void init () {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j) { g[i][j] = 1; }
            }
        }
    }

    inline void solve () {
        curr = 0; init ();

        for (int i = 1; i <= k; i++) {
            memset (vis, 0, sizeof (vis));

            ++curr; dfs (1);

            if (es[curr].size () < n - 1) { std::cout << -1 << "\n"; return; }
        }
    }
}


// 假的, 而且没调出来
namespace Policy2 {
    int deg[maxn];
    
    bool vis[maxn];
    void dfs (int now) {
        vis[now] = true;

        std::vector< std::pair<int, int> > ts;

        for (int t = 1; t <= n; t++) {
            if (g[now][t] == 0) { continue; }
            if (vis[t]) { continue; }

            ts.push_back ({ deg[t], t });
        }

        std::sort (ts.begin (), ts.end ());

        for (auto it : ts) {
            int t = it.second;

            g[now][t] = 0; deg[now] --;
            g[t][now] = 0; deg[t] --;

            es[curr].push_back (Edge { now, t });

            dfs (t);
        }

        ts.clear ();
    }

    inline void init () {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j) { g[i][j] = 1; deg[i] ++; }
            }
        }
    }

    inline void solve () {
        curr = 0; init ();

        for (int i = 1; i <= k; i++) {
            memset (vis, 0, sizeof (vis));

            ++curr; dfs (1);

            if (es[curr].size () < n - 1) { std::cout << -1 << "\n"; return; }
        }
    }
}

// 可能是真的
namespace Policy3 {

    inline void init () {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) { continue; }
                g[i][j] = 1;
            }
        }
    }

    // add edge to the answer
    inline void addEdge (int id, int u, int v) {
        g[u][v] = g[v][u] = 0;
        es[id].push_back (Edge { u, v });
    }

    std::vector <int> equiv[maxk];
    bool vis[maxn];

    inline void clear (int step) {
        for (int i = 0; i <= step - 1; i++) { equiv[i].clear (); }
        for (int i = 0; i <= step - 1; i++) { vis[i] = false; }
    }

    inline void solve () {

        int p = (n >> 1);

        if (k > p) { std::cout << -1 << "\n"; exit (0); }

        init ();

        for (int step = 1; step <= std::min (k, p - 1); step ++) {
            clear (step);

            for (int i = 1; i <= n; i++) { equiv[i % step].push_back (i); }

            for (int i = 0; i <= step - 1; i++) {
                int pre = 0;
                for (auto now : equiv[i]) {
                    if (pre) { addEdge (step, now, pre); }
                    pre = now;
                }

                if (i == step - 1) { continue; }
                
                for (int j = 0; j <= step - 1; j++) {
                    if (vis[j]) { continue; }
                    
                    if (i == j) { continue; }

                    if (g[equiv[i].back ()][equiv[j].front ()]) {
                        addEdge (step, equiv[i].back (), equiv[j].front ());
                        vis[i] = true; vis[j] = true;
                        break;
                    }
                }
            }
        }  

        if (k == p) {
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (g[i][j]) { addEdge (p, i, j); }
                }
            }
        }
    }
}

int main () {

    std::cin >> n >> k;

    // Policy1::solve ();
    // Policy2::solve ();
    Policy3::solve ();

    #ifndef ONLINE_JUDGE
    std::cout << n << " " << k << "\n";
    #endif

    for (int i = 1; i <= k; i++) {
        for (auto now : es[i]) {
            std::cout << now.u << " " << now.v << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}