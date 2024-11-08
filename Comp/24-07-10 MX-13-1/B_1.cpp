#include <iostream>

using i64 = long long;

int n, k;

namespace Task2 {
    inline void solve () {
        if ((n - 1) & 1) { std::cout << -1 << "\n"; }
    }
}

int main () {

    freopen ("Btree.in", "r", stdin);
    freopen ("Btree.out", "w", stdout);

    std::ios::sync_with_stdio (false);

    std::cin >> n >> k;

    Task2::solve ();

    return 0;
}