#include <iostream>

#define int long long

using namespace std;

const int maxn = 5005;
const int mod = 1e9 + 7;

int n, m;
int dp[maxn][maxn];

signed main () {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) { dp[1][i] = 1; }

    for (int i = 1; i <= m - 1; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] %= mod;
            for (int k = 0; k * j <= n; k ++) {
                dp[i + 1][j + k * j] += dp[i][j];
                dp[i + 1][j + k * j] %= mod;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            res += dp[i][j];
            res %= mod;
		}
    }
	
    cout << res % mod << endl;

    return 0;
}
