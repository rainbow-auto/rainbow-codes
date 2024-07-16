#include <iostream>

using i64 = long long;

const int maxn = 505;

const i64 mod = 1e9 + 7;

i64 n, m;
i64 dp[maxn][maxn];

i64 pw2[maxn * maxn];

int main () {

    freopen ("seg.in", "r", stdin);
    freopen ("seg.out", "w", stdout);

    std::ios::sync_with_stdio (false);

    std::cin >> n >> m;

    if (m == 0) { std::cout << 1 << "\n"; return 0; }

    pw2[0] = 1;
    for (int i = 1; i <= 500 * 500; i ++) {
        pw2[i] = 2ll * pw2[i - 1] % mod;
    }

    dp[0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int k = i + 1; k <= n; k ++) {
            for (int j = 0; j <= m; j ++) {
                dp[k][j + 1] = (dp[k][j + 1] + (dp[i][j] * (pw2[k - i] - 1) % mod * pw2[(n - k) * (k - i)]) % mod) % mod;
            }
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i][m] % mod) % mod;
    }   

    std::cout << ans << "\n";

    return 0;
}