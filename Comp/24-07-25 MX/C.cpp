#include <iostream>

const int maxn = 5005;

int n, m;

int a[maxn];
int b[maxn];

int dp[maxn][maxn];
int pre[maxn];

int main () {

    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
    
    std::cin >> m;
    for (int i = 1; i <= m; i++) { std::cin >> b[i]; }

    for (int i = 1; i <= n; i++) {
        
        // pre process

        int mx = 0;
        for (int j = 1; j <= m; j++) {
            if (b[j] < a[i]) { mx = std::max (mx, dp[i - 1][j]); }
            pre[j] = mx;
        }

        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) { dp[i][j] = pre[j] + 1; }
            else { dp[i][j] = dp[i - 1][j]; }
        }       
    }

    int ans = 0;
    for (int j = 1; j <= m; j++) { ans = std::max (ans, dp[n][j]); }
    std::cout << ans << "\n";

    return 0;
}