#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 500005;

using i64 = long long;

int n, m;

struct Set {
    struct Node {
        int ls, rs;
        int sum; 
    };
    Node tr[maxn << 8];
    int tot, root;

    void modify (int& now, i64 l, i64 r, i64 pos, int val) {
        if (not now) { now = ++tot; }        
        tr[now].sum += val;

        if (l == r) { return; }

        int mid = (l + r) >> 1;
        if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }
        if (pos > mid) { modify (tr[now].rs, mid + 1, r, pos, val); }
    }
    
    i64 kth (int now, i64 l, i64 r, int k) {
        if (not now) { return 0; }
        if (l == r) { return l; }

        i64 mid = (l + r) >> 1;

        int lcnt = tr[tr[now].ls].sum;
        if (k <= lcnt) { return kth (tr[now].ls, l, mid, k); }
        else { return kth (tr[now].rs, mid + 1, r, k - lcnt); }
    }

    int siz;

    inline void ins (i64 val) { siz ++; modify (root, 0, 1e9, val, 1); } 

    inline void del (i64 val) { siz --; modify (root, 0, 1e9, val, -1); }

    inline i64 kth (int k) { return kth (root, 0, 1e9, k); }

    inline i64 size () { return siz; }
};

struct Range {
    i64 l, r;
    i64 len;
} rs[maxn];

std::vector <i64> tr[maxn << 3];

void modify (int now, int l, int r, int L, int R, int id) {
    if (L <= l and r <= R) { tr[now].push_back (id); return; }        

    int mid = (l + r) >> 1;
    if (L <= mid) { modify (now << 1, l, mid, L, R, id); } 
    if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, id); }
}  

Set curr;
i64 ans = 2e9;
void dfs (int now, int l, int r) {
    for (auto x : tr[now]) { curr.ins (rs[x].len); }

    if (l == r) { 
        if (curr.size () >= m) { ans = std::min (ans, curr.kth (m) - curr.kth (1)); } 
    } else {
        int mid = (l + r) >> 1;
        dfs (now << 1, l, mid);
        dfs (now << 1 | 1, mid + 1, r);
    }

    for (auto x : tr[now]) { curr.del (rs[x].len); }
}

int vals[maxn << 1], valCnt;

int main () {

    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) { 
        int l, r; std::cin >> l >> r;
        rs[i] = Range { l, r, r - l };
        
        vals[++valCnt] = l;
        vals[++valCnt] = r;
    }

    std::sort (vals + 1, vals + valCnt + 1);
    valCnt = std::unique (vals + 1, vals + valCnt + 1) - vals - 1;

    for (int i = 1; i <= n; i++) {
        rs[i].l = std::lower_bound (vals + 1, vals + valCnt + 1, rs[i].l) - vals;
        rs[i].r = std::lower_bound (vals + 1, vals + valCnt + 1, rs[i].r) - vals;
    }   

    for (int i = 1; i <= n; i++) { modify (1, 1, valCnt, rs[i].l, rs[i].r, i); }

    dfs (1, 1, valCnt);

    if (ans == 2e9) { std::cout << -1 << "\n"; }
    else { std::cout << ans << "\n"; }

    return 0;
}