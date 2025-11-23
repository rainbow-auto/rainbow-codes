#include <bits/stdc++.h>
#define rep(_id, _st, _ed) for (int _id = (_st); _id <= (_ed); _id++)
#define per(_id, _st, _ed) for (int _id = (_st); _id >= (_ed); _id--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s used\n";
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

using i64 = long long;
using f64 = long double;

constexpr int maxn = 200005;

int n, m;
int s[maxn];

namespace Task0 {
    int p[maxn];

    inline void solve() {
        int all = 0;
        int ans = 0;
        
        rep (i, 1, n) p[i] = i;
        do {
            int cur = (1 << m) - 1;
            rep (i, 1, n) {
                if ((s[p[i]] & cur) == 0) continue;
                cur &= s[p[i]];
            }

            if (cur & 1) ans++;
            all++;
        } while (std::next_permutation(p + 1, p + n + 1));     

        std::cout << std::fixed << std::setprecision(16) << f64(1.0 * ans / all) << "\n";
    }
}

inline void solve() {
    std::cin >> n >> m;
    rep (i, 1, n) {
        rep (j, 1, m) {
            char c; std::cin >> c;
            s[i] |= ((c - '0') << (j - 1));
        }
    }

    Task0::solve();
}

int main() {
    fastread

    file("iqtest")

    solve();

    return 0;
}