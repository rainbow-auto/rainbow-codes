#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using i64 = long long;

const int maxn = 1000005;
const i64 mod = 1e9 + 7;

i64 n, m;

i64 p[maxn];

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

i64 siz[maxn];

i64 con[maxn];

void dfs (int now, int fa) {
    siz[now] = 1;
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;

        if (t == fa) { continue; }

        dfs (t, now);
        siz[now] += siz[t];
    }
    con[now] = siz[now] * (n - siz[now]);
}

int main () {

    std::cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int u, v; std::cin >> u >> v;
        addEdge (u, v);
        addEdge (v, u);
    }

    dfs (1, 0);

    std::sort (con + 1, con + n + 1, [] (i64 x, i64 y) { return x > y; });

    std::cin >> m;

    std::priority_queue <i64> q;
    for (int i = 1; i <= m; i++) { i64 x; std::cin >> x; q.push (x); }

    i64 ans = 0;
    while (q.size () >= n) { con[1] = con[1] * q.top () % mod; q.pop (); }

    for (int i = 1; i <= n; i++) {
        if (q.empty ()) { ans = (ans + con[i]) % mod; }
        else { ans = (ans + con[i] * q.top () % mod) % mod; q.pop (); }
    }

    std::cout << ans << "\n";

    return 0;
}