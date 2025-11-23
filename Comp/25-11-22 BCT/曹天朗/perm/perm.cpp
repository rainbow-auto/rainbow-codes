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

constexpr int maxn = 1005;

int n, q;
int p[maxn];
i64 c[maxn];

namespace Task1 {
    struct DSU {
        int fa[maxn];
        int L[maxn], R[maxn];
        inline void init(int n) {
            rep (i, 1, n) fa[i] = L[i] = R[i] = i;
        }

        int find(int x) {
            if (fa[x] == x) return x;
            return fa[x] = find(fa[x]);
        }

        inline void mrg(int u, int v) {
            u = find(u); v = find(v);
            if (u == v) return;
            fa[v] = u;
            L[u] = std::min(L[u], L[v]);
            R[u] = std::max(R[u], R[v]);
        }
    } dsu;

    std::vector<int> ls[maxn];
    inline int calc() {
        dsu.init(n);
        rep (i, 1, n) {
            // [i, p[i]]
            dsu.mrg(i, p[i]);
            int l = i, r = p[i];
            if (l > r) std::swap(l, r);
            ls[r].push_back(l);
        }
        
        i64 cur = n;
        rep (i, 1, n) if (dsu.fa[i] == i) cur--;

        i64 ans = cur;
        rep (i, 1, n) {
            cur -= ls[i].size();
            if (i == dsu.R[dsu.find(i)]) cur++;
            ans = std::min(ans, c[i] + cur);
        }
        
        rep (i, 1, n) std::exchange(ls[i], {});

        return ans;
    }

    inline void solve() {
        std::cout << calc() << "\n";

        while (q--) {
            int op; std::cin >> op;
            if (op == 1) {
                int x, y; std::cin >> x >> y;
                std::swap(p[x], p[y]);
            } else {
                int l, r, v; std::cin >> l >> r >> v;
                rep (i, l, r) c[i] += v;
            }

            std::cout << calc() << "\n";
        }
    }
}

inline void solve() {
    std::cin >> n >> q;
    rep (i, 1, n) std::cin >> c[i];
    rep (i, 1, n) std::cin >> p[i];

    Task1::solve();
}

int main() {
    fastread

    file("perm")

    solve();

    return 0;
}