#include <bits/stdc++.h>
#define rep(_id, _st, _ed) for (int (_id) = (_st); (_id) <= (_ed); (_id)++)
#define per(_id, _st, _ed) for (int (_id) = (_st); (_id) >= (_ed); (_id)--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

using i64 = long long;
using u64 = unsigned long long;

constexpr int maxn = 100005;

int n;
int a[maxn];

namespace Sol {
    inline void solve() {
        i64 sum = 0;
        rep (i, 1, n) sum += a[i];

        i64 pre = 0;
        rep (i, 1, n - 1) {
            pre += a[i];
            i64 suf = sum - pre;

            // L 
            if (pre > suf) {
                std::cout << "1";
                continue;
            }

            if (a[i] <= a[i + 1]) {
                std::cout << "0";
                continue;
            }

            // K
            if (i + 2 > n) {
                std::cout << "1";    
                continue;
            }

            if (pre + a[i + 1] <= suf - a[i + 1]) {
                std::cout << "0";
                continue;
            }


            if (a[i] + a[i + 1] > a[i + 2]) {
                std::cout << "1";
                continue;
            }

            // L
            // assert(0);
            if (pre - a[i] > suf + a[i]) {
                std::cout << "1";
                continue;
            } else {
                std::cout << "0";
                continue;
            }

            assert(0);
        }

        std::cout << "\n";

        rep (i, 1, n) a[i] = 0;
    }
}

inline void solve() {
    std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];

    Sol::solve();
}

int main() {
    fastread

    // file("war6")

    int _; std::cin >> _;
    while (_--) {
        solve();
    }
    
    return 0;
}