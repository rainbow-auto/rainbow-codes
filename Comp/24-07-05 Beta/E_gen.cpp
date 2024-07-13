#include <iostream>
#include <random>
#include <chrono>

std::mt19937 rng (std::chrono::steady_clock::now ().time_since_epoch ().count ());

i64 getNum (i64 l, i64 r) {
    return std::uniform_int_distribution<i64> (l, r) (rng);
}

int main () {

    int n = 10;

    return 0;
}