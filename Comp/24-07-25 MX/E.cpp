#include <iostream>

const int maxn = 1005;

int n;
int a[maxn];

int dp[maxn][maxn];

inline void chkmax (int& a, int b) { if (b > a) { a = b; } }

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    for (int i = 1; i <= n; i++) {
        chkmax (dp[i][a[i]], dp[i - 1][a[i] - 1] + 1);
        for (int j = 1; j <= i; j++) {
            chkmax (dp[i][j], dp[i - 1][j]);
            chkmax (dp[i][j], dp[i - 1][j - 1]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) { chkmax (ans, dp[n][i]); }

    std::cout << ans << "\n";

    return 0;
}
