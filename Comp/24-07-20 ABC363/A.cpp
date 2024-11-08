#include <iostream>

int cnt (int now) {
    if (now >= 1 and now <= 99) { return 1; }
    if (now >= 100 and now <= 199) { return 2; }
    if (now >= 200 and now <= 299) { return 3; }
    if (now >= 300 and now <= 399) { return 4; }
}

int main () {

    int r; std::cin >> r;
    
    int now = cnt (r);

    int ans = 0;
    while (cnt (r) != now + 1) { ans ++; r++; }

    std::cout << ans << "\n";

    return 0;
}