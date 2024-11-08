#include <iostream>

const int maxn = 200005;

int n, q;

struct Node {
    int sum;
    bool tag;
} tr[maxn << 4];

inline void rev (int now, int l, int r) {
    tr[now].tag ^= 1;
    tr[now].sum = (r - l + 1) - tr[now].sum;
}

inline void pushDown (int now, int l, int r) {
    if (not tr[now].tag) { return; }
    
    int mid = (l + r) >> 1;
    rev (now << 1, l, mid);
    rev (now << 1 | 1, mid + 1, r);
    tr[now].tag = false;
}

inline void pushUp (int now) { tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum; }

void modify (int now, int l, int r, int L, int R) {
    if (L <= l and r <= R) { rev (now, l, r); return; }

    pushDown (now, l, r);

    int mid = (l + r) >> 1;
    if (L <= mid) { modify (now << 1, l, mid, L, R); }
    if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R); }

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
        if (op == 0) {
            int l, r; std::cin >> l >> r;
            modify (1, 1, n, l, r);
        } else if (op == 1) {
            int l, r; std::cin >> l >> r;
            std::cout << query (1, 1, n, l, r) << "\n";
        }
    }

    return 0;
}
