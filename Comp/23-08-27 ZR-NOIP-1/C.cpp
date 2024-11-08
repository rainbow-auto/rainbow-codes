#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

const int maxn = 1000005;

#define int long long

int n;
int a[maxn];

namespace Task1 {
    void solve () {
        int mx = 0;
        int tot = (1 << n) - 1;
        for (int S = 0; S <= tot; S ++) {
            int ans = 0;
            for (int i = 0; i < n; i++) { if (S & (1 << i)) { ans ^= a[i + 1]; } }
            ans ++;
            for (int i = 0; i < n; i++) { if (not (S & (1 << i))) { ans ^= a[i + 1]; }; }
        
            mx = max (mx, ans);
        }

        cout << mx << endl;
    }
}

namespace Task2 {
    void solve () {
        int cnt0 = 0;
        int cnt1 = 0;
        for (int i = 1; i <= n; i++) {
            cnt0 += a[i] == 0;
            cnt1 += a[i] == 1;
        }    

        int ans = 0;
        if (cnt0) {
            ans = max (ans, (cnt1 + 1) % 2);
        }

        ans = max (ans, cnt1 % 2 + 1);
    
        cout << ans << endl;
    }
}

namespace Task3 {
    mt19937_64 rnd (chrono::steady_clock::now ().time_since_epoch ().count ());

    int _solve () {
        shuffle (a + 1, a + n + 1, rnd ());
        int split = rnd () % (n - 1) + 1;

        int ans = 0;    
        for (int i = 1; i <= n; i++) {
            ans ^=  a[i];
            if (i == split) { ans ++; }
        }
        return ans;
    }   

    void solve () {
        int start = clock ();

        int ans = 0;
        while (clock () - start < 800) { ans = max (ans, _solve ()); }

        cout << ans << endl;
    }
}

signed main () {

    int mx = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> a[i]; mx = max (mx, a[i]); }

    if (mx < 2) {
        Task2::solve ();
    } else if (n <= 20) {
        Task1::solve ();
    } else {
        Task3::solve ();
    }

    return 0;
}