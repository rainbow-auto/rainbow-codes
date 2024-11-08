#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, m;

namespace Task1 {

    const int maxn = 205;

    int dis[maxn][maxn];

    inline void floyd () {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    inline void solve () {
        memset (dis, 0x3f, sizeof (dis));
        for (int i = 1; i <= n; i++) { dis[i][i] = 0; }

        for (int i = 1; i <= m; i++) {
            int u, v, w; cin >> u >> v >> w;

            dis[u][v] = w;
        }

        floyd ();

        for (int i = 2; i <= n; i++) {
            int ans = 0x3f3f3f3f;
            for (int t = 1; t <= n; t++) {
                if (dis[1][t] == 0x3f3f3f3f) { continue; }
                if (dis[i][t] == 0x3f3f3f3f) { continue; }

                ans = min (ans, dis[1][t] + dis[i][t]);
            }

            if (ans == 0x3f3f3f3f) { cout << -1 << " "; }
            else { cout << ans << " "; }
        }
    }
}

namespace Task2 {
    const int maxn = 100005;
    const int maxm = 200005;

    struct Edge {
        int u, v, w;
        int pre;
    } es[maxm];

    int last[maxn], cnt;

    inline void addEdge (int u, int v, int w) {
        es[++cnt] = Edge { u, v, w ,last[u] };
        last[u] = cnt;
    }

    struct Node {
        int id;
        int dis;

        friend bool operator < (Node a, Node b) {
            return a.dis > b.dis;
        }
    };

    int dis[maxn];

    priority_queue<Node> q;
    bool vis[maxn];
    inline void dij () {
        memset (dis, 0x3f, sizeof (dis));
        memset (vis, 0, sizeof (0));

        dis[1] = 0; q.push ({ 1, dis[1] });

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

    inline void solve () {
        
        for (int i = 1; i <= m; i++) {
            int u, v, w; cin >> u >> v >> w;

            addEdge (u, v, w);
            addEdge (v, u, w);
        }

        dij ();

        for (int i = 2; i <= n; i++) {
            if (dis[i] == 0x3f3f3f3f) { cout << -1 << " "; }
            else { cout << dis[i] << " "; }
        }
    }
}

int main () {

    cin >> n >> m;

    if (n <= 200) {
        Task1::solve ();
    } else {
        Task2::solve ();
    }

    return 0;
}
