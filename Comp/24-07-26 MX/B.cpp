#include <iostream>

using i64 = long long;

const int maxn = 1000005;
const i64 mod = 1e9 + 7;

i64 n;
i64 f[maxn];
i64 sum[maxn]; // 前缀和

inline i64 query (int l, int r) {
    if (l > r) { return 0; }
    return (sum[r] - sum[l - 1] + mod) % mod;
}

int main () {

    freopen ("count.in", "r", stdin);
    freopen ("count.out", "w", stdout);

    std::cin >> n;
    
    if (n == 1) { std::cout << "1\n"; return 0; }

    f[0] = 1; sum[0] = f[0];
    f[1] = 1; sum[1] = f[0] + f[1];
    f[2] = 1; sum[2] = f[0] + f[1] + f[2];
    
    for (i64 i = 3; i <= n; i++) {
        f[i] = query (std::max (i - n - 1, 0ll), i - 3) + f[i - 1];
        f[i] %= mod;

        sum[i] = sum[i - 1] + f[i];
        sum[i] %= mod;
    }

    i64 ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        ans = (ans + (f[i - 1] * (n - 1) % mod * (n - 1) % mod)) % mod;
    }
    ans = (ans + (f[n - 1] * (n - 1)) % mod) % mod;
    ans = (ans + f[n]) % mod;

    for (int i = 1; i <= n; i++) {
        ans = (ans + f[i - 1] * (i - 1)) % mod;
    }

    std::cout << ans << "\n";

    return 0;
}