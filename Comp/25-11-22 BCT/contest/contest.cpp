#include <bits/stdc++.h>
#define rep(_id, _st, _ed) for (int _id = (_st); _id <= (_ed); _id++)
#define per(_id, _st, _ed) for (int _id = (_st); _id >= (_ed); _id--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s used\n";
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

using i64 = long long;

constexpr int maxn = 200005;

int n;
int a[maxn];

struct Tree {
    struct Node {
        int sum;
    } tr[maxn << 2];
    
    inline void pushUp(int now) {
        tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
    }

    void build(int now, int l, int r) {
        if (l == r) return tr[now] = Node { 1 }, void(0);
        int mid = (l + r) >> 1;
        build(now << 1, l, mid);
        build(now << 1 | 1, mid + 1, r);
        pushUp(now);
    }

    void mdf(int now, int l, int r, int pos) {
        if (l == r) return tr[now].sum = 0, void(0);
        int mid = (l + r) >> 1;
        if (pos <= mid) mdf(now << 1, l, mid, pos);
        else mdf(now << 1 | 1, mid + 1, r, pos);
        pushUp(now);
    }

    int qry(int now, int l, int r, int x) {
        if (l == r) return l;
        int mid = (l + r) >> 1;
        if (tr[now << 1 | 1].sum < x) return qry(now << 1, l, mid, x - tr[now << 1 | 1].sum);
        else return qry(now << 1 | 1, mid + 1, r, x);
    }
} tr;

int p[maxn];

inline void solve() {
    std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];

    tr.build(1, 1, n);

    db << "kkkk\n";

    rep (i, 1, n) {
        int pos = tr.qry(1, 1, n, a[i] + 1);
        tr.mdf(1, 1, n, pos);
        p[pos] = i;
    }

    rep (i, 1, n) std::cout << p[i] << " ";
    std::cout << "\n";
} 

int main() {
    fastread

    // file("contest")

    solve();

    return 0;
}