#include <iostream>

const int maxn = 300005;

int T;

int n, k;
int a[maxn];

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n >> k;
        for (int i = 1; i <= n; i++) { char c; std::cin >> c; a[i] = (c == 'T'); } // H : 0 | T : 1

        int now = 0;
        int res = 0;

        a[0] = a[1];

        int l = 1;
        for (int r = 1; r <= n; r++) {
            if (a[r] != a[r - 1]) { now ++; }

            while (now > k) { if (a[l] != a[l + 1]) { now --; } l++; }
            res = std::max (res, r - l + 1);
        }

        std::cout << res << "\n";
    }

    return 0;
}