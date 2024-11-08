#include <iostream>

using i64 = long long;
const i64 mod = 1e9 + 7;
const int maxn = 1000005;

int T;
i64 n, k;

i64 pwk[maxn];

inline i64 ksm (i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) { res *= a; res %= mod; }
        a *= a; a %= mod; b >>= 1;
    }
    return res;
}

i64 gcd (i64 a, i64 b) {
    if (not b) { return a; }
    return gcd (b, a % b);
}

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n >> k;
        
        for (int i = 1; i <= n; i++) { pwk[i] = ksm (i, k); }

        i64 ans = 0;
        for (i64 i = 1; i <= n; i++) {
            for (i64 j = 1; j <= i; j++) {
                ans += pwk[gcd (j, (j xor i))];
                ans %= mod;
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}