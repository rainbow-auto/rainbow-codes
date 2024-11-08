#include <iostream>

int T;

int a_min, a_max;
int b_min, b_max;

inline bool check () {
    if (b_min <= a_min and a_min <= b_max) { return true; }
    if (b_min <= a_max and a_max <= b_max) { return true; }
    if (a_min <= b_min and b_min <= a_max) { return true; }
    if (a_min <= b_max and b_max <= a_max) { return true; }

    return false;
}

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> a_min >> b_min;

        a_max = 0, b_max = 0;

        for (int i = 1; i <= a_min; i++) { int now; std::cin >> now; a_max += now; }
        for (int i = 1; i <= b_min; i++) { int now; std::cin >> now; b_max += now; }

        std::cout << ((a_max > b_min) ? "Y" : "N");
        std::cout << (check () ? "Y" : "N");
        std::cout << ((b_max > a_min) ? "Y" : "N");
        std::cout << "\n";
    }

    return 0;
}