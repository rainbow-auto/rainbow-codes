#include <iostream>

using i64 = long long;

const int maxn = 200005;

int n, q;
i64 a[maxn];

namespace Task0 {
    inline bool chk (i64 x, i64 y, i64 z) { return ((x + y > z) and (x + z > y) and (y + z > x)); }

    inline i64 query (int l, int r) {
        i64 res = 0;
        for (int i = l; i <= r; i++) {
            for (int j = i + 1; j <= r; j++) {
                for (int k = j + 1; k <= r; k++) {
                    if (chk (a[i], a[j], a[k])) { res = std::max (res, a[i] + a[j] + a[k]); }
                }
            }
        }
        return res;
    }   

    inline void solve () {
        while (q--) {
            int op; std::cin >> op;

            if (op == 0) {
                int pos; std::cin >> pos;
                i64 val; std::cin >> val;                

                a[pos] = val;
            } else {
                int l, r; std::cin >> l >> r;

                std::cout << query (l, r) << "\n";
            }
        }
    }
}

int main () {

    freopen ("triangle.in", "r", stdin);
    freopen ("triangle.out", "w", stdout);

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    Task0::solve ();

    return 0;
}