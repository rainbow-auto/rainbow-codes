#include <bits/stdc++.h>
#define rep(_id, _st, _ed) for (int (_id) = (_st); (_id) <= (_ed); (_id)++)
#define per(_id, _st, _ed) for (int (_id) = (_st); (_id) >= (_ed); (_id)--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 500005;

int n, m, q;
struct Range {
    int l, r;
} ops[maxn], qs[maxn];

namespace Task1 {
    constexpr int maxn = 3005;

    struct Tree {
        struct Node {
            int tg;
        } tr[maxn << 2];

        void build(int now, int l, int r) {
            if (l == r) return tr[now] = Node { l }, void(0);
            int mid = (l + r) >> 1;
            build(now << 1, l, mid);
            build(now << 1 | 1, mid + 1, r);
        }

        inline void pushdown(int now) {
            if (not tr[now].tg) return;
            tr[now << 1].tg = tr[now << 1 | 1].tg = tr[now].tg;
            tr[now].tg = 0;
        }

        void mdf(int now, int l, int r, int L, int R, int c) {
            if (L <= l and r <= R) return tr[now] = { c }, void(0);
            pushdown(now);
            int mid = (l + r) >> 1;
            if (L <= mid) mdf(now << 1, l, mid, L, R, c);
            if (R > mid) mdf(now << 1 | 1, mid + 1, r, L, R, c);
        }

        int qry(int now, int l, int r, int x) {
            if (l == r) return tr[now].tg;
            pushdown(now);
            int mid = (l + r) >> 1;
            if (x <= mid) return qry(now << 1, l, mid, x);
            else return qry(now << 1 | 1, mid + 1, r, x);
        }
    } tr;

    std::bitset<maxn> cnt;

    inline void solve() {
        rep (t, 1, q) {
            tr.build(1, 1, n);

            auto [L, R] = qs[t];
            rep (i, L, R) {
                auto [l, r] = ops[i];
                tr.mdf(1, 1, n, l, r, tr.qry(1, 1, n, l));
            }

            cnt.reset();
            rep (i, 1, n) cnt.set(tr.qry(1, 1, n, i));
            std::cout << cnt.count() << "\n";
        }
    }
}

namespace TaskA {
    std::set<std::pair<int, int>> s;

    int res[maxn];

    inline void solve() {
        rep (i, 1, n) s.insert({i, i});

        res[0] = n;
        rep (i, 1, m) {
            // for (auto [x, y] : s) db << "(" << x << " " << y << ") "; dbendl;

            res[i] = res[i - 1];
            auto [l, r] = ops[i];
        
            auto it1 = s.upper_bound({l, 0x3f3f3f3f});
            auto [l0, r0] = *std::prev(it1);

            if (r <= r0) continue;
            
            s.erase(std::prev(it1));

            for (auto it = it1; it != s.end(); it = s.erase(it)) {
                auto [l1, r1] = (*it);
                if (l1 > r) break;
                if (r < r1) {
                    s.erase(it);
                    s.insert({r + 1, r1});
                    break;
                }
                res[i]--;
            }
            s.insert({l0, r});
        }

        rep (t, 1, q) std::cout << res[qs[t].r] << "\n";
    }
}

inline void solve() {
    std::cin >> n >> m;
    rep (i, 1, m) std::cin >> ops[i].l >> ops[i].r;

    std::cin >> q;

    rep (t, 1, q) std::cin >> qs[t].l >> qs[t].r;
    
    // return Task1::solve();

    bool flgA = true;
    rep (t, 1, q) flgA &= (qs[t].l == 1);
    if (flgA) TaskA::solve();
    else Task1::solve();
}

int main() {
    fastread

    // file("ex_mo4")
    file("mo")

    solve();

    lookTime

    return 0;
}