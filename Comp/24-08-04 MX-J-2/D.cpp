#include <iostream>

using i64 = long long;

const int maxn = 200005;
const i64 mod = 1e9 + 7;

int n;

i64 dep[maxn];
i64 siz[maxn];

i64 f[maxn]; // f[u] : 以 u 为 lca 的路径的数量
i64 sf[maxn]; // h[u] : \sum \limits_{v \in subtree (u)} f_v
i64 sdf[maxn]; // g[u] : \sum \limits_{v \in subtree (u)} dep_v \cdot f_v

i64 anc[maxn]; // anc[u] : 从 u 到 root 的路径上的 siz 的和
i64 sanc[maxn];

void dfs1 (int now, int fa) {
    siz[now] = 1;
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) { continue; }

        dep[t] = dep[now] + 1;
        dfs1 (t, now);
        siz[now] += siz[t];
    }   
}

void dfs2 (int now, int fa) {
    i64 pre = 0;
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) { continue; }

        dfs2 (t, now);

        f[now] += siz[t] * pre; f[now] %= mod;
        pre += siz[t]; pre %= mod;
    }
}   

void dfs3 (int now, int fa) {
    sf[now] = f[now];
    sdf[now] = dep[now] * f[now];
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) { continue; }

        dfs3 (t);

        sf[now] += sf[t]; sf[now] %= mod;
        sdf[now] += sdf[t]; sdf[now] %= mod;s
    }
}

void dfs4 (int now, int fa) {
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) { continue; }

        anc[t] = anc[now] + siz[t];
        dfs4 (t, now);
    }
}

void dfs5 (int now, int fa) {
    for (int i = last[now]; i; i = es[i].pre) {
        int t = es[i].v;
        if (t == fa) { continue; }
        
        sanc[t] = sanc[now] + anc[now];
        dfs5 (t, now);
    }
}

int main () {

    std::cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; std::cin >> u >> v;
        addEdge (u, v);
        addEdge (v, u);
    }

    dfs1 (1, 0);
    dfs2 (1, 0);
    dfs3 (1, 0);
    dfs4 (1, 0);
    dfs5 (1, 0);

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += sdf[i] + ;
    }

    return 0;
}