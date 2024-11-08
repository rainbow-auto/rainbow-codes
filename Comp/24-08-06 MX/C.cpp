#include <iostream>

using i64 = long long;

const int maxn = 10000005;
const i64 mod = 1e9 + 7;

i64 n;
i64 f[maxn];

int main () {

    std::cin >> n;

    i64 ans = 0;
    for (i64 i = n; i >= 1; i--) {
        f[i] = (n / i) * (n / i);

        for (int j = i * 2ll; j <= n; j += i) { f[i] -= f[j]; }

        ans = (ans + (i * i * f[i]) % mod) % mod;
    }

    std::cout << ans << "\n";

    return 0;
}