#include <iostream>

using i64 = __int128;

i64 exgcd (i64 a, i64 b, i64& x, i64& y) {
    if (not b) { x = 1; y = 0; return a; }
    i64 d = exgcd (b, a % b, y, x);
    y -= x * (a / b);
    return d;
}

i64 inv (i64 n, i64 mod) {
    i64 x, y; exgcd (n, mod, x, y);
    return (x + mod) % mod;
}

const int maxn = 100005;

int k;
i64 a[maxn], b[maxn];

int main () {

    std::cin >> k;

    for (int i = 1; i <= k; i++) { long long x; std::cin >> x; a[i] = x; }
    for (int i = 1; i <= k; i++) { long long x; std::cin >> x; b[i] = x; }

    for (int i = 1; i <= k; i++) { a[i] = ((a[i] % b[i]) + b[i]) % b[i]; }

    i64 M = 1;
    for (int i = 1; i <= k; i++) { M *= b[i]; }

    i64 n = 0;
    for (int i = 1; i <= k; i++) {
        i64 m = M / b[i];
        n = (n + (((((a[i] % M) * m) % M) * inv (m, b[i])) % M)) % M;
    }

    unsigned long long _n = n % M;
    std::cout << _n << "\n";

    return 0;
}