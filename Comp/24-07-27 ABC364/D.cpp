#include <iostream>

const int maxn = 100005;

using i64 = long long;

int n, q;

i64 a[maxn];

struct Node {
    int ls, rs;
    int sum;
} tr[maxn << 5];

int root, tot;

inline void pushUp (int now) { tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum; }

void modify (int& now, i64 l, i64 r, i64 pos, int val) {
    if (not now) { now = ++tot; }
    if (l == r) { tr[now].sum += val; return; }

    i64 mid = (l + r) >> 1;

    if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }
    if (pos > mid) { modify (tr[now].rs, mid + 1, r, pos, val); }

    pushUp (now);
}

int query (int now, i64 l, i64 r, i64 L, i64 R) {
    if (not now) { return 0; }
    if (L <= l and r <= R) { return tr[now].sum; }

    i64 mid = (l + r) >> 1;
    
    int res = 0;
    if (L <= mid) { res += query (tr[now].ls, l, mid, L, R); }
    if (R > mid) { res += query (tr[now].rs, mid + 1, r, L, R); }
    return res;
}

inline int solve (int x, int k) {
    i64 l = 0, r = 1e9;
    int len = 0;

    while (l <= r) {
        i64 mid = (l + r) >> 1;

        int cnt = query (root, -2e9, 2e9, x - mid, x + mid);

        if (cnt >= k) {
            len = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    } 

    return len;
}

int main () {

    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; modify (root, -2e9, 2e9, a[i], 1); }

    for (int i = 1; i <= q; i++) {
        int x, k; std::cin >> x >> k;
        std::cout << solve (x, k) << "\n";
    }

    return 0;
}