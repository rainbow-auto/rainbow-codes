#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

const int maxn = 10005;

int n;
int a[maxn];

namespace Task1 {
    inline void solve () {
        int tot = (1 << n) - 1;

        int ans = 0x3f3f3f3f;

        for (int S = 0; S <= tot; S++) {
            deque<int> q;
            for (int i = 1; i <= n; i++) {
                if (S & (1 << (i - 1))) { q.push_front(a[i]); }
                else { q.push_back (a[i]); }
            }

            int res = 0;
            int last = q.front (); q.pop_front ();
            while (not q.empty ()) { int now = q.front (); q.pop_front (); res = max (res, abs (now - last)); last = now; }

            ans = min (ans, res);
        }

        cout << ans << endl;
    }
}

int main () {

    cin >> n;

    for (int i = 1; i <= n; i++) { cin >> a[i]; }

    Task1::solve ();

    return 0;
}