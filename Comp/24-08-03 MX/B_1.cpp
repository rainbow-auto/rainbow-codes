#include <iostream>

const int maxn = 1000005;

int cnt[maxn];

inline void upd (int x) {
    std::map <int, int> cur;
    for (int i = 2; i * i <= x; i++) {
        while (x % i) { cur[i] ++; x /= i; }
    }
    if (x != 1) { cur[x] ++; }

    for (auto [v, c] : cur) { cnt[v] = std::max (cnt[v], c); }
}

inline i64 ksm (i64 a, i64 b) {
    i64 res = 1; 
    a %= mod;
    while (b) {
        if (b & 1) { res *= a; res %= mod; }
        a *= a; a %= mod; b >>= 1;
    }
    return b;
}

inline i64 get_lcm () {
    i64 res = 1;
    for (int i = 0; i <= 1e6; i++) { res *= ksm (i, cnt[i]); res %= mod; }
    return res;
}

int main () {

    return 0;
}