#include <iostream>
#include <cstdlib>
#include <chrono>

inline bool pai () {
    system ("A_gen.exe > A.in");

    system ("A_1.exe < A.in > A_1.out");
    system ("A_2.exe < A.in > A_2.out");

    if (system ("fc A_1.out A_2.out")) {
        return false;
    }

    return true;
}

inline void getTime () {
    system ("A_gen.exe > A.in");
    
    auto s = std::chrono::steady_clock::now ();
    system ("A_2.exe < A.in > A_2.out");
    auto t = std::chrono::steady_clock::now ();

    auto duration = std::chrono::duration_cast <std::chrono::microseconds> (t - s); 

    double cost = (double) duration.count () / 1000;

    std::cout << cost << "\n";
}

int main () {

    // int tot = 0;
    // while (pai ()) {
    //     std::cout << "Accepted " << (++tot) << "\n";
    // }

    getTime ();

    return 0;
}