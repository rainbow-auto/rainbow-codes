#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

#define endl "\n"
#define fastread std::ios::sync_with_stdio (false); cin.tie (0);

const int maxn = 1000005;

int n;
int a[maxn];

namespace Task1 {

    const int task1maxn = 1005;

    int dp[task1maxn][task1maxn];

    inline void solve () {
        for (int i = 1; i <= n; i++) { dp[i][i] = 1; }

        for (int len = 2; len <= n; len ++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;

                // 找左侧最长的01交错串
                int lpos = l;
                while (lpos + 1 <= r and a[lpos + 1] != a[lpos]) { lpos ++; }

                // 找右侧最长的01交错串
                int rpos = r;
                while (rpos - 1 >= l and a[rpos - 1] != a[rpos]) { rpos --; }
                
                bool flag = false;
                if (l == 1 and r == n) { flag = true; }

                if (lpos >= rpos or a[lpos] != a[rpos]) {
                    dp[l][r] = dp[lpos + 1][rpos - 1] + 1; // 如果lpos + 1 > rpos - 1, dp值也恰好为0
                } else {
                    dp[l][r] = std::min (dp[lpos][rpos - 1], dp[lpos + 1][rpos]) + 1;
                }
            }
        }

        cout << dp[1][n] << endl;
    }

}

int main () {
    fastread

    cin >> n;
    for (int i = 1; i <= n; i++) {
        char now; cin >> now;
        a[i] = now - '0';
    }

    Task1::solve ();

    return 0;
}

/*
1100010101011001001111100000100000010101100111100011100101101010111010000010101101010001100100101001
*/