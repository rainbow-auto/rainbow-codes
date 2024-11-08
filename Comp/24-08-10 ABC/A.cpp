#include <iostream>

int main () {

    int n, t, k;
    std::cin >> n >> t >> k;

    if (t > (n >> 1)) { std::cout << "Yes\n"; return 0; }
    if (k > (n >> 1)) { std::cout << "Yes\n"; return 0; }

    std::cout << "No\n";

    return 0;
}