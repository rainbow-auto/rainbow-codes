#include <bits/stdc++.h>
#define rep(_id, _st, _ed) for (int (_id) = (_st); (_id) <= (_ed); (_id)++)
#define per(_id, _st, _ed) for (int (_id) = (_st); (_id) >= (_ed); (_id)--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 1000005;

namespace Sol {
    constexpr int maxb = 31;

    int n, q;
    int a[maxn];
    int c[maxn];

    int req[maxb][2];

    inline int highbit(int x) {
        return (31 - __builtin_clz(x));
    }

    inline void ins(int i) {
        if (not c[i]) return;
        int b = highbit(c[i]);
        req[b][(a[i] >> b) & 1]++;
    }
    
    inline void del(int i) {
        if (not c[i]) return;
        int b = highbit(c[i]);
        req[b][(a[i] >> b) & 1]--;
    }

    inline void calc() {
        std::pair<int, bool> res = { 0, true };
        rep (b, 0, maxb - 1) if (req[b][0] + req[b][1]) {
            if (req[b][0] and req[b][1]) res.second = false;
            if (req[b][1]) res.first |= (1 << b);
        }
        if (res.second) std::cout << res.first << "\n";
        else std::cout << "-1\n";
    }

    inline void solve() {
        std::cin >> n;

        rep (i, 1, n) std::cin >> a[i];
        rep (i, 1, n - 1) c[i] = (a[i] ^ a[i + 1]);

        rep (i, 1, n - 1) ins(i);

        calc();

        std::cin >> q;
        while (q--) {
            int p; std::cin >> p;
            int x; std::cin >> x;

            if (p < n) del(p);
            if (p > 1) del(p - 1);

            a[p] = x;
            if (p > 1) c[p - 1] = (a[p - 1] ^ a[p]);
            if (p < n) c[p] = (a[p] ^ a[p + 1]);

            if (p < n) ins(p);
            if (p > 1) ins(p - 1);

            calc();
        }
    }
}

inline void solve() {
    Sol::solve();

    lookTime
}

int main() {
    fastread

    file("sort")

    solve();

    return 0;
}