#include <iostream>

const int maxn = (1 << 20) + 5;

bool ex[maxn];
int sum[maxn];

inline int popcount (int x) {
    int res = 0;
    while (x) { res += (x & 1); x >>= 1; }
    return res;
}

inline void display (int x) {
    for (int i = 1; i <= 10; i++) { std::cerr << (x & 1); x >>= 1; }
    std::cerr << "\n";
}

inline void sieve () {
    for (int x = 0; x <= (1ll << 20); x++) {
        int y = x ^ (1ll << popcount (x));
        ex[y] = true; 
        display (y);   
    }

    for (int i = 1; i <= (1ll << 20); i++) { sum[i] = sum[i - 1] + ex[i]; }
}

int main () {

    int T; std::cin >> T;
    
    sieve ();

    while (T--) {
        int L, R; std::cin >> L >> R;
        std::cout << sum[R] - sum[L - 1] << "\n";
    }

    return 0;
}