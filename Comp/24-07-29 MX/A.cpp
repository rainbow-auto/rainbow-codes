#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using i64 = long long;

const int maxn = 500005;

int n;

i64 a[maxn];
i64 L, R;

struct Edge {
    int u, v;
    i64 w;
    int pre;
} es[maxn * 13];

int last[maxn], cnt;

inline void addEdge (int u, int v, i64 w) {
    es[++cnt] = Edge { u, v, w, last[u] };
    last[u] = cnt;
}

struct Node {
    int id;
    i64 dis;

    friend bool operator < (Node a, Node b) {
        return a.dis > b.dis;
    }
};

std::priority_queue <Node> q;

i64 dis[maxn];
bool vis[maxn];

inline void dij (int S) {
    memset (dis, 0x3f, sizeof (dis)); dis[S] = 0;
    memset (vis, 0, sizeof (vis)); 
    q.push ( Node { S, dis[S] } );

    while (not q.empty ()) {
        int u = q.top ().id; q.pop ();
        
        if (vis[u]) { continue; }
        vis[u] = true;

        for (int i = last[u]; i; i = es[i].pre) {
            int v = es[i].v;

            if (dis[v] > dis[u] + es[i].w) {
                dis[v] = dis[u] + es[i].w;
                q.push ( Node { v, dis[v] } );
            } 
        }
    }
}

int main () {

    freopen ("inq.in", "r", stdin);
    freopen ("inq.out", "w", stdout);

    std::cin >> n >> L >> R; L--;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    std::sort (a + 1, a + n + 1);

    for (int i = 0; i < a[1]; i++) {
        for (int j = 2; j <= n; j++) {
            addEdge (i, (i + a[j]) % a[1], a[j]);
        }
    }

    dij (0);

    i64 sumL = 0;
    i64 sumR = 0;

    for (int i = 0; i < a[1]; i++) {
        if (dis[i] <= L) { sumL += (L - dis[i]) / a[1] + 1; }
        if (dis[i] <= R) { sumR += (R - dis[i]) / a[1] + 1; }
    }    

    std::cout << sumR - sumL << "\n";

    return 0;
}