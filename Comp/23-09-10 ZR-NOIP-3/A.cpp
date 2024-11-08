#include <iostream>

using namespace std;

const int maxn = 1000005;

int n, m;
int a[maxn];

namespace Task0 {

    inline void solve () {
        while (m --) {
            int l, r; cin >> l >> r;

            int ans = 0;
            for (int i = l; i <= r; i++) {
                for (int j = i + 1; j <= r; j++) {
                    if (a[i] > a[j]) { ans ++; }
                }
            }

            cout << ans << endl;
        }        
    }
}

namespace Task1 {
    struct Node {
        int val;
        int lc, rc;
    } tr[55 * maxn];

    int rt[maxn], tot;

    inline int cloneNode (int id) {
        tr[++tot] = tr[id];
        return tot;
    }

    inline void pushUp (int x) { tr[x].val = tr[tr[x].lc].val + tr[tr[x].rc].val; }

    void makeTree (int &now, int l, int r) {
        now = ++tot;
        
        if (l == r) {
            tr[now].val = 0;    
            return;
        }
        
        int mid = (l + r) >> 1;
        makeTree (tr[now].lc, l, mid);
        makeTree (tr[now].rc, mid + 1, r);
    
        pushUp (now);
    }


    void change (int &now, int old, int l, int r, int pos, int val) {
        now = cloneNode (old);

        if (l == r) {
            tr[now].val += val;
            return;
        }

        int mid = (l + r) >> 1;

        if (pos <= mid) { change (tr[now].lc, tr[now].lc, l, mid, pos, val); }
        else { change (tr[now].rc, tr[now].rc, mid + 1, r, pos, val); }

        pushUp (now);
    }

    int query (int now, int l, int r, int L, int R) {
        if (l == r) { return tr[now].val; }
        if (L <= l and r <= R) { return tr[now].val; }

        int mid = (l + r) >> 1;

        int res = 0;
        if (L <= mid) { res += query (tr[now].lc, l, mid, L, R); }
        if (R > mid)  { res += query (tr[now].rc, mid + 1, r, L, R); }
        return res;
    }

    void solve () {
        makeTree (rt[0], 0, 50);

        for (int i = 1; i <= n; i++) { change (rt[i], rt[i - 1], 0, 50, a[i], 1); }

        while (m --) {
            int l, r; cin >> l >> r;

            int ans = 0;
            for (int i = l; i <= r; i++) {
                ans += query (rt[i], 0, 50, a[i] + 1, 50) - query (rt[l - 1], 0, 50, a[i] + 1, 50);
            }
            cout << ans << endl;
        }
    }

}

namespace Task2 {
    
    int cnt[maxn][55];
    int scnt[maxn][55];
    int s2[maxn];

    void solve () {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 50; j++) {
                cnt[i][j] = cnt[i - 1][j];
            }
            cnt[i][a[i]] ++;
        
            for (int j = 50; j >= 0; j--) {
                scnt[i][j] = scnt[i][j + 1] + cnt[i][j];
            }
        }

        while (m --) {
            int l, r; cin >> l >> r;

            int ans = 0;
            for (int i = l; i <= r; i++) {
                ans += scnt[i][a[i] + 1] - scnt[l - 1][a[i] + 1];
            }

            cout << ans << endl;
        }
    }
}

int main () {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) { cin >> a[i]; }

    Task2::solve ();

    return 0;
}