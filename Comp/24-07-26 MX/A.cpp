#include <iostream>

#pragma GCC Optimize("Ofast")

using i64 = long long;

i64 a;

int main () {

    freopen ("min.in", "r", stdin);
    freopen ("min.out", "w", stdout);

    std::cin >> a;

    i64 ans = 1e17;

    for (int i = 1; i <= 1e7; i++) {
        i64 b = a * i;
        i64 sum = 0;
        while (b) { sum += b % 10; b /= 10ll; }

        ans = std::min (ans, sum);
    }
    
    std::cout << ans << "\n";

    return 0;
}