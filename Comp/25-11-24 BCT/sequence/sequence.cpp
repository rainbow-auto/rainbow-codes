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

constexpr int maxn = 3000005;
constexpr int mod = 998244353;

int n, k;
int a[maxn];

i64 fac[maxn], ifac[maxn];
i64 iv[maxn];

inline i64 ksm(i64 a, i64 b) {
    i64 res = 1;
    for (; b; (b >>= 1), (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
    return res;
}

inline i64 inv(i64 x) {
    return ksm(x, mod - 2);
}

inline void init(int N) {
    fac[0] = 1; rep (i, 1, N) fac[i] = fac[i - 1] * i % mod;
    ifac[N] = inv(fac[N]); per (i, N - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
    rep (i, 1, N) iv[i] = fac[i - 1] * ifac[i] % mod; 
}

namespace Task1 {
    int cnt[maxn];
    i64 del[maxn];
    struct Tree {
        int tr[maxn];
        inline int lowbit(int x) {
            return x & (-x);
        }

        inline int qry(int pos) {
            if (pos < 0) return 0;
            int res = 0;
            for (int i = pos; i; i -= lowbit(i)) (res += tr[i]) %= mod;
            return res;
        }

        inline void mdf(int pos, int v) {
            for (int i = pos; i <= k; i += lowbit(i)) (tr[i] += v) %= mod;
        }
    } tr;

    inline void solve() {
        rep (i, 1, n) cnt[a[i]]++;

        i64 all = 1;
        rep (i, 1, k) (all *= ifac[cnt[i]]) %= mod;
        rep (i, 1, k) del[i] = all * cnt[i] % mod;
        rep (i, 1, k) tr.mdf(i, del[i]);

        int ans = 0;
        i64 dt = 1;
        rep (i, 1, n) {
            (ans += dt * tr.qry(a[i] - 1) % mod * fac[n - i] % mod) %= mod;

            // del a[i]
            (dt *= cnt[a[i]]) %= mod;
            i64 old = del[a[i]];
            // (del[a[i]] *= inv(cnt[a[i]]) * (cnt[a[i]] - 1) % mod) %= mod;
            (del[a[i]] *= iv[cnt[a[i]]] * (cnt[a[i]] - 1) % mod) %= mod;
            tr.mdf(a[i], ((del[a[i]] - old) % mod + mod) % mod);
            cnt[a[i]]--;
        }

        std::cout << ans + 1 << "\n";
    }
}

inline void solve() {
    int id; std::cin >> id;

    std::cin >> n >> k;
    init(3000000);

    rep (i, 1, n) std::cin >> a[i];

    Task1::solve();

    lookTime
}

int main() {
    fastread

    // file("sequence")

    solve();

    return 0;
}