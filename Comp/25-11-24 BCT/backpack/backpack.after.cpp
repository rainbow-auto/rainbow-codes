#include <bits/stdc++.h>
#define rep(_id, _st, _ed) for (int _id = (_st); _id <= (_ed); _id++) 
#define per(_id, _st, _ed) for (int _id = (_st); _id >= (_ed); _id--) 
#define db std::cerr
#define dbg(x) std::cerr << (#x) << " : " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s used\n";

using i64 = long long;

constexpr int maxn = 200005;

int n, k;
i64 E;
int a[maxn], b[maxn], v[maxn];

namespace Sol {
    using Bag = std::vector<int>;
    
    inline void add(Bag &f, int w, int v) {
        per (j, k - w, 0) f[j + w] = std::max(f[j + w], f[j] + v);
    }

    inline bool chk(const Bag &f) {
        i64 cur = 0;
        rep (i, 1, k) cur += f[k];
        return cur <= E * k;
    }

    int pos[maxn];

    inline void makeA(Bag &f, int l, int r) {
        rep (i, l, r) add(f, a[i], v[i]);
    }

    inline void makeB(Bag &f, int l, int r) {
        rep (i, l, r) add(f, b[i], v[i]);
    }

    // (l0, l1]
    void solve(int L, int R, int qL, int qR, const Bag &f) {
        if (l0 > r0) return;

        int cur = (L + R) >> 1;
        int r2 = 0;
        
        auto g = f; makeA(g, L, mid - 1); makeB(g, mid, std::min(R, qL - 1));

        int l = std::max(mid, r0), r = std::min(r1, n);
        while (l <= r) {
            int mid = (l + r) >> 1;
            auto h = g; makeA(h, l, mid);
            if (chk(h)) {
                pos[cur] = std::min(pos[cur], mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        g = f; makeB(g,, l1 - 1); makeA(g, r2 + 1, r1);
        solve(l0, l2 - 1, r0, r2)

        g = f; makeB(g,)
    }

    inline void solve() {
        Bag f(k + 1);
        solve(1, n + 1, 1, n + 1);
        i64 ans = 0;
        rep (i, 1, n) ans += (n + 1) - a[i];
        std::cout << ans << "\n";
    }
}

inline void solve() {
    std::cin >> n >> k >> E;
    rep (i, 1, n) std::cin >> v[i] >> a[i] >> b[i];

    Sol::solve();
}

int main() {
    fastread

    solve();

    return 0;
}