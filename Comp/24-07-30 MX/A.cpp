#include <iostream>

using i64 = long long;

const int maxn = 100005;
const i64 mod = 1e9 + 7;

int n, m;

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt = 1;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

bool vis[maxn];
i64 vcnt, ecnt;
bool visE[maxn];

void dfs (int now) {
    vis[now] = true;
    vcnt ++;
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;

        if (not visE[i]) { ecnt ++; visE[i] = true; visE[i ^ 1] = true; }

        if (vis[t]) { continue; }
        dfs (t);
    }
}

int main () {

    std::cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; std::cin >> u >> v;
        addEdge (u, v);
        addEdge (v, u);
    }

    i64 ans = 1ll;
    for (int i = 1; i <= n; i++) {
        if (not vis[i]) {
            vcnt = ecnt = 0;
            dfs (i);

            if (vcnt == ecnt) { ans = (ans * 2ll) % mod; }
            if (vcnt < ecnt) { ans *= 0; break; }
            if (vcnt > ecnt) { ans = (ans * vcnt % mod) % mod; }
        }
    }

    std::cout << ans % mod << "\n";

    return 0;
}