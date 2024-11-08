#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define int long long

const int mod = 1145141;

int frac[mod + mod + 5];

namespace Solution {

    inline void preProcess () {
        frac[0] = 1;

        for (int i = 1; i <= mod; i++) {
            frac[i] = frac[i - 1] * i % mod;
        }
    }

    inline int ksm (int a, int b) {
        int base = a;
        int res = 1;

        while (b) {
            if (b & 1) {
                res = res * base % mod;
            }

            b >>= 1;
            base = base * base % mod;
        }

        return res;
    }

    inline int inv (int x) {
        return ksm (x, mod - 2);
    }   

    inline void solve (int d, int n, int a) {
        d %= mod, a %= mod;

        if (d == 0) { cout << ksm (a, n) << endl; return; }
        if (n >= mod) { cout << 0 << endl; return; }

        a = a * inv (d) % mod;
        
        // cout << "a: " << a << endl;
        // cout << a + n - 1 << ": " << frac[a + n - 1] << endl;
        // cout << a - 1 << ": " << frac[a - 1] << endl;
        // cout << "ksm(" << d << ", " << n << "): " << ksm (d, n) << endl;

        int res = frac[a + n - 1] * inv (frac[a - 1]) % mod * ksm (d, n) % mod;

        cout << res << endl;
    }   

}

signed main () {

    // freopen("sequence.in", "r", stdin);
	// freopen("sequence.out", "w", stdout);

    Solution::preProcess ();

    int T; cin >> T;

    while (T--) {
        int d, n, a;
        cin >> d >> n >> a;
        
        Solution::solve (d, n, a);
    }

    return 0;
}