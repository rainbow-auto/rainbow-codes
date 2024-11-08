#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 1000005;

int n;
int col[maxn];

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

int dep[maxn], par[maxn]; // 深度 | 父亲

int fa[maxn];
int find (int x) {
    if (fa[x] == x) { return fa[x]; }
    else { return fa[x] = find (fa[x]); }
}

inline int push (int x) {
    if (col[x] == 0) { fa[x] = x; return 0; }
    
    fa[x] = find (par[x]);
    if (fa[x]) {
        fa[fa[x]] = par[fa[x]];
        return dep[x] - dep[fa[x]];
    }
    return 0;
}

inline int bfs () {
    memset (dep, -1, sizeof (dep)); dep[1] = 1;
    queue<int> q; q.push (1);

    int res = push (1);

    while (not q.empty ()) {
        int now = q.front (); q.pop ();

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (dep[t] != -1) { continue; }

            par[t] = now;
            dep[t] = dep[now] + 1;
            
            q.push (t);

            res += push (t);
        }
    }

    return res;
}

int main () {

    freopen ("wbtree.in", "r", stdin);
    freopen ("wbtree.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) { cin >> col[i]; }

    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        addEdge (u, v);
        addEdge (v, u);
    }

    cout << bfs () << endl;

    return 0;
}