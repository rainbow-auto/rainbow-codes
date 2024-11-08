#include <iostream>

#pragma GCC Optimize(3)

const int maxn = 200005;

using i64 = long long;

int id, T;
int n, m;
i64 L;

i64 d[maxn];

namespace TaskA {

    inline void solve () {
        i64 l = 0, r = 1e10;
        i64 res = 0;

        while (l <= r) {
            i64 mid = (l + r) >> 1;
            
            i64 sum = 0;
            for (int i = 1; i <= m; i++) {
                if (d[i] <= mid) { sum += mid - d[i]; }
            }

            if (sum <= L) { res = mid; l = mid + 1; }
            else { r = mid - 1; }
        }

        std::cout << res << "\n";
    }
}

int main () {

    freopen ("wildfire.in", "r", stdin);
    freopen ("wildfire.out", "w", stdout);

    std::cin >> id >> T;

    while (T--) {
        std::cin >> n >> m >> L; 
        for (int i = 1; i <= m; i++) {
            int u, v; std::cin >> u >> v >> d[i];
        }

        if (m == n - 1) { TaskA::solve (); }
    }

    return 0;
}