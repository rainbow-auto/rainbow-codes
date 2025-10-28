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

constexpr int maxn = 155;

int n;
int a[maxn];

namespace Sol {
    constexpr int maxV = 17;

    bool f[maxn][(1 << maxV) | 5];
    
    int cnt[maxn];
    int mex[maxn][maxn];
    int pre[maxn][maxV + 2];

    inline void solve(int mx) {
        int c = 17;

        rep (i, 1, n) {
            rep (i, 0, mx + 1) cnt[i] = 0;
            rep (j, i, n) {
                cnt[a[j]]++;
                for (mex[i][j] = 0; mex[i][j] <= mx + 1; mex[i][j]++) if (not cnt[mex[i][j]]) break;
                
                if (mex[i][j] <= c) pre[j][mex[i][j]] = i; // i 单调递增
            }
        }

        f[0][0] = true;
        rep (i, 1, n) {
            rep (j, 0, c) {
                if (pre[i][j]) {
                    rep (S, 0, (1 << c) - 1) {
                        f[i][S | (1 << j)] |= f[pre[i][j] - 1][S];
                    }
                }
            }
        }

        int ans = 0;
        rep (S, 0, (1 << c) - 1) {
            if (not f[n][S]) continue;
            int res = 0;
            for (res = 0; res <= c + 1; res ++) if (not (S & (1 << res))) break;
            ans = std::max(ans, res);
        }

        ans ++;
        std::cout << ans << "\n";
    }
}

inline void solve() {
    std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];

    int mx = 0;
    rep (i, 1, n) mx = std::max(mx, a[i]);

    Sol::solve(mx);
}

int main() {
    fastread
//////////////

    // file("mex")

    solve();

    lookTime
    return 0;
}