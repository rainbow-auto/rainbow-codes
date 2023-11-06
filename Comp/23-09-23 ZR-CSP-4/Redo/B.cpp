#include <iostream>

using namespace std;

const int maxn = 500005;

int n;

int a[maxn];

namespace Solution {
    
    inline bool check (int mid) {
        int mx = 0;
        int mn = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            mx = max (mx, a[i]);
            mn = min (mn, a[i]);
        }

        int l = n + 1, r = 0;
        for (int i = 1; i <= n; i++) {
            if (mx - a[i] > mid) { l = min (l, i); r = max (r, i); }
        }

        int delta = mx - mid - mn;
        for (int i = l; i <= r; i++) {
            if (a[i] + delta > mx) { return false; }
        }
        
        return true;
    } 

    inline void solve () {
        int l = 0, r = 1e9;

        int ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check (mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << endl;
    }

}

int main () {

    int T; cin >> T;

    while (T--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        Solution::solve ();
    }

    return 0;
}