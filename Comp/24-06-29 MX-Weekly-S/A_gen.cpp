#include <iostream>
#include <random>
#include <chrono>

std::mt19937 rng (std::chrono::steady_clock::now().time_since_epoch ().count ());

inline int getNum (int l, int r) {
    return std::uniform_int_distribution <int> (l, r) (rng);
}

int main () {

    int n = 10;

    std::cout << n << "\n";

    for (int i = 1; i <= n; i++) { std::cout << getNum (1, n) << " "; }

    return 0;
}