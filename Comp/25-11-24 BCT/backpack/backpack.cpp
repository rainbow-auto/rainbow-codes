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

using Backpack = std::vector<int>;

inline Backpack add(const Backpack &f, int w, int v) {
    Backpack g = f; 
    per (j, k - w, 0) g[j + w] = std::max(g[j + w], f[j] + v);
    return g;
}

// n k ^ 2 log n
namespace Task1 {
    Backpack suf[maxn];

    inline bool chk(const Backpack &pre, const Backpack &suf) {
        i64 res = 0;
        int cur = 0;
        rep (i, 1, k) {
            rep (j, 0, i) cur = std::max(cur, pre[j] + suf[i - j]);
            res += cur;
        }

        if (res > E * k) return false;
        return true;
    }

    inline int getR(const Backpack &pre, int i) {
        int l = i, r = n + 1;
        int res = n + 2;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (chk(pre, suf[mid])) {
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }
        return res;
    } 

    inline void solve() {
        // i64 ans = 0;
        // rep (l, 1, n) {
        //     // dbg(l);
        //     // dbg(getR(pre, l));
        //     ans += (n + 1) - getR(pre, l) + 1;
        //     pre = add(pre, a[l], v[l]);
        // }

        // i64 ans = 0;
        // rep (l, 1, n) {
        //     rep (r, l, n + 1) {
        //         if (chk(pre, suf[r])) {
        //             db << l << ", " << r << "\n";
        //             ans++;
        //         }
        //     }
        //     pre = add(pre, a[l], v[l]);
        // }

        i64 ans = 0;
        rep (l, 1, n) rep (r, 1, n) {
            Backpack p(k + 1);
            rep (i, 1, l - 1) p = add(p, a[i], v[i]);
            rep (i, l, r) p = add(p, b[i], v[i]);
            rep (i, r + 1, n) p = add(p, a[i], v[i]);
            
            int res = 0;
            int cur = 0;
            rep (i, 1, k) {
                cur = std::max(cur, p[i]);
                res += cur;
            }
            if (res <= k * E) {
                db << l << ", " << r << "\n";
                ans++;
            }
        }

        std::cout << ans << "\n";
    }
}

inline void solve() {
    std::cin >> n >> k >> E;
    rep (i, 1, n) std::cin >> v[i] >> a[i] >> b[i];
    Task1::solve();
}

int main() {
    fastread

    solve();

    return 0;
}