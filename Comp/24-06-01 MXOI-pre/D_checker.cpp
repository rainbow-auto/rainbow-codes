#include <iostream>
#include <cstdlib>

inline void display () {
    freopen ("D.in", "r", stdin); 
    
    int n; std::cin >> n;
    std::cout << n << "\n"; 

    for (int i = 1; i <= n; i++) { int x; std::cin >> x; std::cout << x << " "; }
    std::cout << "\n";
}

inline bool pai () {
    // Generate
    system ("D_gen.exe > D.in");
    
    display ();

    // Run
    system ("D_1.exe < D.in > D_1.out");
    system ("D_2.exe < D.in > D_2.out");

    if (system ("fc D_1.out D_2.out")) {
        system ("pause");
        return false;
    }

    return true;
}


int main () {

    int cnt = 0;

    while (pai ()) {
        std::cout << "Accepted " << (++cnt) << "\n";
    }

    return 0;
}