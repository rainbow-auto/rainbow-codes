#include <iostream>

using i64 = long long;

int main () {

    int res = 1;
    for (int i = 1; i <= 10; i++) { res *= i; }
    std::cout << res << "\n";

    return 0;
}