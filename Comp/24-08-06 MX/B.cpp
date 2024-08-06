#include <iostream>

using i64 = __int128;

const int maxn = 100005;

int k;
i64 a[maxn], b[maxn];

i64 gcd (i64 a, i64 b) {
    if (not b) { return a; }
    return gcd (b, a % b);
}

inline i64 lcm (i64 a, i64 b) { return a / gcd (a, b) * b; }

inline void merge (i64& m1, i64& a1, i64 m2, i64 a2) {
    if (m1 < m2) { std::swap (m1, m2); std::swap (a1, a2); }

    while (a1 % m2 != a2) { a1 += m1; }
    m1 = lcm (m1, m2);   
}

int main () {

    std::cin >> k;

    for (int i = 1; i <= k; i++) { int x; std::cin >> x; a[i] = x; }
    for (int i = 1; i <= k; i++) { int x; std::cin >> x; b[i] = x; }

    for (int i = 1; i <= k; i++) { a[i] = ((a[i] % b[i]) + b[i]) % b[i]; }

    i64 m = b[1];
    i64 n = a[1];

    for (int i = 2; i <= k; i++) { merge (m, n, b[i], a[i]); }

    std::cout << (long long)(n) << "\n";

    return 0;
}