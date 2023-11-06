#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1000005;

int n;
int a[maxn];

namespace Task1 {

    const int maxn = 15;

    int res;
    vector<int> chosen;

    vector<int> mex;

    void dfs (int now) {
        if (now == chosen.size ()) { int xorSum = 0; for (auto x : mex) { xorSum ^= x; } res = max (res, xorSum); return; }

        int t[maxn]; memset (t, 0, sizeof (t));
        for (int i = now; i < chosen.size (); i++) {
            t[chosen[i]] ++;

            int mexNow = 0;
            for (int j = 0; j <= 6; j++) {
                if (not t[j]) { mexNow = j; break; }
            }

            mex.push_back (mexNow);
            
            dfs (i + 1);

            mex.pop_back ();
        }
    }   

    void solve () {
        int ans = 0;
        for (int S = 0; S < (1 << n); S++) {
            chosen.clear ();
            for (int i = 1; i <= n; i++) {
                if (S & (1 << (i - 1))) {
                    chosen.push_back (a[i]);
                }
            }

            dfs (0);
            ans = max (ans, res);
        }

        cout << ans << endl;
    }
}

int main () {

    freopen ("mexor.in", "r", stdin);
    freopen ("mexor.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Task1::solve ();

    return 0;
}