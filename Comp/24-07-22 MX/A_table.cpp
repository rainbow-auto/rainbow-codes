#include <iostream>

using i64 = long long;

inline i64 solve (i64 n, i64 m) {
    i64 res = 0;
    
    for (i64 kt = 1; 4 * kt <= (n - 1); kt++) {
        for (i64 t = kt; t * t <= kt; t++) {
            if (kt % t) { continue; }
        
            i64 k = kt / t;

            res += 1 + (k != t);
        }
    }

    return res;
}

int main () {

    i64 n, m; std::cin >> n >> m;

    i64 ans = solve (n, m) + solve (m, n) + (m / 2) + (n / 2);

    std::cout << ans << "\n";

    return 0;
}