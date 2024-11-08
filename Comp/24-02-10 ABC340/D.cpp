#include <iostream>
#include <queue>
#include <cstring>

using i64 = long long;

const int maxn = 400005;

int n;
i64 a[maxn], b[maxn], x[maxn];

i64 dis[maxn];

struct Edge {
    int u, v;
    i64 w;
    int pre;
} es[maxn];

int last[maxn], cnt;

inline void addEdge (int u, int v, i64 w) {
    es[++cnt] = Edge { u, v, w, last[u] };
    last[u] = cnt;
}

struct Node {
    i64 dis;
    int id;

    friend bool operator < (Node a, Node b) {
        return a.dis > b.dis;
    }
};
std::priority_queue <Node> q;

bool vis[maxn];

i64 dij () {
    memset (vis, 0, sizeof (vis));
    memset (dis, 0x3f, sizeof (dis));
    dis[1] = 0;
    q.push (Node { dis[1], 1 });

    while (not q.empty ()) {
        int u = q.top ().id; q.pop ();
        if (vis[u]) { continue; }
        vis[u] = true;

        for (int i = last[u]; i; i = es[i].pre) {
            int v = es[i].v;

            if (dis[v] > dis[u] + es[i].w) {
                dis[v] = dis[u] + es[i].w;
                q.push (Node { dis[v], v });
            }
        }
    }

    return dis[n];
}

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> a[i] >> b[i] >> x[i]; }

    for (int i = 1; i <= n; i++) {
        addEdge (i, i + 1, a[i]);   
        addEdge (i, x[i], b[i]);
    }

    std::cout << dij () << "\n";

    return 0;
}