#include <bits/stdc++.h>
#define rep(_id, _st, _ed) for (int _id = (_st); _id <= (_ed); _id++)
#define per(_id, _st, _ed) for (int _id = (_st); _id >= (_ed); _id--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s used\n";
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

using i64 = long long;

constexpr int maxn = 500005;

int n, q;
int a[maxn];

namespace Sol {
    struct Tag {
        int st, ed;
        int cnt;

        friend bool operator == (Tag a, Tag b) {
            return a.st == b.st and a.ed == b.ed and a.cnt == b.cnt;
        }
    };

    constexpr Tag $0 = { -1, -1, 0 };

    struct Tree {
        struct Node {
            Tag tg;
            std::array<std::array<int, 2>, 2> cnt;
            std::array<std::array<int, 2>, 2> mx;
            Node() {
                tg = $0;
                cnt = {};
            }
        } tr[maxn << 2];

        inline Tag compose(Tag a, Tag b) {
            if (a.st == -1) return b;
            if (b.st == -1) return a;
            Tag res = Tag { a.st, b.ed, a.cnt + b.cnt };
            if (a.ed == b.st) res.cnt--;
            return res;
        }

        inline void apply(int now, Tag tg) {
            if (tg.st == -1) return;
            std::array<std::array<int, 2>, 2> cnt1 = {};
            cnt1[0][tg.ed] = tr[now].cnt[tg.cnt & 1][tg.st ^ 1] + tr[now].cnt[(tg.cnt & 1) ^ 1][tg.st];
            cnt1[1][tg.ed] = tr[now].cnt[(tg.cnt & 1) ^ 1][tg.st ^ 1] + tr[now].cnt[tg.cnt & 1][tg.st];
            tr[now].cnt = cnt1;
            tr[now].tg = compose(tr[now].tg, tg);
        }

        inline void pushDown(int now) {
            if (tr[now].tg.st == -1) return;
            apply(now << 1, tr[now].tg);
            apply(now << 1 | 1, tr[now].tg);
            tr[now].tg = $0;
        }

        inline void pushUp(int now) {
            tr[now].cnt[0][0] = tr[now << 1].cnt[0][0] + tr[now << 1 | 1].cnt[0][0];
            tr[now].cnt[0][1] = tr[now << 1].cnt[0][1] + tr[now << 1 | 1].cnt[0][1];
            tr[now].cnt[1][0] = tr[now << 1].cnt[1][0] + tr[now << 1 | 1].cnt[1][0];
            tr[now].cnt[1][1] = tr[now << 1].cnt[1][1] + tr[now << 1 | 1].cnt[1][1];
        }

        void build(int now, int l, int r, Tag v) {
            if (l > r) return;

            if (l == r) {
                tr[now].tg = v;
                tr[now].cnt[v.cnt & 1][v.ed] = 1;
                return;
            } 

            int mid = (l + r) >> 1;
            build(now << 1, l, mid, v);
            build(now << 1 | 1, mid + 1, r, v);
            pushUp(now);
        }

        void mdf(int now, int l, int r, int L, int R, Tag tg) {
            if (l > r) return;
            if (L > R) return;

            if (L <= l and r <= R) return apply(now, tg), void(0);
            pushDown(now);
            int mid = (l + r) >> 1;
            if (L <= mid) mdf(now << 1, l, mid, L, R, tg);
            if (R > mid) mdf(now << 1 | 1, mid + 1, r, L, R, tg);
            pushUp(now);
        }

        Tag qry(int now, int l, int r, int pos) {
            if (l > r) return $0;
            if (pos > r) return $0;
            
            if (l == r) return tr[now].tg;
            pushDown(now);
            int mid = (l + r) >> 1;
            if (pos <= mid) return qry(now << 1, l, mid, pos);
            else return qry(now << 1 | 1, mid + 1, r, pos); 
        }

