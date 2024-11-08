// USING TASK0 !!!!

#include <iostream>
#include <vector>

using i64 = unsigned long long;

const int maxk = 105;

i64 n, k;
i64 a[maxk];

std::vector <i64> p;

inline void get_p (i64 x) {
    for (i64 i = 2; i <= x; i++) {
        if (x % i) { continue; } 

        p.push_back (i);

        while (x % i == 0) { x /= i; }
    }
}

namespace Task0 {
    inline void solve () {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int j = 1; j <= k; j++) {
                if (i % a[j] == 0) { flag = false; break; }
            }
            res += flag;
        }

        std::cout << res << "\n";
    }
}

namespace Task1 {
    inline bool get (i64 x, int pos) { return x & (1ll << pos); }

    inline void solve () {
        i64 res = 0;

        for (int S = 0; S <= ((1ll << p.size ()) - 1); S++) {
            int cnt = 0;
            i64 now = 1;

            for (int i = 0; i < p.size (); i++) {
                if (get (S, i)) { 
                    now *= p[i]; 
                    cnt ++; 
                    if (now * p[i] > n) { goto End; } 
                }
            }

            res += ((cnt & 1) ? -1 : 1) * (i64 (n / now));

            End: ;
        }

        std::cout << res << "\n";
    }
}

int main () {

    freopen ("calc.in", "r", stdin);
    freopen ("calc_task0.out", "w", stdout);

    std::cin >> n >> k;

    for (int i = 1; i <= k; i++) { std::cin >> a[i]; get_p (a[i]); }

    Task0::solve ();

    return 0;
}