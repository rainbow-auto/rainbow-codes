#include <iostream>

int T;

int xc, yc, k;

int main () {
    
    std::cin >> T;

    while (T--) {
        std::cin >> xc >> yc >> k;

        int curx = -500;
        int cury = -500;

        int sumx = 0;
        int sumy = 0;
        for (int i = 1; i <= k - 1; i++) {
            curx ++; sumx += curx;
            cury ++; sumy += cury;

            std::cout << curx << " " << cury << "\n";
        }

        std::cout << k * xc - sumx << " " << k * yc - sumy << "\n";
    }
    

    return 0;
}