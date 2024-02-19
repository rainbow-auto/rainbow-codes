#include <iostream>

using i64 = long long;

const int maxn = 200005;

int T;

int n;
int a[maxn];

i64 m;

struct Node {
    i64 mul;
} tr[maxn << 2];

inline void pushUp (int now) { tr[now].mul = (tr[now << 1].mul % m * tr[now << 1 | 1].mul % m) % m; }

void build (int now, int l, int r) {
    if (l == r) { tr[now].mul = a[l]; return; }

    int mid = (l + r) >> 1;
    build (now << 1, l, mid);
    build (now << 1 | 1, mid + 1, r);
    pushUp (now);
}

i64 query (int now, int l, int r, int L, int R) {
    if (L <= l and r <= R) { return tr[now].mul % m; }

    i64 res = 1;

    int mid = (l + r) >> 1;
    if (L <= mid) { res *= query (now << 1, l, mid, L, R); res %= m; }
    if (R > mid) { res *= query (now << 1 | 1, mid + 1, r, L, R); res %= m; }

    return res % m;
}

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n >> m;

        for (int i = 1; i <= n; i++) { std::cin >> a[i]; a[i] %= m; }

        build (1, 1, n);

        std::string s; std::cin >> s;

        int posL = 1, posR = n;
        for (auto op : s) {
            std::cout << query (1, 1, n, posL, posR) << " ";
            if (op == 'L') { posL ++; }
            if (op == 'R') { posR --; }
        }

        std::cout << "\n";
    }

    return 0;
}