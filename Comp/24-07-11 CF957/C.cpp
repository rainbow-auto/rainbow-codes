#include <iostream>

using i64 = long long;

const int maxn = 200005;

int n, m, k;
int a[maxn];

int main () {

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n >> m >> k;

        for (int i = 1, now = n; i <= n - k + 1; i++) { a[i] = now; now --; }

        for (int i = n - m + 1, now = 1; i <= n; i++) { a[i] = now; now ++; }

        for (int i = n - k + 2, now = m + 1; i <= n - m; i++) { a[i] = now; now ++; }

        for (int i = 1; i <= n; i++) { std::cout << a[i] << " "; } std::cout << "\n";
    }

    return 0;
}