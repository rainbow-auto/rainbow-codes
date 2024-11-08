#include <iostream>
#include <chrono>
#include <random>

std::mt19937 rng (std::chrono::steady_clock::now ().time_since_epoch ().count ());

inline int getRand (int l, int r) {
    return std::uniform_int_distribution<int> (l, r) (rng);
}

int main () {

    int n = getRand (1, 15) * 2;
    int k = getRand (1, 10);

    std::cout << n << " " << k << "\n";

    return 0;
}