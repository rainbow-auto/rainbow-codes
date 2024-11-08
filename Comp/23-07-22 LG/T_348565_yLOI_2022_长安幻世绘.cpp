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

using namespace std;

const int maxn = 100005;

int n, m;
int a[maxn];

namespace BIT_min {
    int tr[maxn];

    inline int lowbit (int x) {return x & (-x);} 

    inline void change (int pos, int val) {
        for (int i = pos; i <= n; i += lowbit(i)) {
            tr[i] += val;
        }
    }

    inline int query (int pos) {
        int res = 0x3f3f3f3f;
        for (int i = pos; i; i -= lowbit(i)) {
            res = min (res, tr[i]);
        }
        return res;
    }
}

namespace BIT_max {
    int tr[maxn];
    int n;

    inline int lowbit (int x) {return x & (-x);} 

    inline void change (int pos, int val) {
        for (int i = pos; i <= n; i += lowbit(i)) {
            tr[i] += val;
        }
    }

    inline int query (int pos) {
        int res = 0;
        for (int i = pos; i; i -= lowbit(i)) {
            res = max (res, tr[i]);
        }
        return res;
    }
}

namespace Task36 {
    const int maxn = 1005;

    // set<int> s[maxn][maxn];
    set<int> s[1005][1005];

    inline void solve () {
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int ansnow = 0x3f3f3f3f;
                
                int choice = 0;
                
                for (int k = i - 2; k >= 1; k--) {
                    int mx = max (s[k][j - 1].empty() ? -0x3f3f3f3f : *s[k][j - 1].rbegin(), a[i]);
                    int mn = min (s[k][j - 1].empty() ? 0x3f3f3f3f : *s[k][j - 1].begin(), a[i]);

                    if (ansnow > mx - mn) {
                        ansnow = mx - mn;
                        choice = k;
                    }
                }

                s[i][j].insert (a[i]);
                s[i][j].insert (s[choice][j - 1].begin(), s[choice][j - 1].end());
            }
        }

        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            int mx = *s[i][m].rbegin();
            int mn = *s[i][m].begin();

            ans = min (ans, mx - mn);
        }

        cout << ans << endl;
    }
}

namespace Task4 {
    void solve() {
        int mx_0 = 0, mn_0 = 0x3f3f3f3f;
        int mx_1 = 0, mn_1 = 0x3f3f3f3f;
        
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0 and n == 2 * m) {
                mx_0 = max (mx_0, a[i]);                
                mn_0 = max (mn_0, a[i]);                
            } else if (i % 2 == 1 and n == 2 * m) {
                mx_1 = max (mx_1, a[i]);                
                mn_1 = max (mn_1, a[i]);                
            }
        }

        int ans = min (mx_0 - mn_0, mx_1 - mn_1);

        cout << ans << endl;
    }
}

namespace Task12 {
    void solve () {
        int ans = 0x3f3f3f3f;
        int len = 2 * m - 1;

        for (int l = 1; l + len - 1 <= n; l ++) {
            int r = l + len - 1;
            ans = min (ans, a[r] - a[l]);
        }

        cout << ans << endl;
    }
}

int main () {
//	fastread
	
    cin >> n >> m;

    bool flag4 = true;
    bool flag12 = true;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        if (a[i] < a[i - 1]) {flag12 = true;}
    }

    if (flag12) {Task12::solve();}
    // else if (2 * m + 1 == n or 2 * m - 1 == n) {Task4::solve();}
    else {Task4::solve();}

	return 0;
}
