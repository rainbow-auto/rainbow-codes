#include <iostream>

using i64 = long long;

i64 a, b, c, d;

inline bool chk () {
    if ((a + b) + c == d) { return true; }
    if ((a - b) + c == d) { return true; }
    if ((a * b) + c == d) { return true; }
    
    if ((a + b) - c == d) { return true; }
    if ((a - b) - c == d) { return true; }
    if ((a * b) - c == d) { return true; }
    
    if ((a + b) * c == d) { return true; }
    if ((a - b) * c == d) { return true; }
    if ((a * b) * c == d) { return true; }

    return false;
}

int main () {

    std::cin >> a >> b >> c >> d;
    if (chk ()) { std::cout << "Yes\n"; }
    else { std::cout << "No\n"; }

    return 0;
}