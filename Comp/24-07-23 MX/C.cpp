#include <iostream>

const int maxn = 100005;

int n, q;

struct Node {
    int sum;
    int tag;
} tr[maxn << 4];

inline void pushUp (int now) { tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum; }

inline void update (int now, int l, int r, int val) {
    tr[now].sum += val * (r - l + 1); 
    tr[now].tag += val;
}   

inline void pushDown (int now, int l, int r) {
    if (not tr[now].tag) { return; }
    
    int mid = (l + r) >> 1;
    update (now << 1, l, mid, tr[now].tag);
    update (now << 1 | 1, mid + 1, r, tr[now].tag);
    tr[now].tag = 0;
}

void modify (int now, int l, int r, int L, int R, int val) {
    if (L <= l and r <= R) { update (now, l, r, val); return; }

    pushDown (now, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
    if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }
    pushUp (now);
}

int query (int now, int l, int r, int L, int R) {
    if (L <= l and r <= R) { return tr[now].sum; }

    pushDown (now, l, r);

    int res = 0;
    int mid = (l + r) >> 1;
    if (L <= mid) { res += query (now << 1, l, mid, L, R); }
    if (R > mid) { res += query (now << 1 | 1, mid + 1, r, L, R); }

    return res;
}

int main () {

    std::cin >> n >> q;

    while (q--) {
        int op; std::cin >> op;

        if (op == 1) {
            int l, r; std::cin >> l >> r;
            modify (1, 1, n, l, r, 1);
        } else {
            int l, r; std::cin >> l >> r;
            std::cout << query (1, 1, n, l, r) << "\n";
        }
    }

    return 0;
}