#include <iostream>

using namespace std;

const int maxn = 3005;

int n, m;
int w[maxn], v[maxn];

namespace Solution {
    int dp[maxn][maxn][3];

    inline void solve () {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                // 不选
                dp[i][j][1] = max (dp[i][j][1], dp[i - 1][j][1]);
                
                dp[i][j][2] = max (dp[i][j][1], dp[i - 1][j][0]);
                dp[i][j][2] = max (dp[i][j][1], dp[i - 1][j][2]);

                if (j - w[i] < 0) { continue; }

                // 选
                dp[i][j][0] = dp[i - 1][j - w[i]][0] + v[i];
                
                dp[i][j][1] = max (dp[i][j][1], dp[i - 1][j - w[i]][1] + v[i]);
                dp[i][j][1] = max (dp[i][j][1], dp[i - 1][j - w[i]][2] + v[i]);

                dp[i][j][2] = max (dp[i][j][2], dp[i - 1][j - w[i]][0] + v[i]);
            }
        }    

        for (int i = 1; i <= m; i++) {
            if (dp[n][i][1]) { cout << dp[n][i][1] << " "; }
            else { cout << "-1 "; }
        }
        cout << endl;

        cout << "dp:" << endl;
    
        cout << "0:";
        for (int i = 1; i <= n; i++) {
            cout << dp[i][1][0] << " ";
        }
        cout << endl;
        
        cout << "1:";
        for (int i = 1; i <= n; i++) {
            cout << dp[i][1][1] << " ";
        }
        cout << endl;

        cout << "2:";
        for (int i = 1; i <= n; i++) {
            cout << dp[i][1][2] << " ";
        }
        cout << endl;
    }
}

int main () {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    Solution::solve();

    return 0;
}