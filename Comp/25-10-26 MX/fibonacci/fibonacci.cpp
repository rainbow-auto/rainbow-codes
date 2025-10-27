#include <bits/stdc++.h>
#define rep(_i, _st, _ed) for (int (_i) = (_st); (_i) <= (_ed); (_i)++)
#define per(_i, _st, _ed) for (int (_i) = (_st); (_i) >= (_ed); (_i)--)
#define file(name) std::freopen(name".in", "r", stdin); std::freopen(name".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
#define db std::cerr
#define dbendl std::cerr << "\n";
#define lookTime db << (1.0 * clock() / CLOCKS_PER_SEC) << "s used\n";

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int maxn = 100005;

i64 f[maxn];

struct Rect {
    i64 xl, xr;
    i64 yl, yr;
};

Rect rs[maxn];

inline void init() {
    f[0] = 0;
    f[1] = 1;
    rs[1] = { -1, 0, 0, 1 };

    rep (i, 2, 10000) {
        f[i] = f[i - 1] + f[i - 2];
        if (i % 4 == 1) {
            rs[i].xr = rs[i - 1].xl;
            rs[i].yr = rs[i - 1].yr;
            
            rs[i].xl = rs[i].xr - f[i];
            rs[i].yl = rs[i].yr - f[i];
        }
        if (i % 4 == 2) {  
            rs[i].xl = rs[i - 1].xl;
            rs[i].yr = rs[i - 1].yl;
            
            rs[i].xr = rs[i].xl + f[i];
            rs[i].yl = rs[i].yr - f[i];
        }
        if (i % 4 == 3) {
            rs[i].xl = rs[i - 1].xr;
            rs[i].yl = rs[i - 1].yl;
            
            rs[i].xr = rs[i].xl + f[i];
            rs[i].yr = rs[i].yl + f[i];
        }
        if (i % 4 == 0) {
            rs[i].xr = rs[i - 1].xr;
            rs[i].yl = rs[i - 1].yr;

            rs[i].xl = rs[i].xr - f[i];
            rs[i].yr = rs[i].yl + f[i];
        }
    }
}

inline bool chk(i64 x, i64 y, Rect r) {
    return r.xl <= x and x <= r.xr and r.yl <= y and y <= r.yr;
}

inline void solve() {
    i64 x, y; std::cin >> x >> y;
    rep (i, 1, 10000) {
        if (chk(x, y, rs[i])) {
            std::cout << f[i] << "\n";
            return;
        }
    }
}

int main() {
    fastread

    // file("fibonacci3")
    int _; std::cin >> _;

    init();

    while (_--) {
        solve();
    }

    lookTime

    return 0;
}