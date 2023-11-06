#include <iostream>
#include <cstring>
#include <queue>

#define endl "\n"

using namespace std;

const int maxn = 1000005;

inline void read (int &x) {
    x = 0;
    char ch = getchar ();
    int flag = 1;
    while (not isdigit (ch)) { if (ch == '-') { flag = -1; } ch = getchar (); }
    while (isdigit (ch)) { x = x * 10 + ch - '0'; ch = getchar (); }
    x *= flag;
}

int n, m, q;
int a[maxn];

namespace Task1 {

    const int maxn = 2005;
    const int maxm = maxn * maxn + 5;

    struct Edge {
        int u, v;
        int pre;
        int w;
    } es[maxm];

    int last[maxn], cnt;

    inline void addEdge (int u, int v, int w) {
        es[++cnt] = Edge { u, v, last[u], w };
        last[u] = cnt;
    }

    struct Node {
        int id;
        int dis;

        friend bool operator < (Node a, Node b) {
            return a.dis > b.dis;
        }
    };

    priority_queue<Node> q;
    int dis[maxn];
    bool vis[maxn];

    inline int dij (int S, int T) {
        memset (vis, 0, sizeof (vis));
        memset (dis, 0x3f, sizeof (dis)); dis[S] = 0;
        q.push ( Node { S, dis[S] } );

        while (not q.empty ()) {
            int now = q.top ().id; q.pop ();

            if (vis[now]) { continue; }
            vis[now] = true;

            for (int i = last[now]; i; i = es[i].pre) {
                int t = es[i].v;
                
                if (dis[t] > dis[now] + es[i].w) {
                    dis[t] = dis[now] + es[i].w;
                    q.push ( Node { t, dis[t] } );
                }
            }   
        }

        return dis[T];
    }

    inline void buildGraph () {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i] & a[j]) {
                    addEdge (i, j, a[i] + a[j]);
                }
            }
        }
    }

    void solve () {
        
        buildGraph ();

        while (::q--) {
            int S, T; read (S); read (T);

            if (S == T) { cout << 2 * a[S] << endl; continue; }

            int res = dij (S, T);
            cout << (res == 0x3f3f3f3f ? -1 : res) << endl;
        }
    }

}

int main () {

    freopen ("andgraph.in", "r", stdin);
    freopen ("andgraph.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie (0); cout.tie (0);

    read (n); read (m); read (q);

    for (int i = 1; i <= n; i++) { read (a[i]); }

    Task1::solve ();

    return 0;
}
    