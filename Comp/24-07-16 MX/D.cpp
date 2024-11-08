#include <iostream>
#include <set>

using i64 = long long;

const int maxT = 100005;

i64 n, k;

namespace Task1 {
    const int maxn = 100005;
    std::set <int> vis;

    inline void solve () {
        vis.clear ();
        int pos = 0;

        while (true) {
            int sum = 0;
            for (int i = 1; i <= k; i++) {
                pos ++;

                int now = 1; while (vis.count (now)) { now ++; }
                vis.insert (now); sum += now;

                if (now == n) { std::cout << pos << "\n"; return; }   
            }

            pos ++;
            vis.insert (sum);

            if (sum == n) { std::cout << pos << "\n"; return; }
        }
    }
}

int main () {

    freopen ("array.in", "r", stdin);
    freopen ("array.out", "w", stdout);

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n >> k;
        Task1::solve ();
    }

    return 0;
}