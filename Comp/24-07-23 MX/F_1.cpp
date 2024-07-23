#include <iostream>
#include <vector>

const int maxn = 100005;

int n, m;

struct Set {
    struct Node {
        int ls, rs;
        int sum; 
    };
    Node tr[maxn << 8];
    int tot, root;

    void modify (int& now, int l, int r, int pos, int val) {
        if (not now) { now = ++tot; }        
        tr[now].sum += val;

        if (l == r) { return; }

        int mid = (l + r) >> 1;
        if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }
        if (pos > mid) { modify (tr[now].rs, mid + 1, r, pos, val); }
    }
    
    int kth (int now, int l, int r, int k) {
        if (not now) { return 0; }
        if (l == r) { return l; }

        int mid = (l + r) >> 1;

        int lcnt = tr[tr[now].ls].sum;
        if (k <= lcnt) { return kth (tr[now].ls, l, mid, k); }
        else { return kth (tr[now].rs, mid + 1, r, k - lcnt); }
    }

    int siz;

    inline void ins (int val) { siz ++; modify (root, 0, 1e9, val, 1); } 

    inline void del (int val) { siz --; modify (root, 0, 1e9, val, -1); }

    inline int kth (int k) { return kth (root, 0, 1e9, k); }

    inline int size () { return siz; }
};

struct Range {
    int l, r;
} rs[maxn];

std::vector <int> tr[maxn << 3];

void modify (int now, int l, int r, int L, int R, int id) {
    if (L <= l and r <= R) { tr[now].push_back (id); return; }        

    int mid = (l + r) >> 1;
    if (L <= mid) { modify (now << 1, l, mid, L, R, id); } 
    if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, id); }
}  

Set curr;
int ans = 0x3f3f3f3f;
void dfs (int now, int l, int r) {
    for (auto x : tr[now]) { curr.ins (rs[x].r - rs[x].l); }

    if (l == r) { 
        if (curr.size () >= m) { ans = std::min (ans, curr.kth (m) - curr.kth (1)); } 
    } else {
        int mid = (l + r) >> 1;
        dfs (now << 1, l, mid);
        dfs (now << 1 | 1, mid + 1, r);
    }

    for (auto x : tr[now]) { curr.del (rs[x].r - rs[x].l); }
}

int main () {

    std::cin >> n >> m;

    int mx = 0;

    for (int i = 1; i <= n; i++) { 
        int l, r; std::cin >> l >> r;
        rs[i] = Range { l, r };
        mx = std::max (mx, r);
    }

    for (int i = 1; i <= n; i++) {
        modify (1, 0, mx, rs[i].l, rs[i].r, i);
    }

    dfs (1, 0, mx);

    if (ans == 0x3f3f3f3f) { std::cout << -1 << "\n"; }
    else { std::cout << ans << "\n"; }

    return 0;
}