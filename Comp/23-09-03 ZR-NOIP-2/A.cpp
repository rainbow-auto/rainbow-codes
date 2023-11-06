#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>

using namespace std;

const long double eps = 1e-19;

long double x;

namespace Task1 {
    inline void solve () {
        for (int a = 1; a <= 1000; a++) {
            for (int b = 1; b <= 1000; b++) {
                if (fabs((long double) a / (long double) b - x) < eps) {
                    cout << a << " " << b << endl;
                    return;
                }
            }
        } 
    }
}

namespace Task2 {
    inline void solve () {
        for (int b = 1; b <= 1e7; b ++) {
            int a = round (x * (long double) b);

            long double c = (long double) a / b;

            if (fabs(c - x) < eps) { cout << a << " " << b << endl; return; }
        }
    }
}

// namespace Task3 {
//     bool check (int b) {
//         long double a = x * (long double) b;
//         int aa = ceil (a);
        
//         return fabs(a - (long double) aa) < eps;
//     }

//     inline void solve () {
//         int l = 0, r = 1e9;
        
//         cout << "check (3) " << check (3) << endl;  

//         int ans = 0;
//         while (l <= r) {
//             int mid = (l + r) >> 1;
//             cout << "mid = " << mid << endl;
//             if (check (mid)) {
//                 r = mid - 1;
//                 ans = mid;
//             } else {
//                 l = mid + 1;
//             }
//         }
//     }
// }

int main () {

    cin >> x;

    Task2::solve ();

    return 0;
}