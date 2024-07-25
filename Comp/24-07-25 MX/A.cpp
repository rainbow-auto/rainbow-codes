#include <iostream>

const int maxn = 100005;

using i64 = long long;

int n;

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

i64 val[maxn];

i64 f[maxn];
void dp (int now, int fa) {
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) { continue; }

        dp (t, now);

        if (f[t] > 0) { f[now] += f[t]; }
    }
    f[now] += val[now];
}

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> val[i]; }

    for (int i = 1; i <= n - 1; i++) {
        int u, v; std::cin >> u >> v;
        addEdge (u, v);
        addEdge (v, u);
    }

    dp (1, 0);

    i64 ans = -1e10;
    for (int i = 1; i <= n; i++) { ans = std::max (ans, f[i]); }

    std::cout << ans << "\n";

    return 0;
}