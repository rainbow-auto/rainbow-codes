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

// constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
constexpr i64 inf = 1e18;

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
        g[now][c[now] ^ 1] = inf;

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) continue;

            dfs2(t, now);

            i64 dt = 0;
            if (flg[i]) dt = -es[i].w;
            else dt = es[i].w;
         
            ans = std::min(ans, ans0 + g[now][0] + g[t][1] + dt);
            ans = std::min(ans, ans0 + g[now][1] + g[t][0] + dt);

            g[now][0] = std::min(g[now][0], g[t][0] + dt);
            g[now][1] = std::min(g[now][1], g[t][1] + dt);
        }

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
                ans0 += es[i].w;
                es[i].w *= -1;
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

            h[now][1] = std::min(h[now][1], ans0 + g[now][1] + g[t][1] + es[i].w); // ans2
            h[now][1] = std::min(h[now][1], h[t][1]);
            
            h[now][0] = std::min(h[now][0], ans0 + g[now][0] + g[t][1] + es[i].w); // ans1
            h[now][0] = std::min(h[now][0], ans0 + g[now][1] + g[t][0] + es[i].w); // ans1
            h[now][0] = std::min(h[now][0], h[t][0]);
            
            g[now][0] = std::min(g[now][0], g[t][0] + es[i].w);
            g[now][1] = std::min(g[now][1], g[t][1] + es[i].w);
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

        if (c[1] == 1) ans = std::min(ans, h[1][0]);

        std::array<i64, 2> preg = { inf, inf };
        std::array<i64, 2> preh = { inf, inf };
        
        for (int i = last[1]; i; i = es[i].pre) {
            int t = es[i].v;
            ans = std::min(ans, h[t][1] + preg[0]); // 1 1 0
            // db << "110: " << h[t][1] + preg[0] << "\n";
            
            ans = std::min(ans, h[t][0] + preg[1]); // 0 1 1
            // db << "011: " << h[t][0] + preg[1] << "\n"; 
            
            ans = std::min(ans, g[t][1] + es[i].w + preh[0]);
            ans = std::min(ans, g[t][0] + es[i].w + preh[1]);
            // db << "011: " << h[t][0] + preg[1] << "\n"; 
            // db << "110: " << h[t][1] + preg[0] << "\n";

            // db << "\n";

            preg[0] = std::min(preg[0], g[t][0] + es[i].w);
            preg[1] = std::min(preg[1], g[t][1] + es[i].w);

            preh[0] = std::min(preh[0], h[t][0]);
            preh[1] = std::min(preh[1], h[t][1]);
        }

        ans = std::min(ans, h[1][1] + g[1][0]);

        return ans;
    }
}

namespace Sol {
    i64 ans0;

    void dfs(int now, int fa) {
        f[now] = c[now];
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) continue;
            dfs(t, now);
            f[now] ^= f[t];
            if (f[t]) {
                ans0 += es[i].w;
                es[i].w *= -1;
            }
        }
    }

    i64 ans;
    i64 g[maxn][3][2]; // u 1 0
    i64 h[3][2];

    inline bool chkmin(i64 &x, i64 y) {
        return (x > y) ? ((x = y), true) : false;
    }

    void dfs2(int now, int fa) {
        rep (c1, 0, 2) rep (c0, 0, 1) g[now][c1][c0] = inf;
        if (c[now]) g[now][1][0] = 0;
        else g[now][0][1] = 0;
        g[now][0][0] = 0;

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) continue;

            dfs2(t, now);

            rep (c1, 0, 2) rep (c0, 0, 1) h[c1][c0] = g[now][c1][c0];

            rep (cp1, 0, 2) rep (cp0, 0, 1) {
                rep (c1, 0, 2) rep (c0, 0, 1) {
                    if (cp1 + c1 <= 2 and cp0 + c0 <= 1) {
                        chkmin(g[now][cp1 + c1][cp0 + c0], h[cp1][cp0] + g[t][c1][c0] + (((c0 + c1) & 1) ? es[i].w : 0));
                    }
                }
            }
        }

        // dbg(now);
        // rep (c1, 0, 2) rep (c0, 0, 1) db << "(" << c1 << ", " << c0 << " | " << g[now][c1][c0] << ")\n";
        // dbendl;
    }

    inline i64 solve() {
        rep (i, 1, cnt) flg[i] = false; 
        ans0 = 0;
        dfs(1, 0);
        ans = ans0;
        dfs2(1, 0);

        ans = std::min(ans, ans0 + g[1][2][1]);
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

    if (not flg) std::cout << Task2::solve() << "\n";
    else std::cout << Sol::solve() << "\n";
}

int main() {
    fastread

    // file("match4")
    
    solve();

    lookTime
    return 0;
}