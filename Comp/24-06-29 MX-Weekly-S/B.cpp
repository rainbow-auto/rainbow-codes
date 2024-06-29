#include <iostream>

using i64 = long long;

const int maxn = 2000005;

int n, q;
int a[maxn];

int cnt[maxn];

// namespace Task1 {
//     inline void solve () {
//         while (q--) {
//             int op; std::cin >> op;

//             if (op == 1) {
//                 int x; std::cin >> x;
//                 cnt[x] ++;
//             } else if (op == 2) {
//                 int x; std::cin >> x;
//                 cnt[x] --;
//             } else {
//                 int k; std::cin >> k;

//                 int ans = 0;
//                 for (int i = 1; i <= n; i++) {
//                     if (cnt[i] > k) { ans += cnt[i] - k; }
//                 }
//                 std::cout << ans << "\n";
//             }
//         }

//     }
// }

namespace Task2 {
    struct Tree {
        struct Node {
            int ls, rs;
            i64 val;
        } tr[maxn << 4];
        
        int root, tot;

        void modify (int& now, int l, int r, int pos, i64 val) {
            if (not now) { now = ++tot; }            
            
            if (l == r) {
                tr[now].val += val;
                return;
            } 

            int mid = (l + r) >> 1;
            if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }
            else { modify (tr[now].rs, mid + 1, r, pos, val); }

            tr[now].val = tr[tr[now].ls].val + tr[tr[now].rs].val;
        }

        i64 query (int now, int l, int r, int L, int R) {
            if (not now) { return 0; }
            if (L <= l and r <= R) { return tr[now].val; }

            int mid = (l + r) >> 1;

            i64 res = 0;
            if (L <= mid) { res += query (tr[now].ls, l, mid, L, R); }
            if (R > mid) { res += query (tr[now].rs, mid + 1, r, L, R); }

            return res;
        }
    } t1, t2;
    

    inline void solve () {
        for (int i = 1; i <= n; i++) {
            t1.modify (t1.root, 0, n, cnt[i], cnt[i]); 
            t2.modify (t2.root, 0, n, cnt[i], 1); 
        }
        
        while (q--) {
            int op; std::cin >> op;

            if (op == 1) {
                int x; std::cin >> x;
                t1.modify (t1.root, 0, n, cnt[x], -cnt[x]);
                t2.modify (t2.root, 0, n, cnt[x], -1);
                cnt[x] ++;
                t1.modify (t1.root, 0, n, cnt[x], cnt[x]);
                t2.modify (t2.root, 0, n, cnt[x], 1);
            } else if (op == 2) {
                int x; std::cin >> x;
                t1.modify (t1.root, 0, n, cnt[x], -cnt[x]);
                t2.modify (t2.root, 0, n, cnt[x], -1);
                cnt[x] --;
                t1.modify (t1.root, 0, n, cnt[x], cnt[x]);
                t2.modify (t2.root, 0, n, cnt[x], 1);
            } else if (op == 3) {
                int k; std::cin >> k;
                std::cout << t1.query (t1.root, 0, n, k + 1, n) - 1ll * t2.query (t2.root, 0, n, k + 1, n) * k << "\n";
            }
        }
    }
}

int main () {

    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; cnt[a[i]] ++; }

    Task2::solve ();

    return 0;
}