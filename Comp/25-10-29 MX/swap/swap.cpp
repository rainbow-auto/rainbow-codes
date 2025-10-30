#include <bits/stdc++.h>
#define rep(_id, _st, _ed) for (i64 (_id) = (_st); (_id) <= (_ed); (_id)++)
#define per(_id, _st, _ed) for (i64 (_id) = (_st); (_id) >= (_ed); (_id)--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

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

namespace Task2 {
    i64 gcd(i64 a, i64 b) {
        if (not b) return a;
        return gcd(b, a % b);
    }

    constexpr int maxb = 36;
    // constexpr int maxb = 5;
    int f[maxb][maxn];
    int p[maxn];

    int res[maxn];
    
    inline void solve() {
        i64 T = n / gcd(n, m) * m;
        dbg(T);

        rep (i, 0, n - 1) p[i] = i;
        rep (i, 1, T) {
            // dbg(i);
            std::swap(p[(b[i % m] + i) % n], p[(c[i % m] + i) % n]);
        }

        rep (i, 0, n - 1) f[0][p[i]] = i;

        rep (b, 0, maxb - 2) {
            // dbg(b);
            rep (i, 0, n - 1) {
                f[b + 1][i] = f[b][f[b][i]];
            }
        }

        i64 stp = (t - t % T) / T;
        dbg(stp);

        rep (i, 0, n - 1) {
            int to = i;
            per (b, maxb - 1, 0) {
                if ((stp >> b) & 1) {
                    // dbg(b);
                    to = f[b][to];
                }
            }
            res[to] = a[i];
        }

        i64 rst = (t % T);
        dbg(rst);
        rep (i, t - rst + 1, t) {
            std::swap(res[(b[i % m] + i) % n], res[(c[i % m] + i) % n]);
        }

        rep (i, 0, n - 1) std::cout << res[i] << " "; std::cout << "\n";
    }
}

inline void solve() {
    std::cin >> n >> m;
    std::cin >> t;
    rep (i, 0, n - 1) std::cin >> a[i];
    rep (i, 0, m - 1) std::cin >> b[i] >> c[i];

    int B = 10000000;
    if (t <= B) Task1::solve();
    else Task2::solve();
}

int main() {
    fastread

    file("swap")
    solve();

    return 0;
}

/*
6 7 4 5 8 3 0 9 2 1 
*/