#include <iostream>
#include <vector>
#include <algorithm>

#pragma GCC Optimize(3)

#define db(x) std::cerr << #x << ": " << x << "\n";

using i64 = long long;

const int maxn = 30005;

int n;
int a[maxn];

namespace Task0 {

    inline void (solve ()) {
        std::vector <int> curr;

        i64 ans = 0;

        for (int l = 1; l <= n; l++) {
            curr.clear ();
            
            for (int r = l; r <= n; r++) {
                curr.push_back (a[r]);
                std::sort (curr.begin (), curr.end ());
                
                ans += curr[((curr.size () + 1) >> 1) - 1];

                // db (l);
                // db (r);
                // db (curr[((curr.size () + 1) >> 1) - 1]);
            }
        }

        std::cout << ans << "\n";
    }
}

namespace Task1 {
    
    struct SegTree {
        struct Node {
            int ls, rs;
            i64 sum;
        } tr[maxn << 5];

        int rt[maxn], tot;

        void modify (int& now, int old, int l, int r, int pos, int val) {
            now = ++tot;
            tr[now] = tr[old];

            tr[now].sum += val;

            if (l == r) { return; }

            int mid = (l + r) >> 1;
            if (pos <= mid) { modify (tr[now].ls, tr[old].ls, l, mid, pos, val); }
            else { modify (tr[now].rs, tr[old].rs, mid + 1, r, pos, val); }
        }

        int query (int now, int old, int l, int r, int k) {
            if (not now) { return 0; }
            if (l == r) { return l; }

            int mid = (l + r) >> 1;

            int lcnt = tr[tr[now].ls].sum - tr[tr[old].ls].sum;

            if (k <= lcnt) { return query (tr[now].ls, tr[old].ls, l, mid, k); }
            else { return query (tr[now].rs, tr[old].rs, mid + 1, r, k - lcnt); }
        }
    } tr;

    inline int kth (int L, int R, int k) {
        return tr.query (tr.rt[R], tr.rt[L - 1], 1, n, k);
    }

    inline void solve () {
        tr.rt[0] = ++tr.tot;
        for (int i = 1; i <= n; i++) { tr.modify (tr.rt[i], tr.rt[i - 1], 1, n, a[i], 1); }

        i64 ans = 0;
        for (int l = 1; l <= n; l++) {
            for (int r = l; r <= n; r++) {
                int len = r - l + 1;

                ans += kth (l, r, ((len + 1) >> 1));
            }
        } 

        std::cout << ans << "\n";
    }
}

int main () {

    freopen ("random.in", "r", stdin);
    freopen ("random.out", "w", stdout);

    std::ios::sync_with_stdio (false); std::cin.tie (0);

    std::cin >> n;
    
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    // Task0::solve ();

    Task1::solve ();

    return 0;
}