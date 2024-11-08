#include <iostream>
#include <cstring>

using i64 = long long;

const int maxn = 100005;

int n, q;
int a[maxn];

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

int x, y;

inline bool check (int now) { return a[now] == x or a[now] == y; }

namespace Subtask1 {
    
    int belong[maxn], tot;
    int siz[maxn];
    
    void dfs (int now) {
        if (belong[now]) { return; }
        if (not check (now)) { return; }

        siz[tot] ++;
        belong[now] = tot;
        for (int i = last[now]; i; i = es[i].pre) {
            int v = es[i].v;

            dfs (v);   
        }
    }

    inline void solve () {
        memset (belong, 0, sizeof (belong));
        memset (siz, 0, sizeof (siz));
        tot = 0;

        for (int i = 1; i <= n; i++) {
            if (belong[i]) { continue; }
            tot ++;
            dfs (i);
        }

        i64 ans = 0;
        for (int i = 1; i <= tot; i++) {
            ans += 1ll * siz[i] * siz[i];
        }

        std::cout << ans << "\n";
    }
}

namespace Subtask2 {
    int cnt[maxn];
    
    inline void init () {
        for (int i = 1; i <= n; i++) { cnt[a[i]] ++; }
    }

    inline void solve () {
        i64 ans;
        if (check (1)) {
            ans = 1ll * (cnt[x] + cnt[y]) * (cnt[x] + cnt[y]);
        } else {
            ans = cnt[x] + cnt[y];
        }
        std::cout << ans << "\n";
    }
}

int main () {

    std::cin >> n >> q;
    
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    bool Subtask2Flag = true;

    for (int i = 2; i <= n; i++) {
        int fa; std::cin >> fa;
        addEdge (i, fa);
        addEdge (fa, i);
        
        Subtask2Flag &= fa == 1;
    }

    if (Subtask2Flag) { Subtask2::init (); }

    for (int i = 1; i <= q; i++) {
        std::cin >> x >> y;
        if (Subtask2Flag) { Subtask2::solve (); }
        else { Subtask1::solve (); }
    }

    return 0;
}
