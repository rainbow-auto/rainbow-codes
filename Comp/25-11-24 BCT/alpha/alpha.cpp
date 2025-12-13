#include <bits/stdc++.h>
#define rep(_id, _st, _ed) for (int _id = (_st); _id <= (_ed); _id++) 
#define per(_id, _st, _ed) for (int _id = (_st); _id >= (_ed); _id--) 
#define db std::cerr
#define dbg(x) std::cerr << (#x) << " : " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

using i64 = long long;

constexpr int maxn = 15;

int n, k;

int a[maxn];
int b[maxn];

namespace Task0 {
    int p[maxn];

    inline void solve() {
        std::cin >> n >> m >> k;
        rep (i, 1, n) std::cin >> a[i];

        rep (i, 1, k + m) p[i] = i;
        
        int ans = 0;
        do {
            rep (i, 1, k + m) {
                int cur = p[i];
                if (p[i] > k) {
                    rep (j, 1, n) 
                }
            }
        } while (std::next_permutation(p + 1, p + k + m + 1));
    }
}

inline void solve() {

}

int main() {
    fastread

    solve();

    return 0;
}