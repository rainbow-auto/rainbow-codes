// use Task2

#include <iostream>
#include <vector>

using i64 = long long;

const int maxn = 100005;

int n, q;
int a[maxn];

int gcd (int a, int b) {
    if (b == 0) { return a; }
    return gcd (b, a % b);
}

namespace Task1 {
    
    inline void solve () {
        while (q--) {
            int op; std::cin >> op;

            if (op == 2) {
                int x; std::cin >> x;

                int sum = 0;
                for (int i = 1; i <= n; i++) {
                    if (gcd (i, x) == 1) { sum += a[i]; }
                }

                std::cout << sum << "\n";
            } else {
                int x, y; std::cin >> x >> y;

                a[x] = y;
            }
        }
    }

}

namespace Task2 {

    int mu[maxn];
    int not_prime[maxn];
    std::vector<int> primes;

    // 线性筛莫比乌斯函数
    inline void get_mu () {
        mu[1] = 1;
        not_prime[1] = true;
        
        for (int i = 2; i <= n; i++) {
            if (not not_prime[i]) { primes.push_back (i); mu[i] = -1; }

            for (auto p : primes) {
                if (i * p > n) { break; }
                not_prime[i * p] = true;
                mu[i * p] = -1 * mu[i];

                if (i % p == 0) { mu[i * p] = 0; break; }
            }
        }
        // for (int i = 1; i <= n; i++) { std::cerr << mu[i] << " "; }
    }

    int s[maxn]; // s_d = \sum\limits_{d | i} a_i

    inline void init () {
        get_mu ();

        // O (n log n) <=> 与埃氏筛同理
        for (int d = 1; d <= n; d++) {
            for (int k = 1; k * d <= n; k ++) {
                int i = k * d;
                s[d] += a[i];
            }
        }
    }

    inline void modify (int pos, int val) {
        int delta = val - a[pos];
        a[pos] = val;

        for (int d = 1; d * d <= pos; d ++) {
            if (pos % d == 0) { 
                s[d] += delta; 
            
                if (pos / d != d) { s[pos / d] += delta; }
            }
        }
    }

    inline int query (int x) {
        int res = 0;
        for (int d = 1; d * d <= x; d++) {
            if (x % d == 0) {
                res += mu[d] * s[d];        
                
                if (x / d != d) { res += mu[x / d] * s[x / d]; }
            }
        }
        return res;
    }

    inline void solve () {
        init ();

        while (q--) {
            int op; std::cin >> op;

            if (op == 1) {
                int x, y; std::cin >> x >> y;
                modify (x, y);
            } else {
                int x; std::cin >> x;
                std::cout << query (x) << "\n";
            }
        }
    }

}

int main () {

    std::ios::sync_with_stdio (false); std::cin.tie (0);

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    // Task1::solve ();
    Task2::solve ();

    return 0;
}