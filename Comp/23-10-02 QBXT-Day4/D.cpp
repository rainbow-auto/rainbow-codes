#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int mod = 1e9 + 7;

int n;
string s;

namespace Task1 {
    
    int res;
    long long a, b; // 顾客 | 小葱

    inline bool check () {
        long long c = a + b;    
        int tot = 0, sc[20]; memset (sc, 0, sizeof (sc));
        while (c) { sc[++tot] = c % 10; c /= 10; }

        for (int i = 1; i <= tot; i++) {
            if (sc[i] != sc[tot - i + 1]) { return false; }
        }
        return true;
    }
    
    void dfs (int now) {
        if (now >= n) { if (check ()) { res ++; if (res >= mod) { res -= mod; } } return; }

        for (int i = 0; i < s.size (); i++) {
            if (now == 0 and s[i] == '0') { continue; }
            
            for (int j = 0; j < s.size (); j++) {
                if (now == 0 and s[j] == '0') { continue; }

                long long old_a = a;
                long long old_b = b;

                a = a * 10 + s[i] - '0';
                b = b * 10 + s[j] - '0';

                dfs (now + 1);

                a = old_a;
                b = old_b;
            }

        }   
    }

    inline void solve () {
        a = b = 0ll;

        res = 0;
        dfs (0);
        cout << res << endl;
    }

}

int main () {

    freopen ("sell.in", "r", stdin);
    freopen ("sell.out", "w", stdout);

    int T; cin >> T;

    while (T--) {
        cin >> n;
        cin >> s;

        Task1::solve ();
    }

    return 0;
}