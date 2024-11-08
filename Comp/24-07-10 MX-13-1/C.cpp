#include <iostream>

using i64 = long long;

const i64 mod = 998244353;

inline i64 ksm (i64 a, i64 b) {
    i64 res = 1;
    i64 base = a;
    while (b) {
        if (b & 1) { res *= base; res %= mod; }
        base *= base; base %= mod;
        b >>= 1;
    }
    return res;
}

i64 gcd (i64 a, i64 b) {
    if (not b) { return a; }
    return gcd (b, a % b);
}

inline void simplify (i64& a, i64& b) {
    i64 d = gcd (a, b);
    a /= d; b /= d;
}

i64 n, x, y;

namespace Task1 {
    inline void solve () {
        i64 ans = x * ksm (y, 998244351); ans %= mod;
        std::cout << ans << "\n";
    }
}

int main () {

    freopen ("Cbracket.in", "r", stdin);
    freopen ("Cbracket.out", "w", stdout);

    std::cin >> n >> x >> y;
    simplify (x, y);

    if (n == 1) { Task1::solve (); }

    return 0;
}