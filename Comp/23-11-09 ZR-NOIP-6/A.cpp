#include <iostream>

using i64 = long long;

const int maxn = 5005;

int n;
int a[maxn];

namespace Reader {
    template <int T>
    struct fast_io {
        char p[T], *p1, *p2;
        fast_io() {
            p1 = p2 = p;
            fread(p, 1, T, stdin);    
        }
        char gc() {
            return *p1++;
        }

    };
    fast_io<110'000'000> io;
    int read() {
        int r = 0, neg = 1;
        char ch;
        do ch = io.gc();while (ch < 48 || ch > 57);
        do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
        return r;
    }
}

namespace Subtask1 {

    template<int size, typename val_t>
    struct SegmentTree {
        struct Node {
            val_t mn;
        } tr[size << 3];

        inline void pushUp (int now) { tr[now].mn = std::min (tr[now << 1].mn, tr[now << 1 | 1].mn); }

        void build_tree (int now, int l, int r) {
            if (l == r) {
                tr[now].mn = a[l];
                return;
            }

            int mid = (l + r) >> 1;
            build_tree (now << 1, l, mid);
            build_tree (now << 1 | 1, mid + 1, r);
            pushUp (now);
        }   

        val_t query (int now, int l, int r, int L, int R) {
            if (L <= l and r <= R) { return tr[now].mn; }

            val_t res = 0x3f3f3f3f;
            int mid = (l + r) >> 1;
            if (L <= mid) { res = std::min (res, query (now << 1, l, mid, L, R)); }
            if (R > mid) { res = std::min (res, query (now << 1 | 1, mid + 1, r, L, R)); }

            return res;
        }
    };

    SegmentTree<maxn, int> tr;

    int querys[maxn][maxn];

    inline void solve () {
        // tr.build_tree (1, 1, n);

        for (int l = 1; l <= n; l++) {
            int min_now = 0x3f3f3f3f;
            for (int r = l; r <= n; r++) {
                min_now = std::min (min_now, a[r]);
                querys[l][r] = min_now;
            }
        }

        int ans = 0;
        for (int r = 1; r <= n; r ++) {
            for (int l = r - 1; l >= 1; l--) {
                int mid = (l + r) / 2 + 1;
                if (querys[l][r] == querys[mid][r]) {
                    ans ++;
                }
            }
        }

        std::cout << ans << "\n";
    }
}

int main () {

    std::ios::sync_with_stdio (false); std::cin.tie (0);
 
    n = Reader::read ();
    for (int i = 1; i <= n; i++) { a[i] = Reader::read (); }
    
    Subtask1::solve ();

    return 0;
}