#include <iostream>

using i64 = long long;

int n;

inline bool check (int x) {
    int x1 = x % 10; if (x) { x /= 10; }
    int x2 = x % 10; if (x) { x /= 10; }
    int x3 = x % 10; if (x) { x /= 10; }

    return x2 * x3 == x1;
}

int main () {

    std::cin >> n;

    for (int now = n; now <= 999; now++) {
        if (check (now)) { std::cout << now << "\n"; break; }
    }

    return 0;
}