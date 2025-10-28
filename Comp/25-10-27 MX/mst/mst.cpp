#include <bits/stdc++.h>
#define rep(_i, _st, _ed) for (int (_i) = (_st); (_i) <= (_ed); (_i)++)
#define per(_i, _st, _ed) for (int (_i) = (_st); (_i) >= (_ed); (_i)--)
#define db std::cerr
#define dbendl std::cerr << "\n"
#define dbg(x) std::cerr << (#x) << ": " << x << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s used\n";

using i64 = long long;
using u64 = unsigned long long;
using f64 = double;

constexpr int maxn = 200005;

int n;

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

namespace Sol {
    int f[maxn];
    int mx;

    void dfs(int now, int fa, bool col) {
        f[now] = 0;
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) continue;
            dfs(t, now, col ^ 1);
            mx = std::max(mx, f[now] + f[t] + 1);
            f[now] = std::max(f[now], f[t] + 1);
        }
    }

    inline void clr() {
        std::memset(f, 0, sizeof f);
        std::memset(last, 0, sizeof last);
        cnt = 0;
        mx = 0;
    }

    inline void solve() {
        dfs(1, 0, 1);
        if (mx < 3) return std::cout << "-1\n", void(0);
        // std::cout << 2 * ((g[0] - 1) + (g[1] - 1)) + 3 << "\n";
        // g[0] + g[1] = n
        std::cout << 2 * n - 1 << "\n";
    }
}

inline void solve() {
    std::cin >> n;
    rep (i, 1, n - 1) {
        int u, v; std::cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    if (n == 1) return std::cout << "0\n", void(0);
    Sol::solve();
    Sol::clr();
}

int main() {
    fastread
    //////////////

    // file("mst")

    int _; std::cin >> _;
    while (_--) {
        solve();
    }

    lookTime

    return 0;
}