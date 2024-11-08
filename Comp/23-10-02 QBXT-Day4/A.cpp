#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1005;
const long long mod = 1e9 + 7;

int n;
long long a[maxn];

namespace Util { // 假
    long long gcd (long long a, long long b) {
        if (not b) { return a; }
        else { return gcd (b, a % b); }
    }

    inline long long ksm (long long a, long long b) {
        long long base = a;
        long long res = 1;
        while (b) {
            if (b & 1) {
                res *= base;
                res %= mod;
            }
            b >>= 1;
            base *= base;
            base %= mod;
        }

        return res;
    }

    inline long long inv (long long x) {
        return ksm (x, mod - 2);
    } 
}

namespace Fake {
    void solve () {
        using namespace Util;

        sort (a + 1, a + n + 1);
        n = unique (a + 1, a + n + 1) - a - 1;

        long long g = 1;
        for (int i = 1; i <= n; i++) { g = gcd (g, a[i]); }

        for (int i = 1; i <= n; i++) { a[i] *= inv (g); }

        cout << "gcd = " << g << endl;

        int lcm = 1;
        for (int i = 1; i <= n; i++) { lcm *= a[i]; lcm %= mod; }
        
        cout << lcm << endl;
    }   
}

namespace Task1 {
    inline bool check (long long lcm) {
        for (int i = 1; i <= n; i++) {
            if (lcm % a[i]) { return false; }
        }
        return true;
    }

    inline void solve () {
        long long lcm = 1;

        while (not check (lcm)) {
            lcm ++;
        }

        cout << lcm << endl;
    }
}

int main () {

    freopen ("buy.in", "r", stdin);
    freopen ("buy.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> a[i]; }

    Task1::solve ();

    return 0;
}