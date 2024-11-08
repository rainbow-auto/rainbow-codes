#include <iostream>
#include <algorithm>

using i64 = long long;
using f64 = double;

const int maxn = 5005;

int n, m;
int a[maxn];

namespace Task1 {
    f64 ans;
    
    int choice[maxn];

    void dfs (int now, int rest) {
        if (now == n + 1) {
            if (rest != 0) { return; }

            f64 ansnow = 0;
            for (int i = 1; i <= n; i++) {
                int cnt = 0;
                for (int j = 1; j <= n; j++) {
                    if (choice[i] < a[j]) { cnt ++; }
                }

                ansnow += 1.0 * cnt / n;
            }
            ans = std::min (ans, ansnow);

            return;
        }

        for (int i = 0; i <= rest; i++) { 
            choice[now] = i;
            dfs (now + 1, rest - i); 
        }
    }  

    inline void solve () {
        ans = 1e18;
        dfs (1, m);
        std::cout << ans << "\n";
    }
}

const f64 eps = 1e-18;

namespace Task2 {
    
    f64 dp[maxn][maxn];

    void solve () {
        std::sort (a + 1, a + n + 1);

        for (int i = 0; i <= m; i++) {
            f64 cnt = n - ((std::upper_bound (a + 1, a + n + 1, i) - a) - 1);
            dp[1][i] = 1.0 * cnt / n;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = 1e18;
                for (int k = 0; j - k >= 0; k++) {
                    f64 cnt = n - ((std::upper_bound (a + 1, a + n + 1, k) - a) - 1);
                    if (dp[i][j] - (dp[i - 1][j - k] + (1.0 * cnt / f64(n))) > eps) {
                        dp[i][j] = dp[i - 1][j - k] + (1.0 * cnt / f64(n));
                    }
                }

                // l = j - k \in 0 \dots j
                // dp[i - 1][0...j] + v[k]
                // j - k \in 0...j
            }
        }

        // std::cout << dp[n][m] << "\n";
        printf ("%.12lf\n", dp[n][m]);
    }
}

int main () {

    freopen ("monster.in", "r", stdin);
    freopen ("monster.out", "w", stdout);

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    std::sort (a + 1, a + n + 1);

    // Task1::solve ();
    Task2::solve ();

    return 0;
}