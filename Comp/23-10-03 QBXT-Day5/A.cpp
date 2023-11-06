#include <iostream>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

const int maxn = 100005;

#define int unsigned long long

int n, P;
int a[maxn];

namespace Task1 {

    int b[maxn];

    inline void preProcess () {
        for (int i = 1; i <= n; i++) { b[i] = 1ll << (int)(floor (log2 (a[i])) + 1ll); }
    }

    map<int, int> t;

    inline void solve () {
        preProcess ();

        t.clear ();

        int res = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                // \frac{\frac{P - a_k}{b_k} - a[j]}{b_j} = a_i

                int now = P - a[k];
                if (now % b[k]) { continue; }
                now /= b[k];
                now -= a[j];
                if (now % b[j]) { continue; }
                now /= b[j];

                if (t.count (now)) { res += t[now]; }
            }
            t[a[j]] ++;
        }   

        cout << res << endl;
    }

}

namespace Task2 {
    inline void solve () {
        int a = ::a[1];
        int b = 1ll << (int)(floor(log2(a)) + 1);
        
        if (a * b * b + a * b + a == P) { cout << 1ll * n * (n - 1) * (n - 2) / 6 << endl; }
        else { cout << 0 << endl; }
    }
}

namespace Task3 {
    const int maxv = 513;// 512
    int ti[maxv];
    int tk[maxn][maxv];

    inline int getB (int x) { return 1ll << ( (int) ( floor ( log2 (x) ) ) + 1ll ); }
    
    inline void solve () {
        memset (ti, 0, sizeof (ti));
        memset (tk, 0, sizeof (tk));
        
        for (int k = n; k >= 1; k--) {
            for (int ak = 0; ak < maxv; ak++) {
                tk[k][ak] = tk[k + 1][ak];
            }
            tk[k][a[k]] ++;
        }
        
        int res = 0;
        for (int j = 1; j <= n; j++) {
            for (int ak = 0; ak < maxv; ak++) { // 枚举a_k的值
                if (not tk[j + 1][ak]) { continue; }
                int bk = getB (ak);
                int bj = getB (a[j]);

                int now = P - ak;
                if (now % bk) { continue; }
                now /= bk;
                now -= a[j];
                if (now % bj) { continue; }
                now /= bj;

                res += tk[j + 1][ak] * ti[now];
            }   
            ti[a[j]] ++;
        }

        cout << res << endl;
    }       

}

signed main () {

    ios::sync_with_stdio (false);
    cin.tie (0);

    int T; cin >> T;

    while (T--) {
        cin >> n >> P;

        int mx = 0;
        int mn = 0x3f3f3f3f3f3f3f3f;
        for (int i = 1; i <= n; i++) { cin >> a[i]; mx = max (mx, a[i]); mn = min (mn, a[i]); }

        if (mx == mn) { Task2::solve (); }
        else if (mx <= 512) { Task3::solve (); }
        else { Task1::solve (); }
    }

    return 0;
}