#include <bits/stdc++.h>
#define rep(_i, _st, _ed) for (int (_i) = (_st); (_i) <= (_ed); (_i++))
#define per(_i, _st, _ed) for (int (_i) = (_st); (_i) >= (_ed); (_i--))
#define db std::cerr
#define dbendl std::cerr << "\n";
#define dbg(x) std::cerr << (#x) << ": " << (x) << "\n";
#define lookTime std::cerr << (1.0 * clock() / CLOCKS_PER_SEC) << "s used\n";
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

using i64 = long long;
using u64 = unsigned long long;

constexpr int maxn = 1000005;
constexpr i64 mod = 998244353;

int n, k;

struct Edge {
    int u, v;
    int pre;
} es[maxn];

int last[maxn], cnt;
inline void addEdge(int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

namespace Task1 {
    int dep[maxn];
    int mxd[maxn]; // max dep

    std::vector<int> ds[maxn];
    void dfs(int now) {
        mxd[now] = dep[now];
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            dep[t] = dep[now] + 1;
            dfs(t);
            mxd[now] = std::max(mxd[now], mxd[t]);
        }
        ds[dep[now]].push_back(mxd[now]);
    }

    i64 fac[maxn], ifac[maxn];
    inline i64 ksm(i64 a, i64 b) {
        i64 res = 1;
        for (; b; (b >>= 1), (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
        return res;
    }

    inline i64 inv(i64 x) {
        return ksm(x, mod - 2);
    }

    inline void init() {
        fac[0] = 1; rep (i, 1, n) fac[i] = fac[i - 1] * i % mod;
        ifac[n] = inv(fac[n]); per(i, n - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
    }

    inline i64 choose(int a, int b) {
        if (a < b or a < 0 or b < 0) return 0;
        return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
    }

    inline int calc(int d, int R, int c) {
        // dbg(R);
        int cnt = ds[d].size() - (std::lower_bound(ds[d].begin(), ds[d].end(), R) - ds[d].begin());
        cnt -= c;
        // dbg(cnt);
        if (cnt > k - 1) {
            // db << choose(cnt, k - 1) * fac[k - 1] % mod << "\n";
            return choose(cnt, k - 1) * fac[k - 1] % mod;
        } else {
            return 0;
        }
    }

    inline int calc(int x) {
        int L = dep[x], R = mxd[x];
        // dbg(L); dbg(R);
        int res = ((calc(L, R, 1) - calc(L, R + 1, 0)) % mod + mod) % mod;
        // dbg(res);
        return res;
    }
    
    inline void solve() {
        init();
        
        dep[1] = 1; dfs(1);

        rep (i, 1, mxd[1]) std::sort(ds[i].begin(), ds[i].end());

        int ans = 0;
        rep (i, 2, n) {
            // dbg(i);
            (ans += calc(i)) %= mod;
            // dbendl;
        }
        
        std::cout << ans << "\n";
        lookTime
    }
}

inline void solve() {
    std::cin >> n >> k;
    rep (i, 2, n) {
        int p; std::cin >> p;
        addEdge(p, i);
    }

    Task1::solve();
}

int main() {
    fastread;
    ////////////

    solve();

    return 0;
}