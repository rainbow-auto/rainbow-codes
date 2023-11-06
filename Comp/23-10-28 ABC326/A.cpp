#include <iostream>

using i64 = long long;

int x, y;

int main () {

    std::cin >> x >> y;

    if (x - y > 0) {
        if (x - y > 3) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
    } else if (y - x > 0) {
        if (y - x > 2) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
    }

    return 0;
}