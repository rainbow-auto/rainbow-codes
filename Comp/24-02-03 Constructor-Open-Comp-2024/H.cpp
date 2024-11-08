#include <iostream>
#include <vector>

using i64 = long long;

// std::vector<i64> primes;
// bool not_prime[10000005];
// inline void get_primes () {
//     not_prime[1] = true;
//     i64 now = 1;
//     while (primes.size () <= 100) {
//         now ++;
//         if (not_prime[now]) { continue; }
//         primes.push_back (now);

//         for (i64 j = 1; j * now <= 10000005; j++) {
//             not_prime[j * now] = true;
//         }
//     }
// }

const i64 primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547 };

int T;

int n;
i64 x;

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n >> x;

        for (int i = 1; i <= n; i++) { std::cout << x * primes[i - 1] << " "; } 
        std::cout << "\n";
    }

    return 0;
}