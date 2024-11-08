#include <iostream>

inline bool pai () {
    system ("B_gen.exe > B.in");
    system ("B_1.exe < B.in > B_1.out");
    system ("B_2.exe < B.in > B_2.out");

    if (system ("fc B_1.out B_2.out")) { std::cout << "Wrong Answer\n"; return false; }
    return true;
}

int main () {

    int cnt = 0;
    while (pai ()) { std::cout << "Accepted " << (++cnt) << "\n"; }

    return 0;
}