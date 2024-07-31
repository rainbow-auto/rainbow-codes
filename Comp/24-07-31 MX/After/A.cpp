#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;

const int maxn = 1000005;

i64 n;

i64 a[maxn];

i64 pw[20];
inline void init () {
    pw[0] = 1; 
    for (int i = 1; i <= 16; i++) { pw[i] = 10ll * pw[i - 1]; }
}

inline i64 f (i64 x) {
    i64 res = 0; while (x) { res += x % 10ll; x /= 10ll; }
    return res;
}

int main () {

    // freopen ("digit.in", "r", stdin);
    // freopen ("digit.out", "w", stdout);

    init ();

    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
    
    i64 ans = 0;
    for (int i = 1; i <= n; i++) { ans += 2ll * n * f (a[i]); }

    for (int d = 1; d <= 16; d++) {
        std::vector <i64> curr;
        for (int i = 1; i <= n; i++) { curr.push_back (a[i] % pw[d - 1]); }
        std::sort (curr.begin (), curr.end ());

        i64 gsum = 0;

        // a[i] % 10 ^ {d - 1} + a[j] % 10 ^ {d - 1} >= pw[d - 1] 
        // a[i] % 10 ^ {d - 1} >= pw[d - 1] - a[j] % 10 ^ {d - 1}
        for (auto now : curr) {
            gsum += curr.size () - (std::lower_bound (curr.begin (), curr.end (), pw[d - 1] - now) - curr.begin ());
        }

        ans -= 9ll * gsum;
    }    

    std::cout << ans << "\n";

    return 0;
}