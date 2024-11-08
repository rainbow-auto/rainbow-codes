#include <iostream>

using namespace std;

const int maxn = 500005;

int n;
int a[maxn];

namespace Task1 {
    inline void solve () {
        int x, y; cin >> x >> y;
        int res = 0x3f3f3f3f;

        res = min (res, x + max (0, y - 2));
        res = min (res, y + max (0, x - 2));

        cout << res << endl;
    }
}

namespace Task2 {

    inline void solve () {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++) {
            cnt1 += (a[i] == 1);
            cnt2 += (a[i] == 2);
        }

        int res = 0;

        res += cnt1;
        cnt2 -= cnt1;

        if (cnt2 <= 0) { cout << res << endl; return; }

        int delta = cnt2 / 2;
        res += delta * 2;
        cnt2 -= delta * 2;
    
        if (cnt2 <= 0) { cout << res << endl; return; }

        res += cnt2 * 2;

        cout << res << endl;
    }
}

int main () {

    int T; cin >> T;

    while (T--) {
        cin >> n;

        if (n == 1) {
            int x; cin >> x;
            cout << x << endl;
        } else if (n == 2) {
            Task1::solve ();
        } else {
            int mx = 0;
            for (int i = 1; i <= n; i++) {
                cin >> a[i];
                mx = max (mx, a[i]);
            }

            if (mx <= 2) {
                Task2::solve ();
            } else {

            }
        }
    }

    return 0;
}