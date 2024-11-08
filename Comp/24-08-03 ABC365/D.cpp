#include <iostream>

const int maxn = 200005;

int n;
int dp[maxn][3];

int main () {

    std::cin >> n;
    std::string s; std::cin >> s;
    s = " " + s;

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'R') { // 0  => P
            dp[i][0] = std::max (dp[i][0], dp[i - 1][1] + 1); 
            dp[i][0] = std::max (dp[i][0], dp[i - 1][2] + 1); 
            dp[i][2] = std::max(dp[i - 1][0], dp[i - 1][1]);
        } else if (s[i] == 'P') { // 1 => S
            dp[i][1] = std::max (dp[i][1], dp[i - 1][0] + 1); 
            dp[i][1] = std::max (dp[i][1], dp[i - 1][2] + 1); 
            dp[i][0] = std::max(dp[i - 1][1], dp[i - 1][2]);
        } else { // 2 => R
            dp[i][2] = std::max (dp[i][2], dp[i - 1][0] + 1); 
            dp[i][2] = std::max (dp[i][2], dp[i - 1][1] + 1); 
            dp[i][1] = std::max (dp[i - 1][0], dp[i - 1][2]);
        }
    }

    int res = 0;
    res = std::max (res, dp[n][0]);
    res = std::max (res, dp[n][1]);
    res = std::max (res, dp[n][2]);

    std::cout << res << "\n";

    return 0;
}