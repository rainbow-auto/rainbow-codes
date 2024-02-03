#include <iostream>

int T;

int main () {

    std::cin >> T;

    while (T--) {
        int a, b, k; std::cin >> a >> b >> k;

        for (int c = 0; c <= a + b; c++) {
            int d = a + b - c;

            if (c % 10 == k and d % 10 == k) { std::cout << "YES\n"; goto end; }
        }

        std::cout << "NO\n";

        end:;
    }

    return 0;
}