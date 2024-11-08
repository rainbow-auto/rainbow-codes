#include <iostream>

using i64 = long long;

int c, n, m, q;

namespace Subtask1 {
    inline void solve () {
        std::cout << 1;
        while (q--) { std::cout << 1; }
    }
}

namespace Subtask2 {
    int a[5];
    int b[5];
    
    inline bool check () {
        return (a[1] - b[1] < 0 and a[2] - b[2] < 0) or (a[1] - b[1] > 0 and a[2] - b[2] > 0);
    }

    inline void solve () {
        for (int i = 1; i <= n; i++) { std::cin >> a[i]; } a[n + 1] = a[n];
        for (int i = 1; i <= m; i++) { std::cin >> b[i]; } b[m + 1] = b[m];

        if (check ()) { std::cout << 1; }
        else { std::cout << 0; }

        while (q--) {
            int kx; std::cin >> kx;
            int ky; std::cin >> ky;
            
            for (int i = 1; i <= kx; i++) { int p, v; std::cin >> p >> v; a[p] = v; }
            for (int i = 1; i <= ky; i++) { int p, v; std::cin >> p >> v; b[p] = v; }

            if (check ()) { std::cout << 1; }
            else { std::cout << 0; }
        }
    }
}

int main () {

    std::cin >> c >> n >> m >> q;

    if (n == 1 and m == 1) { Subtask1::solve (); return 0; }

    if (n <= 2 and m <= 2) { Subtask2::solve (); return 0; }

    return 0;
}