        int qry(int now, int l, int r, int L, int R, int b) {
            if (l > r) return 0;
            if (L > R) return 0;
            
            // db << "now: " << now << " | " << l << ", " << r << "\n";
            // db << tr[now].cnt[0][0] << " " << tr[now].cnt[0][1] << " | " << tr[now].cnt[1][0] << " " << tr[now].cnt[1][1] << "\n";
            
            if (L <= l and r <= R) return tr[now].cnt[b][0] + tr[now].cnt[b][1];
            pushDown(now);
            int mid = (l + r) >> 1;
            if (R <= mid) return qry(now << 1, l, mid, L, R, b);
            if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R, b);
            return qry(now << 1, l, mid, L, R, b) + qry(now << 1 | 1, mid + 1, r, L, R, b);
        }
    } tr[2];

    inline int calc(int org, Tag tg) {
        if (tg == $0) return org;
        return org - (tg.cnt - 1);

        // if (org & 1) {
        //     if (tg.st == 0) tg.cnt--;
        //     return org - tg.cnt;
        // } else {
        //     if (tg.st == 1) tg.cnt--;
        //     return org - tg.cnt;
        // }
    }

    std::array<std::vector<int>, 2> c;
    inline int qryL(int v, int b) {
        int l = 0, r = (int) c[b].size() - 1;
        int res = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int cnow = calc(c[b][mid], tr[b].qry(1, 0, (int) c[b].size() - 1, mid));
            if (cnow < v) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res + 1;
    }

    inline int qryR(int v, int b) {
        int l = 0, r = (int) c[b].size() - 1;
        int res = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            i64 cnow = calc(c[b][mid], tr[b].qry(1, 0, (int) c[b].size() - 1, mid));
            if (cnow > v) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res - 1;
    }

    inline void display(int b) {
        db << b << ": ";
        rep (i, 0, (int) c[b].size() - 1) {
            db << calc(c[b][i], tr[b].qry(1, 0, (int) c[b].size() - 1, i)) << " ";
        }
        dbendl
    }

    inline void display_cnt(int b) {
        db << b << ": ";
        rep (i, 0, (int) c[b].size() - 1) {
            db << tr[b].qry(1, 0, (int) c[b].size() - 1, i).cnt << " ";
        }
        dbendl
    }

    inline void solve() {
        std::sort(a + 1, a + n + 1);
        c[0].push_back(-1e9);
        c[1].push_back(-1e9);
        rep (i, 1, n) c[a[i] & 1].push_back(a[i]);
        c[0].push_back(1e9);
        c[1].push_back(1e9);
        
        tr[0].build(1, 0, (int) c[0].size() - 1, Tag { 1, 1, 1 });
        tr[1].build(1, 0, (int) c[1].size() - 1, Tag { 0, 0, 1 });

        dbg(c[0].size());
        dbg(c[1].size());

        i64 ans = 0;
        rep (i, 1, n) ans += a[i];

        // display(0);
        // display(1);
        // db << "##########\n";

        int tot = 0;

        while (q--) {
            int l, r, op; std::cin >> l >> r >> op;
            // db << l << " " << r << " " << op << "\n";
             
            int l0 = qryL(l, 0); 
            int r0 = qryR(r, 0);

            // tot++;
            // if (tot <= 5)  db << "0rg: " << l0 << " " << r0 << "\n";

            int l1 = qryL(l, 1);
            int r1 = qryR(r, 1);
            // if (tot <= 5) db << "1rg: " << l1 << " " << r1 << "\n";

            if (l0 <= r0) ans -= tr[0].qry(1, 0, (int) c[0].size() - 1, l0, r0, op ^ 1);
            // dbg(tr[0].qry(1, 0, (int) c[0].size() - 1, l0, r0, op ^ 1));
            if (l1 <= r1) ans -= tr[1].qry(1, 0, (int) c[1].size() - 1, l1, r1, op);
            // dbg(tr[1].qry(1, 0, (int) c[1].size() - 1, l1, r1, op));
            std::cout << ans << "\n";

            if (l0 <= r0) tr[0].mdf(1, 0, (int) c[0].size() - 1, l0, r0, Tag {op, op, 1});
            if (l1 <= r1) tr[1].mdf(1, 0, (int) c[1].size() - 1, l1, r1, Tag {op, op, 1});

            // db << "after: \n";
            // display(0);
            // display(1);
            // db << "cnt: \n";
            // display_cnt(0);
            // display_cnt(1);
            // if (tot <= 5) db << "--------------\n";
        }
    }
}

namespace Task0 {
    inline void solve() {
        while (q--) {
            int l, r; std::cin >> l >> r;
            bool op; std::cin >> op;

            rep (i, 1, n) if (l <= a[i] and a[i] <= r) {
                if ((a[i] & 1) == op) {
                    a[i]--;
                }
            }

            i64 sum = 0;
            rep (i, 1, n) sum += a[i];
            std::cout << sum << "\n"; 
        }
    }
}

inline void solve() {
    std::cin >> n >> q;
    rep (i, 1, n) std::cin >> a[i];

    // if (n <= 2000) return Task0::solve(), void(0);

    Sol::solve();
}

int main() {
    fastread

    // file("uzu3")

    solve();

    lookTime

    return 0;
}