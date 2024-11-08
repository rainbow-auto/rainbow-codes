#include <iostream>

int T;

int main () {

    std::cin >> T;

    while (T--) {
        int x1, x2, x; std::cin >> x1 >> x2 >> x;

        if (x1 <= x and x <= x2) { std::cout << "YES\n"; }
        else if (x2 <= x and x <= x1) { std::cout << "YES\n"; }
        else { std::cout << "NO\n"; }
    }

    return 0;
}
