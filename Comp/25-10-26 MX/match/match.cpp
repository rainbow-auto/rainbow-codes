#include <bits/stdc++.h>
#define rep(_i, _st, _ed) for (int (_i) = (_st); (_i) <= (_ed); (_i)++)
#define per(_i, _st, _ed) for (int (_i) = (_st); (_i) >= (_ed); (_i)--)
#define file(name) std::freopen(name".in", "r", stdin); std::freopen(name".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
#define db std::cerr
#define dbendl std::cerr << "\n";
#define lookTime db << (1.0 * clock() / CLOCKS_PER_SEC) << "s used\n";
#define dbg(x) db << (#x) << ": " << x << "\n";

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int maxn = 1000005;

int n;
struct Edge {
    int u, v;
    i64 w;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v, int w) {
    es[++cnt] = Edge { u, v, w, last[u] };
    last[u] = cnt;
}

bool c[maxn];

// namespace Task1 {
//     i64 resnow;
//     bool f[maxn];
//     void dfs(int now, int fa) {
//         f[now] = c[now];
//         for (int i = last[now]; i; i = es[i].pre) {
//             int t = es[i].v;
//             if (t == fa) continue;
//             dfs(t, now);
//             f[now] ^= f[t];
//             if (f[t]) resnow += es[i].w;
//         }
//     }
    
//     inline i64 solve() {
//         i64 ans = 1e18;
//         rep (i, 1, n) rep (j, i + 1, n) if (c[i] != c[j]) {
//             std::swap(c[i], c[j]);
//             resnow = 0;
//             dfs(1, 0);
//             ans = std::min(ans, resnow);
//             std::swap(c[i], c[j]);
//         }

//         return ans;
//     }
// }

bool f[maxn];
bool flg[maxn << 1];
i64 g[maxn][2];

namespace Task2 {
    i64 ans0;

    void dfs(int now, int fa) {
        f[now] = c[now];
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) continue;
            dfs(t, now);
            f[now] ^= f[t];
            if (f[t]) {
                flg[i] = true;
                ans0 += es[i].w;
            }
        }
    }

    i64 ans;
    void dfs2(int now, int fa) {
        g[now][c[now]] = 0;
        g[now][c[now] ^ 1] = 1e18;

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) continue;

            dfs2(t, now);

            i64 dt = 0;
            if (flg[i]) dt = -es[i].w;
            else dt = es[i].w;
         
            // db << "now " << now << " | " << t << " " << g[t][0] + dt << ", " << g[t][1] + dt << "\n";
            
            ans = std::min(ans, ans0 + g[now][0] + g[t][1] + dt);
            ans = std::min(ans, ans0 + g[now][1] + g[t][0] + dt);

            g[now][0] = std::min(g[now][0], g[t][0] + dt);
            g[now][1] = std::min(g[now][1], g[t][1] + dt);
        }

        // db << "now " << now << " g: " << g[now][0] << ", " << g[now][1] << "\n";

        ans = std::min(ans, ans0 + g[now][c[now] ^ 1]);
    }

    inline i64 solve() {
        rep (i, 1, cnt) flg[i] = false; 
        ans0 = 0;
        dfs(1, 0);
        ans = ans0;
        dfs2(1, 0);
        return ans;
    }
}

namespace Task3 {
    constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

    i64 ans0, ans1, ans2, ans;

    i64 h[maxn][2];

    void dfs(int now, int fa) {
        f[now] = c[now];
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) continue;
            dfs(t, now);
            f[now] ^= f[t];
            if (f[t]) {
                flg[i] = true;
                ans0 += es[i].w;
            }
        }
    }

    void dfs2(int now, int fa) {
        g[now][c[now]] = 0;
        g[now][c[now] ^ 1] = inf;

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) continue;

            dfs2(t, now);

            i64 dt = 0;
            if (flg[i]) dt = -es[i].w;
            else dt = es[i].w;
         
            h[now][1] = std::min(h[now][1], ans0 + g[now][1] + g[t][1] + dt); // ans2
            h[now][1] = std::min(h[now][1], h[t][1]);
            
            h[now][0] = std::min(h[now][0], ans0 + g[now][0] + g[t][1] + dt); // ans1
            h[now][0] = std::min(h[now][0], ans0 + g[now][1] + g[t][0] + dt); // ans1
            h[now][0] = std::min(h[now][0], h[t][0]);
            
            g[now][0] = std::min(g[now][0], g[t][0] + dt);
            g[now][1] = std::min(g[now][1], g[t][1] + dt);
        }

        if (c[now] == 1) h[now][1] = std::min(h[now][1], ans0 + g[now][1]);
        h[now][0] = std::min(h[now][0], ans0 + g[now][c[now] ^ 1]);
    }

    inline i64 solve() {
        rep (i, 1, cnt) flg[i] = false; 
        
        ans0 = 0;
        dfs(1, 0);
        rep (i, 1, n) h[i][0] = h[i][1] = ans0;

        dfs2(1, 0);
        
        ans = inf;

        // if (c[1] == 1) ans = std::min(ans, h[1][0]);

        // std::array<i64, 2> preg = { (i64) 1e18, (i64) 1e18 };
        // std::array<i64, 2> preh = { (i64) 1e18, (i64) 1e18 };
        
        // for (int i = last[1]; i; i = es[i].pre) {
        //     int t = es[i].v;
        //     ans = std::min(ans, h[t][1] + preg[0]); // 1 1 0
        //     ans = std::min(ans, h[t][0] + preg[1]); // 0 1 1
            
        //     ans = std::min(ans, g[t][1] + preh[0]);
        //     ans = std::min(ans, g[t][0] + preh[1]);

        //     preg[0] = std::min(preg[0], g[t][0]);
        //     preg[1] = std::min(preg[1], g[t][1]);

        //     preh[0] = std::min(preh[0], h[t][0]);
        //     preh[1] = std::min(preh[1], h[t][1]);
        // }

        ans = std::min(ans, h[1][1] + g[1][0]);
        // ans = std::min(ans, h[1][1]);
        ans = std::min(ans, h[1][0] + g[1][1]);
        // ans = std::min(ans, h[1][0]);

        return ans;
    }
}

inline void solve() {
    std::cin >> n;
    bool flg = false;

    rep (i, 1, n) {
        std::cin >> c[i];
        flg ^= c[i];
    }

    rep (i, 1, n - 1) {
        int u, v; std::cin >> u >> v;
        int w; std::cin >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    if (flg and n <= 1000) {
        i64 ans = 1e18;
        rep (i, 1, n) {
            if (c[i]) {
                // db << "del " << i << "\n";
                c[i] = 0;
                ans = std::min(ans, Task2::solve());
                c[i] = 1;
                // db << "---------\n";
            }
        }
        std::cout << ans << "\n";
        return;
    }

    if (not flg) std::cout << Task2::solve() << "\n";
    else std::cout << Task3::solve() << "\n";
}

int main() {
    fastread

    // file("match")
    
    solve();

    lookTime
    return 0;
}