#include <iostream>

using namespace std;

const int mod = 998244353;

int n;
long long a1, a2, b1, b2;

long long gcd (long long a, long long b) {
    if (a < 0) { a = -a; }
    if (b < 0) { b = -b; }

    if (b == 0) { return a; }
    else { return gcd (b, a % b); }
}

namespace Task1 {

    const int maxn = 505;
    long long f[maxn];
    int last = 3;

    inline void solve () {
        f[0] = f[1] = f[2] = 1;

        for (; last <= n + 1; last++) {
            f[last] = f[last - 1] - 2ll * f[last - 3];
        }

        cout << gcd (a1 * f[n] + a2 * f[n + 1], b1 * f[n] + b2 * f[n + 1]) % mod << endl;
    }

}

int main () {

    int T; cin >> T;

    while (T--) {
        cin >> n;
        cin >> a1 >> a2 >> b1 >> b2;
        
        Task1::solve ();
    }


    return 0;
}