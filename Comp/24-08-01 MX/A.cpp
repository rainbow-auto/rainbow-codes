#include <iostream>

const int maxn = 200005;

using i64 = long long;

int q;

struct SegTree {
    struct Info {
        i64 mx, len;

        friend Info operator + (Info a, Info b) {
            return Info { std::max (a.mx, b.mx), a.len + b.len };
        }
    };
 
    struct Node {
        Info info;
    } tr[maxn << 4];

    void modify (int now, int l, int r, int pos, i64 mx, i64 len) {
        if (l == r) {
            tr[now].info.mx += mx;
            tr[now].info.len = len; // 对len赋值
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) { modify (now << 1, l, mid, pos, mx, len); }
        if (pos > mid) { modify (now << 1 | 1, mid + 1, r, pos, mx, len); }

        tr[now].info = tr[now << 1].info + tr[now << 1 | 1].info;
    }   

    Info query (int now, int l, int r, int L, int R) {
        if (L <= l and r <= R) { return tr[now].info; }

        Info res = Info { 0, 0 };

        int mid = (l + r) >> 1;
        if (L <= mid) { res = res + query (now << 1, l, mid, L, R); }   
        if (R > mid) { res = res + query (now << 1 | 1, mid + 1, r, L, R); }

        return res;
    }
} tr;

int head, tail;   

int get_prek (i64 k) {
    int l = head, r = tail;

    int res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (tr.query (1, 1, q, head, mid).len >= k) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }

    return res;
}

int main () {
    head = 1, tail = 0;

    std::cin >> q;

    int T = q;
    while (T--) {
        int op; std::cin >> op;

        if (op == 1) {
            i64 x; std::cin >> x;
            tail++;
            tr.modify (1, 1, q, tail, x, x);

        } else if (op == 2) {
            i64 k; std::cin >> k;
            int res = get_prek (k);

            i64 pre = tr.query (1, 1, q, head, res).len;
            if (pre == k) { head = res + 1; continue; }

            tr.modify (1, 1, q, res, 0, pre - k);
            head = res;          

        } else if (op == 3) {
            i64 k; std::cin >> k;

            int res = get_prek (k);
            i64 pre = tr.query (1, 1, q, head, res).len;

            i64 ans = tr.query (1, 1, q, res, res).mx - (pre - k);
            std::cout << ans << "\n";

        } else if (op == 4) {
            std::cout << tr.query (1, 1, q, head, tail).mx << "\n";
        }
    }    

    return 0;
}