#include <iostream>

inline void check (int& x, int c) {
    while (x % c == 0) { x /= c; }
}

int main () {

    int L, R; std::cin >> L >> R;

    int ans = 0;

    for (int i = L; i <= R; i++) {
        int x = i;
        check (x, 2); if (x == 1) { ans ++; continue; }
        check (x, 3); if (x == 1) { ans ++; continue; }
        check (x, 5); if (x == 1) { ans ++; continue; }
        check (x, 7); if (x == 1) { ans ++; continue; }
    }

    std::cout << ans << "\n";

    return 0;
}