#include <iostream>
#include <cstdlib>

using i64 = long long;

inline bool check () {
    system ("A_gen.exe > reverse.in");

    system ("A.exe");
    system ("A_1.exe");

    if (system ("fc reverse.ans reverse_task1.ans")) {
        return false;
    }
    return true;
}

int main () {

    while (check ()) { std::cout << "Accepted\n"; }

    return 0;
}