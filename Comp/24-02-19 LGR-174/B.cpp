#include <iostream>
#include <queue>
#include <cstring>

const int maxn = 600005;

int T;

int n, m, k;

struct Edge {
    int u, v;
    int pre;
} es[maxn];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

namespace Subtask2 {
    
    struct Node {
        int id;
        int dis;

        friend bool operator < (Node a, Node b) {
            return a.dis > b.dis;
        }
    };

    int dis[maxn];
    int ans[maxn];
    bool vis[maxn];

    inline bool check () {
        memset (vis, 0, sizeof (vis));
        memset (dis, 0x3f, sizeof (dis)); dis[1] = 0; ans[1] = 1;

        std::priority_queue <Node> q;
        q.push (Node { 1, dis[1] });

        while (not q.empty ()) {
            int u = q.top ().id; q.pop ();

            if (vis[u]) { continue; }
            vis[u] = true;

            for (int i = last[u]; i; i = es[i].pre) {
                int v = es[i].v;
                
                if (dis[v] > dis[u] + 1) {
                    dis[v] = dis[u] + 1;
                    ans[v] = ans[u];
                    q.push (Node { v, dis[v] });
                } else if (dis[v] == dis[u] + 1) {
                    ans[v] += ans[u];
                }
            }
        }

        for (int i = 1; i <= n; i++) { if (ans[i] != 1) { return false; } }
        return true;
    }
    
    inline void solve () {
        if (check ()) {
            std::cout << "Yes\n";
            for (int i = 1; i <= m; i++) { std::cout << "1 "; } std::cout << "\n";
        } else {
            std::cout << "No\n";
        }
    }
}   

namespace Subtask3 {
    inline void solve () {
        std::cout << "Yes\n";
        for (int i = 1; i <= m; i++) { std::cout << "1 "; } std::cout << "\n";
    }
}

bool visEdge[maxn];
bool vis[maxn];

namespace Subtask4 {

    void dfs (int now) {
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (vis[t]) { continue; }
            
            visEdge[i] = true;
            dfs (t);
        }
    }
    
    inline void solve () {
        memset (visEdge , 0, sizeof (visEdge));
        memset (vis, 0, sizeof (vis));
        dfs (1);

        std::cout << "Yes\n";
        for (int i = 1; i <= m; i++) {
            if (visEdge[i]) { std::cout << 1 << " "; }
            else { std::cout << 1e9 << " "; }
        }

        std::cout << "\n";
    }
}

inline void clear () {
    memset (last, 0, sizeof (last));
    cnt = 0;
}

int main () {

    std::cin >> T;
    
    while (T--) {
        clear ();

        std::cin >> n >> m >> k;

        for (int i = 1; i <= m; i++) {
            int u, v; std::cin >> u >> v;
            addEdge (u, v);
        }

        if (m == n - 1) { Subtask3::solve (); }
        else if (k == 1) { Subtask2::solve (); }
        else if (k == 1e9) { Subtask4::solve (); }
        // else if (n <= 5 and m <= 5) { Subtask1::solve (); }
    
    }

    return 0;
}