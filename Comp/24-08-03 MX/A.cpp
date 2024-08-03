#include <iostream>
#include <algorithm>

using i64 = long long;

const i64 mod = 1e9 + 7;
const int maxn = 105;

i64 n, k;

inline i64 fac (i64 t) {
    i64 res = 1;
    for (int i = 2; i <= t; i++) { res *= i; res %= mod; }
    return res;
}

namespace Task1 {
    
    int a[maxn];
    inline void solve () {
        for (int i = 1; i <= n; i++) { a[i] = i; }
        
        i64 ans = 0;
        do {
            int sum = 0;
            for (int i = 1; i <= n; i++) { sum += std::max (i, a[i]); }
            if (sum == k) { ans ++; }
        } while (std::next_permutation (a + 1, a + n + 1));

        ans *= fac (n); ans %= mod;
        std::cout << ans << "\n";
    }
}

int main () {

    freopen ("count.in", "r", stdin);
    freopen ("count.out", "w", stdout);

    std::cin >> n >> k;

    if (n <= 10) {
        Task1::solve ();
    } else if (n * (n + 1) / 2 == k) {
        std::cout << fac (n) << "\n";
    }

    return 0;
}