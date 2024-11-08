#include <iostream>
#include <cstring>
#include <bitset>

using namespace std;

const int maxk = 205;

int n, m, K;
int a[maxk];

namespace Task1 {

    const int maxn = 205;
    const int maxm = 2005;

    int dp[maxn][maxm]; // dp[i][j] 前i个人, 选的物品价值和为j

    inline void solve () {
        memset (dp, 0, sizeof (dp));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 1; k <= K; k++) {
                    if (j < a[k]) { continue; }
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - a[k]]) % 2;
                }
            }
        }

        cout << dp[n][m] << endl;
    }
}

namespace Task2 {

    const int maxm = 100005;

    bitset<maxm> dp[2];

    inline void solve () {
        dp[0].reset (); dp[1].reset ();

        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i % 2].reset ();
            for (int k = 1; k <= K; k++) {
                dp[i % 2] ^= (dp[(i - 1) % 2] << a[k]);
            }
        }

        cout << dp[n % 2][m] << endl;
    }
}

nam

int main () {

    int T; cin >> T;

    while (T--) {
        cin >> n >> m >> K;

        for (int i = 1; i <= K; i++) { cin >> a[i]; }
        
        Task2::solve ();
    }

    return 0;
}