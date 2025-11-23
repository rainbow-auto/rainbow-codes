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

constexpr int maxn = 2000005;
constexpr int mod = i64(1e9 + 7);

int m, p;
i64 fac[maxn], ifac[maxn], pw2[maxn];

inline i64 ksm(i64 a, i64 b) {
    a %= mod;
    i64 res = 1;
    for (; b; (b >>= 1), (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
    return res;
}

inline i64 inv(i64 x) {
    return ksm(x, mod - 2);
}

inline void init(int N) {
    fac[0] = 1; rep (i, 1, N) fac[i] = fac[i - 1] * i % mod;
    ifac[N] = inv(fac[N]); per (i, N - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
    pw2[0] = 1; rep (i, 1, N) pw2[i] = pw2[i - 1] * 2ll % mod;
}

inline i64 choose(int a, int b) {
    if (a < 0 or b < 0 or a < b) return 0;
    return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

inline i64 ichoose(int a, int b) {
    if (a < 0 or b < 0 or a < b) return 0;
    return ifac[a] * fac[b] % mod * fac[a - b] % mod;
}

namespace Task1 {
    inline void solve() {
        int n = 2 * p + m;
        i64 ans = 0;
        rep (t, 0, p + m + 1) {
            rep (k, 0, t - 1) {
                // (ans += inv(choose(n, t)) % mod * ksm(2ll, k) % mod * k % mod * choose(p, k) % mod * choose(m, t - 1 - k) % mod) %= mod;
                (ans += ichoose(n, t) % mod * pw2[k] % mod * k % mod * choose(p, k) % mod * choose(m, t - 1 - k) % mod) %= mod;
            }
        }
        std::cout << ans << "\n";
    }
}

namespace Task2 {
    inline void solve() {
        int n = 2 * p + m;
        i64 ans = 0;
        rep (t, 0, p + m + 1) {
            int k = t - 1;
            (ans += ichoose(n, t) % mod * pw2[k] % mod * k % mod * choose(p, k) % mod * choose(m, t - 1 - k) % mod) %= mod;
        }
        std::cout << ans << "\n";
    }
}

inline void solve() {
    std::cin >> p >> m;
    if (m == 0) Task2::solve();
    else Task1::solve();
}

int main() {                     
    fastread

    file("socks")

    init(2000000);

    int _; std::cin >> _;
    while (_--) {
        solve();
    }

    lookTime

    return 0;
}