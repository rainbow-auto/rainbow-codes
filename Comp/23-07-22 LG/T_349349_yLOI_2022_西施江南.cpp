#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

#define int long long

using namespace std;

const int maxn = 500005;

int T;
int n;
int a[maxn];


namespace Baoli {

    int gcd (int a, int b) {if (b == 0) {return a;} else {return gcd (b, a % b);}}

    int lcm (int a, int b) {return a * b / gcd (a, b);}

    void solve () {
        int mul = 1;
        for (int i = 1; i <= n; i++) {
            mul *= a[i];
        }
        
        int l = lcm (a[1], a[2]), g = gcd(a[1], a[2]);
        for (int i = 3; i <= n; i++) {
            l = lcm (l, a[i]);
            g = gcd (g, a[i]);
        }

        if (l * g == mul) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

}

namespace Luangao {
    int mod1 = 114514114529;
    int mod2 = 19198101919819;
    int mod3 = 1000000007;

    int mod;

    int ksm (int x, int y) {
        int base = x; 
        int res = 1;

        while (y) {
            if (y & 1) {(res *= base) ;res %= mod;}
            base *= base;
            y >>= 1;
        } 

        return res;
    }

    int gcd (int a, int b) {if (b == 0) {return a;} else {return gcd (b, a % b);}}

    int lcm (int a, int b) {return a * b * ksm (gcd (a, b), mod - 2);}

    bool _solve () {
        int mul = 1;
        for (int i = 1; i <= n; i++) {
            (mul *= a[i]);
            mul %= mod;
        }
        
        int l = lcm (a[1], a[2]), g = gcd(a[1], a[2]);
        for (int i = 3; i <= n; i++) {
            l = lcm (l, a[i]);
            g = gcd (g, a[i]);
        }

        if (l * g == mul) return true;
        else return false;
    }

    void solve () {
        bool res = true;
        mod = mod1; res &= _solve();
        mod = mod2; res &= _solve();
        mod = mod3; res &= _solve();

        if (res) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

signed main () {
	fastread
    
    cin >> T;

    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        // if (n <= 10) {
        //     Baoli::solve();
        // } else {
            Luangao::solve();
        // }
    }

	return 0;
}
