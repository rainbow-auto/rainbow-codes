#include <iostream>

using i64 = long long;

const int maxn = 100005;

int n;
i64 a[maxn];

inline i64 f (i64 x) {
    i64 res = 0; while (x) { res += x % 10ll; x /= 10ll; }
    return res;
}

int main () {

    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    i64 ans = 0;

    for (int i = 1; i <= n; i++) {
        i64 delta = 0;
        for (int j = 1; j <= n; j++) {
            ans += f (a[i] + a[j]);
            delta += f (a[i] + a[j]);
        }
        std::cerr << delta << "\n";
    }

    return 0;
}