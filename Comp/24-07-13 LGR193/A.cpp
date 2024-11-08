#include <iostream>

using i64 = unsigned long long;

i64 n, k;

int main () {

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n >> k;

        i64 mod = 2;

        i64 rest1 = 1;
        i64 rest2 = 2;

        i64 choice;

        for (int i = 1; i <= k; i++) {
            int x; std::cin >> x;

            if (x == 1) {
                choice = rest2;
            } else {

                choice = rest1;
            }

            rest1 = choice;
            rest2 = choice + mod;
            mod *= 2ll;
        }

        std::cout << choice << "\n";
    }


    return 0;
}