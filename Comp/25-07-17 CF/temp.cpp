#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 300005;
int f[N][20], dep[N], edge_w[N], dis[N];
struct Edge {
    int to, w;
};
vector<Edge> _G[N];
vector<Edge> G[N];
int n, m;
int u[N], v[N], lca_[N], len[N];
int cnt[N], cf[N];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; i < 20; ++i) {
        f[u][i] = f[f[u][i-1]][i-1];
    }
   // for (auto &e : G[u]) 
    for(int i = 0; i <G[u].size(); ++i) 
    {
        Edge e = G[u][i];
        edge_w[e.to] = e.w;
        dis[e.to] = dis[u] + e.w;
        dfs(e.to, u);
    }
}

int get_lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 19; i >= 0; --i) {
        if (dep[f[x][i]] >= dep[y]) {
            x = f[x][i];
        }
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

void dfs_sum(int u, int fa) {
    for (int i = 0; i <G[u].size(); ++i) 
    {
        Edge e = G[u][i];
        dfs_sum(e.to, u);
        cf[u] += cf[e.to];
    }
}

bool check(int mid) {
    memset(cf, 0, sizeof(cf));
    int total = 0, max_reduce = 0;
    
    for (int i = 1; i <= m; ++i) {
        if (len[i] > mid) {
            total++;
            max_reduce = max(max_reduce, len[i] - mid);
            cf[u[i]]++;
            cf[v[i]]++;
            cf[lca_[i]] -= 2;
        }
    }
    
    if (total == 0) return true;
    
    dfs_sum(1, 0);
    
    for (int i = 2; i <= n; ++i) {
        if (cf[i] == total && edge_w[i] >= max_reduce) {
            return true;
        }
    }
    return false;
}

void _dfs(int now, int fa) {
    for (auto t : _G[now]) {
        if (t.to == fa) continue;
        G[now].push_back({t.to, t.w});
        _dfs(t.to, now);
    }
}

int main() {
    n = read(), m = read();
    for (int i = 1; i < n; ++i) {
        int a = read(), b = read(), t = read();
        _G[a].pb({b, t});
        _G[b].pb({a, t});
    }
    
    _dfs(1, 0);

    dfs(1, 0);
    
    int max_len = 0;
    for (int i = 1; i <= m; ++i) {
        u[i] = read(), v[i] = read();
        lca_[i] = get_lca(u[i], v[i]);
        len[i] = dis[u[i]] + dis[v[i]] - 2 * dis[lca_[i]];
        max_len = max(max_len, len[i]);
    }
    
    int l = 0, r = max_len;
    int ans = max_len;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}