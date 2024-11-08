#include <iostream>

using i64 = long long;

inline bool pai () {
    system ("B_gen.exe > calc.in");

    system ("B.exe");
    system ("B_1.exe");

    if (system ("fc calc.out calc_task0.out")) { return false; }
    return true;
}

int main () {

    while (pai ()) {
        std::cout << "Accepted\n";
    }

    return 0;
}