#include <iostream>

using i64 = long long;

const int maxn = 100005;

int n;

int fa[maxn];

namespace Subtask1 {
    int Q;

    int lastans = 0;
    inline void decode (int &l, int &r) {
        l ^= lastans; l %= n; l++;
        r ^= lastans; r %= n; r++;
        if (l > r) { std::swap (l, r); }
    }

    inline void solve () {
        std::cin >> Q;
        while (Q--) {
            int l, r; std::cin >> l >> r;
            decode (l, r);
            
            int ans = 0;

            for (int i = l; i <= r; i++) {
                int now = i;
                while (now) { 
                    if (now >= l and now <= r) { ans ++; }
                    now = fa[now]; 
                }
            }

            std::cout << ans << "\n";
            lastans = ans;
        }
    }
}

/*
复杂度又假了啊啊啊啊啊啊

呜呜呜
*/
namespace Subtask2 {
    
    int siz[maxn], son[maxn], fa[maxn], dep[maxn];
    void tree_build (int now) {
        siz[now] = 1;

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa[now]) { continue; }
            
            fa[t] = now;
            dep[t] = dep[now] + 1;
            tree_build (t);
            siz[now] += siz[t];
            if (siz[t] > siz[son[now]]) { son[now] = t; }
        }
    }

    int top[maxn], dfn[maxn], dpos, rnk[maxn], bottom[maxn];
    void tree_decomp (int now, int topnow) {
        dfn[now] = ++dpos;
        rnk[dfn[now]] = now;
        bottom[now] = dfn[now];
        top[now] = top[now];

        if (not son[now]) { return; }
        tree_decomp (son[now], topnow);
        bottom[now] = std::max (bottom[now], bottom[son[now]]);

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa[now]) { continue; }
            if (t == son[now]) { continue; }

            tree_decomp (t, t);
            bottom[now] = std::max (bottom[now], bottom[t]);
        }
    }

    template <int size, typename val_t>
    struct SegmentTree {
        struct Node {
            int ls, rs;
            val_t val;
            val_t cnt;
        } tr[size << 4];

        inline void pushUp (int now) {
            tr[now].cnt = tr[tr[now].ls].cnt + tr[tr[now].rs].cnt;
        }

        int root[size], tot;

        SegmentTree () { root = tot = 0; }

        inline int newNode (Node old = {0, 0, 0, 0}) { ns[++tot] = old; return tot; }

        void modify (int &now, int old, int l, int r, int pos, val_t val) {
            if (not now) { now = newNode (tr[old]); }

            if (l == r) {
                tr[now].val += val;
                tr[now].cnt = bool (tr[now].val);
                return;
            }

            int mid = (l + r) >> 1;
            if (pos <= mid) { modify (tr[now].ls, tr[old].ls, l, mid, pos, val); }
            else { modify (tr[now].rs, tr[old].rs, mid + 1, r, pos, val); }

            pushUp (now);
        }

        val_t query (int now, int old, int l, int r, int L, int R) {
            if (not now) { return 0; }

            if (L <= l and r <= R) { return tr[now].cnt - tr[old].cnt; }

            val_t res = 0;
            int mid = (l + r) >> 1;
            if (L <= mid) { res += query (tr[now].ls, tr[old].ls, l, mid, L, R); }
            if (R > mid) { res += query (tr[now].rs, tr[old].rs, mid + 1, r, L, R); }
            
            return res;
        }
    };

    SegmentTree<maxn, int> tr;

    inline void init () {
        tree_build (1);
        tree_decomp (1, 1);

        tr.root[0] = tr.newNode ();

        for (int i = 1; i <= dpos; i++) {
            tr.modify (tr.root[i], tr.root[i - 1], 1, dpos, rnk[i], 1);
        }
    }

    inline int subtreeCntQuery (int u, int L, int R) {
        return tr.query (tr.root[dfn[u]], tr.root[bottom[u]], 1, dpos, L, R);
    }

    int Q;

    int lastans = 0;
    inline void decode (int &l, int &r) {
        l ^= lastans; l %= n; l++;
        r ^= lastans; r %= n; r++;
        if (l > r) { std::swap (l, r); }
    }

    inline void solve () {
        std::cin >> Q;

        while (Q--) {
            
        }
    }

}

int main () {

    std::cin >> n;
    for (int i = 2; i <= n; i++) { std::cin >> fa[i]; }

    Subtask1::solve ();

    return 0;
}