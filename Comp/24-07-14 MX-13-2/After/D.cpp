#include <iostream>

using i64 = long long;

const i64 mod = 998244353;

const int maxn = 200005;

i64 n, m;

i64 fac[maxn];

inline void init () {
    fac[0] = 1;
    for (i64 i = 1; i <= 200000ll; i++) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
    }
}

inline i64 ksm (i64 a, i64 b) {
    i64 base = a;
    i64 res = 1;

    while (b) {
        if (b & 1) { res *= base; res %= mod; }
        base *= base; base %= mod;
        b >>= 1;
    }

    return res;
}

inline i64 inv (i64 x) { return ksm (x, mod - 2); }

inline i64 C (i64 x, i64 y) { // x 中选出 y 个
    if (x < y) { return 0; }
    return (((fac[x] * inv (fac[y])) % mod) * inv (fac[x - y])) % mod;
}

inline void solve () {
    i64 ans = 0;
    
    for (i64 k = 1; k <= i64 (n / m); k++) {
        i64 x_1 = n - m * k + 2ll * k;
        i64 y_1 = 2ll * k;
        i64 c_1 = C (x_1, y_1);

        i64 x_2 = n - m * k + k;
        i64 y_2 = 2ll * k;
        i64 c_2 = C (x_2, y_2);

        ans += (c_1 - c_2 + mod) % mod;
        ans %= mod;
    }

    std::cout << ans << "\n";
}


int main () {

    freopen ("magic.in", "r", stdin);
    freopen ("magic.ans", "w", stdout);

    int T; std::cin >> T;
    
    init ();

    while (T--) {
        std::cin >> n >> m;

        solve ();
    }

    return 0;
}