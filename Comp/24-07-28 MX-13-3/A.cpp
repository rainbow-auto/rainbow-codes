#include <iostream>

const int maxn = 10005;

int n;

namespace Task1 {
    int a[maxn];

    int old_a[maxn];

    inline void op () {
        memcpy (old_a, a, sizeof (a));

        for (int i = 1; i <= n; i++) {
            a[(i << 1) - 1] = old_a[i];
            a[i << 1] = old_a[n + i];
        }
    }

    inline bool chk () {
        bool flag = true;
        for (int i = 1; i <= (n << 1); i++) { flag &= (a[i] == i); }
        return flag;
    }

    inline int solve () {
        for (int i = 1; i <= (n << 1); i++) { a[i] = i; }
        
        int ans = 0;
        do {
            ans ++;
            op ();
        } while (not chk ());

        return ans;
    }

}

#define MAKETABLE

int main () {

    #ifdef MAKETABLE

    int curr = 2;

    int pre = 0;

    for (int i = 1; i <= 500; i++) { 
        n = i; 
        int res = Task1::solve ();

        std::cerr << i << ": " << res << "\n";

        // if (res == curr) { 
        //     curr ++;
        // } else {
        //     if (i % 4 == 0) { std::cout << "#"; }
        //     if (res == i - 1) { 
        //         std::cout << i - pre << "\n"; 
        //         pre = i;
        //     }
        // }
    }
    #endif

    #ifndef MAKETABLE

    int T; std::cin >> T;

    while (T--) { 
        std::cin >> n; 
        std::cout << Task1::solve () << "\n";
    }

    #endif

    return 0;
}