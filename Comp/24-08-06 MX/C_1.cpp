#include <iostream>
#include <vector>

const int maxn = 10000005;
const int mod = 1e9 + 7;

using i64 = long long;

bool np[maxn]; // not prime
i64 mu[maxn];
i64 sum[maxn];

std::vector <i64> primes;

inline void sieve (i64 n) {
    np[1] = true;
    mu[1] = 1;
    for (i64 i = 2; i <= n; i++) {
        if (not np[i]) { primes.push_back (i); mu[i] = -1; }
        
        for (auto p : primes) {
            if (i * p > n) { break; }
            np[i * p] = true;
            mu[i * p] = -1 * mu[i];
            if (i % p == 0) { mu[i * p] = 0; break; }    
        }   
    }   

    for (int i = 1; i <= n; i++) { sum[i] = sum[i - 1] + mu[i]; }
}

inline i64 solve (i64 n) {
    i64 ans = 0;

    for (i64 l = 1, r = 1; l <= n; l = r + 1) {
        r = n / (n / l);
        ans += (n / l) * (n / l) * (sum[r] - sum[l - 1]);
    }

    return ans;
}

int main () {

    i64 n; std::cin >> n;

    sieve (n);

    i64 ans = 0;
    for (int i = 1; i <= n; i++) { ans = (ans + i * i * solve (i)) % mod; }

    std::cout << ans << "\n";

    return 0;
}