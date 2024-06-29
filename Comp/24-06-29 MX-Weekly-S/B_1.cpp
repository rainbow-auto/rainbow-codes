#include <iostream>

using i64 = long long;

const int maxn = 2000005;

int n, q;
int a[maxn];

int siz;

struct Tree {
    i64 tr[maxn];

    inline int lowbit (int x) { return x & (-x); }

    inline void add (int pos, i64 val) { 
        if (pos == 0) { return; }
        for (int i = pos; i <= siz; i += lowbit (i)) { tr[i] += val; } 
    }
    
    inline i64 _query (int pos) { 
        if (pos == 0) { return 0; }
        i64 res = 0; for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; } return res; 
    }

    inline i64 query (int l, int r) { 
        if (l > r) { return 0; }
        return _query (r) - _query (l - 1); 
    }
} tr1, tr2;

int cnt[maxn];

int main () {

    std::ios::sync_with_stdio (false); std::cin.tie (0);

    std::cin >> n >> q;

    siz = n + q + 1;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; cnt[a[i]] ++; }

    for (int i = 1; i <= n; i++) {
        tr1.add (cnt[i], cnt[i]);
        tr2.add (cnt[i], 1);
    }

    while (q--) {
        int op; std::cin >> op;

        if (op == 1) {
            int x; std::cin >> x;
            if (cnt[x]) { tr1.add (cnt[x], -cnt[x]); tr2.add (cnt[x], -1); }
            cnt[x]++;
            tr1.add (cnt[x], cnt[x]);
            tr2.add (cnt[x], 1);
        } else if (op == 2) {
            int x; std::cin >> x;
            tr1.add (cnt[x], -cnt[x]);
            tr2.add (cnt[x], -1);
            cnt[x]--;
            if (cnt[x]) { tr1.add (cnt[x], cnt[x]); tr2.add (cnt[x], 1); }
        } else {
            int k; std::cin >> k;
            i64 res = tr1.query (k + 1, siz) - tr2.query (k + 1, siz) * k;
            std::cout << res << "\n";
        }
    }

    return 0;
}