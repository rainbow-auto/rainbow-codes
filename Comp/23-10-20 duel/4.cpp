#include <iostream>
#include <map>

using i64 = long long;

const int maxn = 2005;

int n;
int a[maxn];

int pre[maxn];

std::map<int, bool> dp[maxn];

int main () {

    int T; std::cin >> T;
    
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
        for (int i = 1; i <= n; i++) { pre[i] = pre[i - 1] xor a[i]; }

        dp[1][a[1]] = true;
        for (int i = 2; i <= n; i++) {
            dp[i].clear ();
            for (int j = 1; j < i; j++) {
                for (int k = j + 1; k < i; k++) {
                    if (dp[j].count (pre[i] ^ pre[k - 1])) {
                        dp[i][pre[i] ^ pre[k - 1]] = true;
                    }
                }
            }
        }

        if (dp[n].size()) { std::cout << "YES" << "\n"; }
        else { std::cout << "NO" << "\n"; }
    }
    
    return 0;
}