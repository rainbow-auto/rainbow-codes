#include <iostream>

using namespace std;

const int maxn = 15;
const int maxm = 1005;

struct Edge {
    int u, v;
    int pre;
    int w;
} es[maxm];

int last[maxn], cnt;

inline void addEdge (int u, int v, int w) {
    es[++cnt] = Edge {u, v, last[u], w};
    last[u] = cnt;
}

bool vis[maxn];
int dfs (int now) {
    vis[now] = true;
    
    int mx = 0;
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (vis[t]) { continue; }
        
        mx = max (mx, dfs (t) + es[i].w);
    }

    vis[now] = false;
    return mx;
}

int main () {

    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        addEdge (u, v, w);
        addEdge (v, u, w);
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max (mx, dfs (i));
    }
    cout << mx << endl;

    return 0;
}