#include <iostream>

const int maxn = 200005;

int n;
int a[maxn];

int main () {

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n;

        for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

        int ans = 0;

        for (int i = 1; (i << 1) <= n; i++) {
            if (not a[(i << 1)] and not a[(i << 1) - 1]) { continue; }

            if (a[(i << 1)] <= 2 and a[(i << 1) - 1] <= 2) { ans += 1; }
            else { ans += 2; }
        }

        if (n & 1) {
            if (a[n]) { ans ++; }
        }

        std::cout << ans << "\n";
    }

    return 0;
}