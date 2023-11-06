#include <iostream>

using namespace std;

const int maxn = 100005;

int n, m;

const int mod = 998244353;

namespace Task1 {

    int a[maxn];

    inline int convert (string s) {
        int res = 0;
        
        for (int i = 0; i < s.size (); i++) {
            res = res << 1 | (s[i] == '1');
        }

        return res;
    }

    inline void solve () {
        for (int i = 1; i <= n; i++) {
            string s; cin >> s;

            a[i] = convert (s);
        }


        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                res += (a[i] xor a[j]) * (a[i] xor a[j]);
                res %= 998244353;
            }
        }

        cout << res << endl;
    }

}


int main () {

    cin >> n >> m;

    if (n <= 1000) {
        Task1::solve ();
    } else {
        
    }

    return 0;
}