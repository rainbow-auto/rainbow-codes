#include <iostream>

using i64 = long long;

const int maxn = 500005;

int n, q;

int a[maxn];

struct Node {
    int lval, rval;
    bool isGood;
    bool cov, tag;
} tr[maxn << 4];

inline void merge (Node& x, Node a, Node b) {
    x.isGood = (a.rval != b.lval) and a.isGood and b.isGood;
    x.lval = a.lval; x.rval = b.rval;
}

inline void pushUp (int now) { merge (tr[now], tr[now << 1], tr[now << 1 | 1]); }

inline void update (int now) {
    tr[now].lval ^= 1; tr[now].rval ^= 1;

    if (tr[now].cov) { tr[now].tag ^= 1; }   
    else { tr[now].cov = true; tr[now].tag = true; }
}

inline void pushDown (int now) {
    if (not tr[now].cov) { return; }
    update (now << 1);
    update (now << 1 | 1);
    tr[now].tag = false; tr[now].cov = false;
}

void build (int now, int l, int r) {
    tr[now].lval = a[l]; tr[now].rval = a[r];
    if (l == r) { tr[now].isGood = true; tr[now].tag = tr[now].cov = false; return; }
    
    int mid = (l + r) >> 1;
    build (now << 1, l, mid);
    build (now << 1 | 1, mid + 1, r);
    
    pushUp (now);
}

void rev (int now, int l, int r, int L, int R) {
    if (L <= l and r <= R) { update (now); return; }

    pushDown (now);

    int mid = (l + r) >> 1;
    if (L <= mid) { rev (now << 1, l, mid, L, R); }
    if (R > mid) { rev (now << 1 | 1, mid + 1, r, L, R); }

    pushUp (now);
}

Node query (int now, int l, int r, int L, int R) {
    if (L <= l and r <= R) { return tr[now]; }

    pushDown (now);

    int mid = (l + r) >> 1;
    if (R <= mid) { return query (now << 1, l, mid, L, R); }
    if (L > mid) { return query (now << 1 | 1, mid + 1, r, L, R); }

    Node x; merge (x, query (now << 1, l, mid, L, R), query (now << 1 | 1, mid + 1, r, L, R)); return x;
}

int main () {
    
    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        char c; std::cin >> c; 
        if (c == '0') { a[i] = 0; }
        else { a[i] = 1; }
    }

    build (1, 1, n);

    while (q--) {
        int op, l, r; std::cin >> op >> l >> r;

        if (op == 1) {
            rev (1, 1, n, l, r);
        } else if (op == 2) {
            Node res = query (1, 1, n, l, r);
            if (res.isGood) { std::cout << "Yes\n"; }
            else { std::cout << "No\n"; }
        }
    }

    return 0;
}