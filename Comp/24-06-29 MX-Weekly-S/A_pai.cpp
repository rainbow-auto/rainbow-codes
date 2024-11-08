#include <iostream>
#include <cstdlib>

inline bool pai () {
    system ("A_gen.exe > A.in");
    
    system ("A.exe < A.in > A.out");
    system ("A_2.exe < A.in > A_2.out");

    if (system ("fc A.out A_2.out")) { return false; }

    return true;
}

int main () {

    while (pai ()) { std::cout << "Accepted\n"; }

    return 0;
}