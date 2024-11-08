#include <iostream>

const int maxn = 200005;

using i64 = long long;

int n;
i64 a[maxn];
i64 s[maxn], t[maxn];

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    for (int i = 1; i <= n - 1; i++) {
        std::cin >> s[i] >> t[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        // while (a[i] >= s[i]) { a[i] -= s[i]; a[i + 1] += t[i]; }
        a[i + 1] += t[i] * i64 (a[i] / s[i]); a[i] %= s[i];
    }

    std::cout << a[n] << "\n";

    return 0;
}