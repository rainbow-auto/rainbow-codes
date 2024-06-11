#include <iostream>
#include <ctime>
#include <random>
#include <chrono>

std::mt19937 rng(std::chrono::steady_clock::now ().time_since_epoch ().count ());

inline int getRand (int l, int r) {
    return std::uniform_int_distribution<int> (l, r) (rng);
}

int main () {

    int n = 9;

    std::cout << n << "\n";
    for (int i = 1; i <= n; i++) {
        std::cout << getRand (1, 100) << " ";
    }
    std::cout << "\n";

    return 0;
}