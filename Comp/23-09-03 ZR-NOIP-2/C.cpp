#include <iostream>

using namespace std;

int x, p;
int n;

namespace Task1 {
    inline void solve () {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                for (int c = 1; c <= n; c++) {
                    if (a * b + b * c + a * c == n) { cout << a << " " << b << " " << c << endl; return; }
                }
            }
        }
        cout << -1 << endl;
    }
}

namespace Task2 {
    
    const double eps = 1e-9;
    inline bool check (double now) {
        int temp = now;
        return now - (double) temp < eps;
    }

    inline void solve () {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                double c =  double (n - a * b) / double (a + b);
                if (check (c) and c > eps) { cout << a << " " << b << " " << c << endl; return; }
            }
        }

        cout << -1 << endl;
    }
}

int main () {

    int T; cin >> T;

    while (T--) {
        cin >> x >> p;
        n = x * p * p;
        
        // if (n <= 100) { Task1::solve (); }
        // else if (n % 2 == 1) { cout << "1 1 " << (n - 1) / 2 << endl; }
        // else if (n % 3 == 2) { cout << "2 1 " << (n - 2) / 4 << endl; }
        // else if (n % 4 == 0) { cout << "2 2 " << (n - 4) / 4 << endl; }
        // else if (n % 5 == 6) { cout << "3 2 " << (n - 6) / 4 << endl; }
        // else if (n % 7 == 12) { cout << "4 3 " << (n) }
        // else { cout << -1 << endl; }

        Task2::solve ();
    }


    return 0;
}