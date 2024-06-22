// Unsolve
// 45 pts

#include <iostream>

using i64 = long long;

const int maxn = 100005;

int n;
i64 a[maxn];

i64 dp[maxn];

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i - 1; j++) {
            dp[i] = std::max (dp[i], dp[j] + (a[i] & a[j]));
        }
        ans = std::max (ans, dp[i]);
    }

    std::cout << ans << "\n";

    return 0;
}