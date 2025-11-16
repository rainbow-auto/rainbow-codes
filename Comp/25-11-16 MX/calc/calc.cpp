#include <bits/stdc++.h>
#define rep(_id, _st, _ed) for (int (_id) = (_st); (_id) <= (_ed); (_id)++)
#define per(_id, _st, _ed) for (int (_id) = (_st); (_id) >= (_ed); (_id)--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);
#define lookTime std::cerr << (1.0 * clock() / CLOCKS_PER_SEC) << "s used\n";

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int maxn = 500005;

using Range = std::pair<i64, i64>;
constexpr i64 inf = i64(1e18);
constexpr Range $0 = { -inf, inf };

int n, q;
i64 a[maxn];

// struct Edge {
//     int v;
//     std::pair<i64, i64> rg;
// };

// std::vector<Edge> g[maxn];

struct Edge {
    int u, v;
    int pre;
    Range rg;
} es[maxn];

int last[maxn], cnt;

inline void addEdge(int u, int v, Range rg) {
    es[++cnt] = Edge { u, v, last[u], rg };
    last[u] = cnt;
}

namespace Sol {
    Range f[maxn];
    i128 sum[maxn];
    int fa[maxn];

    void dfs(int now) {
        // for (auto [t, rg] : g[now]) {
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            auto rg = es[i].rg;

            f[t] = { std::max((i128) f[now].first, (rg.first - sum[now])), std::min((i128) f[now].second, (rg.second - sum[now])) };
            sum[t] = sum[now] + a[t];
            fa[t] = now;
            dfs(t);
        }
    }

    struct Tree {
        struct Node {
            int ls, rs;
            int sum;
        } tr[maxn << 6];

        int rt, tot;

        inline void pushUp(int now) {
            tr[now].sum = 0;
            if (tr[now].ls) tr[now].sum += tr[tr[now].ls].sum;
            if (tr[now].rs) tr[now].sum += tr[tr[now].rs].sum;
        }

        void mdf(int &now, i64 l, i64 r, i64 pos, int v) {
            if (not now) now = ++tot;
            if (l == r) return tr[now].sum += v, void(0);
            i64 mid = (l + r) >> 1;
            if (pos <= mid) mdf(tr[now].ls, l, mid, pos, v);
            else mdf(tr[now].rs, mid + 1, r, pos, v);
            pushUp(now);
        }

        int qry(int now, i64 l, i64 r, i64 L, i64 R) {
            if (not now) return 0;
            if (L <= l and r <= R) return tr[now].sum;
            i64 mid = (l + r) >> 1;
            if (R <= mid) return qry(tr[now].ls, l, mid, L, R);
            if (L > mid) return qry(tr[now].rs, mid + 1, r, L, R);
            return qry(tr[now].ls, l, mid, L, R) + qry(tr[now].rs, mid + 1, r, L, R);
        }
    } tr;

    inline void solve() {
        rep (i, 1, n) f[i] = $0;
        sum[1] = a[1];
        dfs(1);

        rep (i, 1, n) {
            if (f[i].first > f[i].second) continue;
            tr.mdf(tr.rt, -inf, inf, f[i].first, 1);
            if (f[i].second < inf) tr.mdf(tr.rt, -inf, inf, f[i].second + 1, -1);
        }

        while (q--) {
            i64 x; std::cin >> x;
            std::cout << tr.qry(tr.rt, -inf, inf, -inf, x) << "\n";
        }

        lookTime
    }
}

inline void solve() {
    std::cin >> n >> q;
    rep (i, 2, n) {
        int p; std::cin >> p;
        i64 l, r; std::cin >> l >> r;
        // g[p].push_back(Edge{i, {l, r}});
        addEdge(p, i, {l, r});
    }

    rep (i, 1, n) {
        char op; std::cin >> op;
        std::cin >> a[i];
        if (op == '-') a[i] *= -1ll;
    }

    Sol::solve();
}

int main() {
    fastread

    file("calc3")

    solve();
    
    return 0;
}