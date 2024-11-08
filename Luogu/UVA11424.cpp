#include <iostream>

using i64 = long long;

const int maxn = 10000005;

i64 n;
i64 f[maxn];

int main () {

    while (true) {
        std::cin >> n;

        if (not n) { break; }

        i64 ans = 0;

        for (i64 i = n; i >= 1; i--) {
            f[i] = (n / i) * (n / i);

            for (int j = i * 2ll; j <= n; j += i) { f[i] -= f[j]; }

            ans += i * f[i];
        }

        for (int i = 1; i <= n; i++) { ans -= i; } ans /= 2ll;

        std::cout << ans << "\n";
    }


    return 0;
}