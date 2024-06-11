#include <iostream>
#include <random>
#include <chrono>

std::mt19937 rng (std::chrono::steady_clock::now ().time_since_epoch ().count ());

int getRand (int l, int r) {
    return std::uniform_int_distribution <int> (l, r) (rng);
} 

const int maxn = 100000;

int main () {

    int n = getRand (maxn - 100, maxn);
    int q = getRand (maxn - 100, maxn);

    std::cout << n << " " << q << "\n";

    for (int i = 1; i <= n; i++) {
        std::cout << getRand (1, 10000) << " ";
    }
    std::cout << "\n";

    for (int i = 1; i <= n; i++) {
        int op = getRand (1, 2);
        std::cout << op << " ";

        if (op == 1) {
            std::cout << getRand (1, std::min (n, 10000)) << " ";
            std::cout << getRand (1, std::min (n, 10000)) << "\n";
        } else {
            std::cout << getRand (1, std::min (n, 10000)) << "\n";
        }

    }


    return 0;
}