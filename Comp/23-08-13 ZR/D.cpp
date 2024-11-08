#include <iostream>
using namespace std;

const int maxn = 5005;
int n, m;
int a[maxn];
int sum[maxn];

int dp[maxn][maxn];

int main () {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= i; k++) {
                dp[i][j] = min(dp[i][j], max(dp[k][i - 1], sum[i] - sum[k - 1]));
            }
        }
    }

    int res = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++) {
        res = min (res, dp[n][i]);
    }
    cout << res << endl;

    return 0;
}