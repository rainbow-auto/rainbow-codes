#include <iostream>

using i64 = long long;

inline i64 solve (i64 n, i64 m) {
    i64 res = 0;
    for (i64 t = 1; ; t++) {
        i64 lim1 = (n - 1) / (4 * t);
        i64 lim2 = (m / 2);

        if (not lim1) { break; }

        res += std::min (lim1, lim2);
    }   

    return res;
}

int main () {

    i64 n, m;

    std::cin >> n >> m;

    i64 ans = solve (n, m) + solve (m, n) + (m / 2) + (n / 2);

    std::cout << ans << "\n";

    return 0;
}