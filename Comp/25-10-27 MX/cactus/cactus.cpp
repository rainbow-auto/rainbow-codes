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
int a[maxn], p[maxn];

namespace Task1 {
    constexpr int maxn = 6005;

    int f[maxn][maxn];
    int pre[maxn][maxn];
    int suf[maxn][maxn];

    inline void clr() {
        rep (i, 0, n) rep (j, 0, n) pre[i][j] = suf[i][j] = f[i][j] = 0;
    }

    inline void solve() {
        a[0] = -0x3f3f3f3f;

        rep (i, 1, n) {
            rep (j, 0, i - 1) {
                if (a[j] < a[i]) {
                    if (p[i]) {
                        f[i][j] = std::max(f[i][j], pre[j][p[i] - 1] + 1);
                        f[i][j] = std::max(f[i][j], suf[j][p[i] + 1] + 1);
                    } else {
                        f[i][j] = pre[j][n] + 1;
                    }
                }
            }

            pre[i][0] = f[i][0]; rep (j, 1, n) pre[i][j] = std::max(pre[i][j - 1], f[i][j]);
            suf[i][n + 1] = 0; per (j, n, 0) suf[i][j] = std::max(suf[i][j + 1], f[i][j]);
        }

        int res = 0;
        rep (i, 1, n) res = std::max(res, pre[i][n]);
        std::cout << res << "\n";

        clr();
    }
}

inline void solve() {
    std::cin >> n; 
    rep (i, 1, n) std::cin >> a[i];
    rep (i, 1, n) std::cin >> p[i];

    Task1::solve();
}

int main() {
    fastread
//////////////

    file("cactus")

    int _; std::cin >> _;
    while (_--) solve();

    lookTime

    return 0;
}