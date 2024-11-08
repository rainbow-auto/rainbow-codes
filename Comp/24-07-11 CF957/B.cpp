#include <iostream>

using i64 = long long;

int n, k;
int mx;

int main () {

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n >> k;
        
        mx = 0;
        for (int i = 1; i <= k; i++) {
            int now; std::cin >> now;
            mx = std::max (mx, now);    
        }

        int ans = (n << 1) - k + 1 - (mx << 1);
        std::cout << ans << "\n";
    }

    return 0;
}