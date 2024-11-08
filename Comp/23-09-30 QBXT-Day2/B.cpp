#include <iostream>
#include <vector>

using namespace std;

const int maxn = 505;

int n, k;
int a[maxn];

namespace Task0 { // 瞎写的

    int ans = 0x3f3f3f3f;

    int merged;
    int fa[maxn];
    int val[maxn];

    inline void init () {
        for (int i = 1; i <= n; i++) { fa[i] = i; val[i] = a[i]; }
    }

    int find (int x) {
        if (fa[x] != x) { return fa[x] = find (fa[x]); }
        return fa[x];
    }

    inline void merge (int x, int y) {
        val[find (x)] ^= val[find (y)];
        fa[find (y)] = find (x);
    }

    vector<int> chosen;
    void dfs () {
        if (merged == n - 1) { int sum = 0; for (auto now : chosen) { sum += now; } ans = min (ans, sum); return; }

        for (int i = 1; i + k - 1 <= n; i++) {
            int passed = 0;
            int sum = 0;
            for (int r = i + 1; r <= n; r ++) {
                if (find (r) != find (r - 1)) {
                    sum ^= val[find (r)];
                    passed ++;
            
                    if (passed >= k) { break; }
                }
            }

            merged += k;

            dfs ();
        }
    }

    inline void solve () {
        init ();
    }

}

namespace Task1 {

    const int maxn = 15;

    int a[maxn], a_len;

    int res = 0x3f3f3f3f;
    vector <int> chosen;
    inline void dfs () {
        if (a_len == 1) { int resnow = 0; for (auto now : chosen) { resnow += now; } res = min (res, resnow); return; }

        for (int i = 1; i + k - 1 <= a_len; i ++) {
            int val = 0; for (int j = i; j <= i + k - 1; j++) { val ^= a[j]; }

            int old_a[maxn];
            memcpy (old_a, a, sizeof (a));
            chosen.push_back (val);

            for (int j = 1; j <= a_len; j++) { cout << old_a[j] << " "; } cout << "-> ";

            a[i] = val;
            int id = i + 1;
            for (int j = i + k - 1 + 1; j <= a_len; j++) {
                a[++id] = a[j];
            }
            a_len = id - 1;

            for (int j = 1; j <= a_len; j++) { cout << a[j] << " "; } cout << endl;

            dfs ();

            chosen.pop_back ();
            memcpy (a, old_a, sizeof (old_a));
        }       
    }   

    inline void solve () {
        for (int i = 1; i <= n; i++) { a[i] = ::a[i]; }
        a_len = n;
        dfs ();
        cout << res << endl;
    }

}

namespace Task2 { // 瞎写的
    
    int dp[maxn][maxn];

    vector<int> dividers;

    int res;
    void dfs (int now, int pos, int L, int R) {
        if (now > k) {
            int resnow = 0;

            int last = L;
            for (auto divider : dividers) {
                resnow ^= dp[last][divider];    
                last = divider;
            }

            res = min (res, resnow);

            return;
        }

        if (R - pos + 1 < k - now) { return; } // 可行性剪枝

        for (int i = pos; i <= R; i++) {
            dividers.push_back (i);

            dfs (now + 1, i + 1, L, R);            

            dividers.pop_back();
        }

    }

    inline int divide (int L, int R) {
        res = 0x3f3f3f3f;
        dfs (1, L, L, R);
        return res;        
    }

    inline void solve () {

        for (int i = 1; i <= n; i++) { dp[i][i] = a[i]; }

        for (int len = 2; len <= n; len ++) {
            for (int l = 1; l + len - 1 <= n; l ++) {
                int r = l + len - 1;

                dp[l][r] = divide (l, r);
            }
        }

        cout << dp[1][n] << endl;
    }

}

int main () {

    cin >> n >> k;

    for (int i = 1; i <= n; i++) { cin >> a[i]; }

    Task1::solve ();

    return 0;
}
