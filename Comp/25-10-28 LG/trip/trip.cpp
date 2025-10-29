#include <bits/stdc++.h>
#define rep(_i, _st, _ed) for (int (_i) = (_st); (_i) <= (_ed); (_i++))
#define per(_i, _st, _ed) for (int (_i) = (_st); (_i) >= (_ed); (_i--))
#define db std::cerr
#define dbendl std::cerr << "\n";
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s used\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

using i64 = long long;
using u64 = unsigned long long;

constexpr int maxn = 1000005;

int n;
int a[maxn];

namespace Sol {
    i64 pre[maxn];
    int cnt[maxn];

    std::vector<i64> vals;

    inline int id(i64 x) {
        auto it = std::lower_bound(vals.begin(), vals.end(), x);
        if (*it != x) return -1;
        return it - vals.begin();
    }

    inline void solve() {
        rep (i, 1, n) pre[i] = pre[i - 1] + a[i];

        rep (i, 0, n) vals.push_back(pre[i]);
        std::sort(vals.begin(), vals.end());
        vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
        
        int ans = 0;
        per (i, n, 1) {
            cnt[id(pre[i])]++;
            int x = id(pre[i - 1]);
            if (~x) ans = std::max(ans, cnt[x]);
        }

        std::cout << ans << "\n";

        std::memset(cnt, 0, sizeof cnt);
        vals.clear();
    }
}

inline void solve() {
    std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];
    
    Sol::solve();
}

int main() {
    fastread;
    ////////////

    int _; std::cin >> _;
    while (_--) {
        solve();
    }

    lookTime

    return 0;
}