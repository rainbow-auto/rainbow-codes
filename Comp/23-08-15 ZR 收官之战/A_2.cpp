#include <iostream>

using namespace std;

const int maxn = 3005;

int n, m;
int w[maxn], v[maxn];

int dp[maxn][maxn][2];

int main () {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= m; i++) {
        dp[0][i][0] = -0x3f3f3f3f;
        dp[0][i][1] = -0x3f3f3f3f;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j][0] = -0x3f3f3f3f;
            dp[i][j][1] = max (dp[i][j][1], dp[i - 1][j][1]);
            dp[i][j][1] = max (dp[i][j][1], dp[i - 1][j][0]);

            if (j - w[i] < 0) { continue; }

            dp[i][j][0] = max (dp[i][j][0], dp[i - 1][j - w[i]][0] + v[i]);
            dp[i][j][1] = max (dp[i][j][1], dp[i - 1][j - w[i]][1] + v[i]);
            dp[i][j][1] = max (dp[i][j][1], dp[i - 1][j - w[i]][0] + v[i]);
        }
    }

    for (int i = 1; i <= n; i++) { cout << dp[i][1][1] << " "; } cout << endl;

    return 0;
}