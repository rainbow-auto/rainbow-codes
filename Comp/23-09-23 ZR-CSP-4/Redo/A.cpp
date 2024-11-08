#include <iostream>
#include <set>

using namespace std;

const int maxn = 500005;

int n;
int a[maxn];

namespace Solution {

    inline void solve () {
        multiset<int> s;

        for (int i = 1; i <= n; i++) {
            s.insert (a[i]);
        }

        int res = 0;

        while (not s.empty ()) {
            auto mn = s.begin ();
            res += *mn;
            s.erase (mn); if (s.empty ()) { break; }

            auto mx = s.end(); mx--; s.erase (mx);
            int hurt = *mx - 2;
            if (hurt > 0) { s.insert (hurt); }
        }

        cout << res << endl;
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