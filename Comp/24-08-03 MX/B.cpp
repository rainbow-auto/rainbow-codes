#include <iostream>

using i64 = long long;

const int maxn = 200005;

int n;
i64 a[maxn];

i64 gcd (i64 x, i64 y) {
    if (not y) { return x; }
    return gcd (y, x % y);
}

i64 lcm (i64 x, i64 y) {
    return x / gcd (x, y) * y;
}

int main () {

    freopen ("inequality.in", "r", stdin);
    freopen ("inequality.out", "w", stdout);

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) { continue; }
                i64 x = a[i]; 
                i64 y = a[j];
                a[i] = gcd (x, y);
                a[j] = lcm (x, y);
            }
        }

        i64 sum = 0;
        for (int i = 1; i <= n; i++) { sum += a[i]; }
        std::cout << sum << "\n";
    }


    return 0;
}