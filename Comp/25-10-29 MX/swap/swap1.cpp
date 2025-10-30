#include <bits/stdc++.h>
#define rep(_id, _st, _ed) for (i64 (_id) = (_st); (_id) <= (_ed); (_id)++)
#define per(_id, _st, _ed) for (i64 (_id) = (_st); (_id) >= (_ed); (_id)--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".ans", "w", stdout);

using i64 = long long;
using u64 = unsigned long long;

constexpr int maxn = 100005;

int n, m;
i64 t;
int a[maxn], b[maxn], c[maxn];

namespace Task1 {
    inline void solve() {
        rep (i, 1, t) {
            std::swap(a[(b[i % m] + i) % n], a[(c[i % m] + i) % n]);
        }
        rep (i, 0, n - 1) std::cout << a[i] << " "; std::cout << "\n";
    }
}

inline void solve() {
    std::cin >> n >> m;
    std::cin >> t;
    rep (i, 0, n - 1) std::cin >> a[i];
    rep (i, 0, m - 1) std::cin >> b[i] >> c[i];

    Task1::solve();
}

int main() {
    fastread

    file("ex_swap1")
    solve();

    return 0;
}

/*
6 7 4 5 8 3 0 9 2 1 
*/