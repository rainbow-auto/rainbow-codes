#include <iostream>
#include <random>
#include <chrono>

using i64 = long long;

std::mt19937 rng (std::chrono::steady_clock::now ().time_since_epoch ().count ());

inline int gen (int l, int r) {
    return std::uniform_int_distribution <int> (l, r) (rng);
}

int main () {

    int n = 1000;

    std::cout << n << "\n";
    for (int i = 1; i <= n; i++) { std::cout << gen (1, 1000) << " "; }

    return 0;
}