#include <iostream>

using i64 = long long;

i64 a, b, r, v, m;

int main () {

    std::cin >> a >> b >> r >> v >> m;

    std::cout << 1ll * 2 * a * 2 * r + 1ll * b * r << " ";
    std::cout << 1ll * 2 * a * 3 * v + 1ll * b * v << " ";
    std::cout << 1ll * 2 * a * 3 * m + 1ll * b * m << "\n";
    
    return 0;
}