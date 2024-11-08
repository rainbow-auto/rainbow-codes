#include <iostream>

#pragma GCC Optimize("Ofast")

const int maxn = 10005;

int n, x, y;
int dp[2][maxn][maxn];

int a[maxn], b[maxn];

int main () {
    
    std::cin >> n >> x >> y;

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j =x; j <= x; j++) {
            for (int k = b[i]; k <= y; k++) {
                dp[i % 2][j][k] = std::max (dp[i % 2][j][k], dp[(i - 1 + 2) % 2][j - a[i]][k - b[i]] + 1);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= x; j++) {
        for (int k = 0; k <= y; k++) {
            std::cerr << dp[n%2][j][k] << " ";

            ans = std::max (ans, dp[n % 2][j][k]);
        }
        std::cerr << "\n";
    }    

    std::cout << ans << "\n";

    return 0;
}