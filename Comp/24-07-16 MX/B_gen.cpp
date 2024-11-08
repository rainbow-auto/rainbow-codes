#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using i64 = long long;

std::mt19937 rng (std::chrono::steady_clock::now ().time_since_epoch ().count ());

inline int gen (int l, int r) {
    return std::uniform_int_distribution <int> (l, r) (rng);
}

int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

// const int maxn = 10005;

// bool np[maxn];
// std::vector <int> primes;
// inline void sieve (int n) {
//     np[1] = true;
//     for (int i = 2; i <= n; i++) {
//         if (not np[i]) { primes.push_back (i); }
//         for (auto p : primes) {
//             if (p * i > n) { break; } 
//             np[p * i] = true;
//             if (i % p == 0) { break; }
//         }
//     }

//     for (auto p : primes) { std::cout << p << ", "; }
// }

int main () {

    // sieve (100);

    int n = gen (1, 10000);
    int k = 10;

    std::cout << n << " " << k << "\n";

    srand (time (0));
    std::random_shuffle (primes, primes + 24);

    for (int i = 1; i <= k; i++) {
        std::cout << primes[(i - 1) << 1] * primes[(i - 1) << 1 | 1] << " ";
    }

    return 0;    
}