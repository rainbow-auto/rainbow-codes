#include <bits/stdc++.h>
#define rep(_i, _st, _ed) for (int (_i) = (_st); (_i) <= (_ed); (_i)++)
#define per(_i, _st, _ed) for (int (_i) = (_st); (_i) >= (_ed); (_i)--)
#define file(name) std::freopen(name".in", "r", stdin); std::freopen(name".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
#define db std::cerr
#define dbendl std::cerr << "\n";
#define lookTime db << (1.0 * clock() / CLOCKS_PER_SEC) << "s used\n";
#define dbg(x) db << (#x) << ": " << x << "\n";

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int maxn = 1000005;
constexpr int maxq = 50005;

int n, q;
struct Query {
    int op;
    int l, r;
    int x;
};
std::vector<Query> qs;

i64 a[maxn];

namespace Task1 {
    i64 pre[maxn];
    i64 suf[maxn];

    inline void solve() {
        for (auto [op, l, r, x] : qs) {
            if (op == 1) {
                pre[l - 1] = -1e18;
                rep (i, l, r) pre[i] = std::max(pre[i - 1], a[i]);
                suf[r + 1] = -1e18;
                per (i, r, l) suf[i] = std::max(suf[i + 1], a[i]);

                i64 res = -1e18;
                rep (i, l + 1, r - 1) {
                    if (pre[i - 1] + suf[i + 1] >= 2ll * a[i]) {
                        res = std::max(res, pre[i - 1] + suf[i + 1] + a[i]);
                    }
                }

                if (res == -1e18) std::cout << "No\n";
                else std::cout << res << "\n";
            } else if (op == 2) {
                rep (i, l, r) a[i] += x;
            }
        }
    }
}

namespace Sol {
    constexpr i64 inf = 1e18;

    using info = std::pair<i64, int>;

    struct Tree {
        struct Node {
            info mx;
            i64 tag;
        } tr[maxn << 2];

        inline void pushUp(int now) {
            tr[now].mx = std::max(tr[now << 1].mx, tr[now << 1 | 1].mx);
        }

        inline void apply(int now, i64 x) {
            tr[now].mx.first += x;
            tr[now].tag += x;
        }

        inline void pushDown(int now) {
            if (not tr[now].tag) return;
            apply(now << 1, tr[now].tag);
            apply(now << 1 | 1, tr[now].tag);
            tr[now].tag = 0;
        }

        void build(int now, int l, int r) {
            if (l == r) return tr[now] = { {a[l], l}, 0 }, void(0);
            int mid = (l + r) >> 1;
            build(now << 1, l, mid);
            build(now << 1 | 1, mid + 1, r);
            pushUp(now);
        }

        info qry(int now, int l, int r, int L, int R) {
            if (L > R) return { -inf, 0 };
            if (L <= l and r <= R) return tr[now].mx;
            pushDown(now);
            int mid = (l + r) >> 1;
            if (R <= mid) return qry(now << 1, l, mid, L, R);
            if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R);
            return std::max(qry(now << 1, l, mid, L, R), qry(now << 1 | 1, mid + 1, r, L, R));
        }        

        void mdf(int now, int l, int r, int L, int R, i64 x) {
            if (L <= l and r <= R) return apply(now, x), void(0);
            pushDown(now);
            int mid = (l + r) >> 1;
            if (L <= mid) mdf(now << 1, l, mid, L, R, x);
            if (R > mid) mdf(now << 1 | 1, mid + 1, r, L, R, x);
            pushUp(now);
        }
     
        info operator[](int x) {
            return qry(1, 1, n, x, x);
        }

        info operator[](std::pair<int, int> x) {
            auto [l, r] = x;
            return qry(1, 1, n, l, r);
        }
    } tr;

    inline i64 calc_x(i64 vmx, int l, int r) {
        if (l >= r) return -inf;
        auto [vm1, m1] = tr[{l + 1, r}];
        i64 res = -inf;
        // y \in (l, m1)
        if (l + 1 <= m1 - 1) res = std::max(res, vmx + tr[{l + 1, m1 - 1}].first + vm1);

        // y = m1
        if (m1 == r) return res;

        auto [z, nxt] = tr[{m1 + 1, r}];
        if (2ll * vm1 <= vmx + z) {
            res = std::max(res, vmx + vm1 + z);
            return res;
        }

        res = std::max(res, calc_x(vmx, m1, r));
        return res;
    }

    inline i64 calc_z(i64 vmx, int l, int r) {
        if (l >= r) return -inf;
        auto [vm1, m1] = tr[{l, r - 1}];
        i64 res = -inf;
        // y \in (l, m1)
        if (m1 + 1 <= r - 1) res = std::max(res, vmx + tr[{m1 + 1, r - 1}].first + vm1);
        // y = m1
        if (m1 == l) return res;

        auto [z, nxt] = tr[{l, m1 - 1}];
        if (2ll * vm1 <= vmx + z) {
            res = std::max(res, vmx + vm1 + z);
            return res;
        }

        res = std::max(res, calc_z(vmx, l, m1));
        return res;
    }

    inline void solve() {
        tr.build(1, 1, n);

        for (auto [op, l, r, x] : qs) {
            if (op == 1) {
                auto [mx, pos] = tr[{l, r}];
                i64 xx = calc_x(mx, pos, r);
                i64 zz = calc_z(mx, l, pos);
                i64 res = std::max(xx, zz);
                if (res == -inf) std::cout << "No\n";
                else std::cout << res << "\n";
            } else {
                tr.mdf(1, 1, n, l, r, x);
            }
        }   
    }
}

inline void solve() {
    std::cin >> n >> q;
    rep (i, 1, n) std::cin >> a[i];
 
    while (q--) {
        int op; std::cin >> op;
        int l, r; std::cin >> l >> r;
        if (op == 1) {
            qs.push_back(Query{ 1, l, r, 0 });
        } else if (op == 2) {
            int x; std::cin >> x;
            qs.push_back(Query{ 2, l, r, x });
        }
    }

    // Task1::solve();
    Sol::solve();

    lookTime
}

int main() {
    fastread

    // file("triple2");
    
    solve();
    return 0;
}