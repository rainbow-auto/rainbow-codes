#include <iostream>
#include <queue>

const int maxn = 300005;

struct Edge {
    int u, v;
    int pre;
} es[maxn];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

char val[maxn];

int fa[maxn]; // 上一个节点的位置

inline void bfs (int s) {
    std::queue <int> q;
    q.push (s);

    while (not q.empty ()) {
        int u = q.front (); q.pop ();

        std::set <std::pair <char, int>> to;
        for (int i = last[u]; i; i = es[i].pre) {
            int v = es[i].v;
            if (fa[v]) { continue; }
            to.insert ({ val[v], v });
        }

        for (auto it : to) {
            fa[it.second] = u;
            q.push (it.second);
        }
    }
}

int main () {

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) { std::cin >> val[i]; }

    for (int i = 1; i <= m; i++) {
        int u, v; std::cin >> u >> v;
        addEdge (u, v);
    }

    int s, t; std::cin >> s >> t;
    

    return 0;
}