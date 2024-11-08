#include <iostream>

int main () {

    int y; std::cin >> y;

    if (y % 4 != 0) {
        std::cout << 365 << "\n";
    } else if (y % 4 == 0 and y % 100 != 0) {
        std::cout << 366 << "\n";
    } else if (y % 100 == 0 and y % 400 != 0) {
        std::cout << 365 << "\n";
    } else {
        std::cout << 366 << "\n";
    }

    return 0;
}