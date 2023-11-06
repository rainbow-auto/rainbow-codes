#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 205;

int n;

namespace Task1 {
    
    const int maxm = 40005;

    struct Edge {
        int u, v;
        long long w;
        int pre; 
    } es[maxm];

    int last[maxn], cnt;

    inline void addEdge (int u, int v, long long w) {
        // cout << u << " " << v << " " << w << endl;

        es[++cnt] = Edge {u, v, w, last[u]};
        last[u] = cnt;
    }

    struct Node {
        int id;
        long long dis;

        friend bool operator < (Node a, Node b) {
            return a.dis > b.dis;
        } 
    };

    bool vis[maxn];
    long long dis[maxn];
    long long dij (int S, int T) {
        memset (vis, 0, sizeof (vis));
        memset (dis, 0x3f, sizeof (dis));

        priority_queue<Node> q;

        dis[S] = 0; q.push (Node { S, dis[S] });

        while (not q.empty ()) {
            int now = q.top ().id; q.pop ();

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

        return dis[T]; 
    }

    vector<int> chosen;
    inline void display () {
        for (auto now : chosen) { cout << now << " "; } cout << endl;
    }

    long long ans = 0x3f3f3f3f3f3f3f3f;
    
    int mindis = 0x3f3f3f3f, mink;

    bool dfsvis[maxn];
    void dfs (int now, long long nowdis) {
        if (now == n) { int res = dij (n, 1); ans = min (ans, nowdis + res); return; }

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            
            if (dfsvis[t]) { continue; }
            
            dfsvis[t] = true;
            long long old_w = es[i].w; es[i].w = 0;

            chosen.push_back (t);

            dfs (t, nowdis + old_w);

            chosen.pop_back ();

            es[i].w = old_w;
            dfsvis[t] = false;
        }
    }
    
    void solve () {
        for (int i = 1; i <= n; i++) { 
            for (int j = 1; j <= n; j++) {
                int w; cin >> w;
                if (w) { addEdge (i, j, w); }
            }
        }
        memset (vis, 0, sizeof (vis));
        dfs (1, 0ll);

        cout << ans << endl;

    }
}

namespace Solution {

    long long dis[maxn][maxn];
    const long long inf = 0x3f3f3f3f3f3f3f3f;

    inline void floydInit () {
        memset (dis, 0x3f, sizeof (dis));
        for (int i = 1; i <= n; i++) { dis[i][i] = 0; }
    }

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
        floydInit ();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int now; cin >> now;

                if (not now) { continue; }

                cout << i << " " << j << " " << now << endl;

                dis[i][j] = now;
            }
        }

        floyd ();

        long long ans = dis[1][n] + dis[n][1];
        cout << ans << endl;
    }
}

int main () {

    cin >> n;

    Task1::solve ();
    
    // Solution::solve ();

    // cout << Solution::dis[1][n] << endl;

    return 0;
}
