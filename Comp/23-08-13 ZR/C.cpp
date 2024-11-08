#include <iostream>
#include <cmath>

#define int long long

using namespace std;

const int maxn = 10005;

int m, p;
int dp[maxn][100];

signed main() {

    cin >> m >> p;
    
    for (int i = 0; i <= 9; i++) {
        dp[1][1 << (i % 7)] ++; 
    }

    for (int i = 2; i <= m; i++) {
        for (int S = 0; S < (1 << 6); S++) {
            for (int j = 0; j < 7; j++) {
                if (S & (1 << j)) {
                    for (int k = 0; k <= 9; k++) {
                        int x = (j * 10 % 7 + k) % 7; 
                        dp[i][S | (1 << x)] = (dp[i][S | (1 << x)] + dp[i - 1][S]) % p ;
                    }
                }
            }
        }
    }

    cout << dp[m][(1 << 6) - 1] % p << endl;

    return 0;
}