#include <iostream>

using namespace std;

namespace Task1 {
    inline int solve (int n) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                for (int c = 1; c <= n; c++) {
                    if (a * b + b * c + a * c == n) { cout << a << " " << b << " " << c << endl; return true; }
                }
            }
        }
        return false;
    }
}

int main () {

    for (int b = 1; b <= 100; b ++) {
        int x = 4 * b + 2;
        if (x % 3 == 2) { continue; }
        if (Task1::solve (x)) { cout << "x = " << 4 * b + 2 << endl; return 0; }
    }   

    cout << "ok" << endl;
    
    return 0;
}