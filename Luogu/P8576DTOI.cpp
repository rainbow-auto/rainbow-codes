#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxm = 10000005;
const int maxn = 100005;
const int maxB = 333;
const i64 mod = 998244353;

int n, q;
int a[maxn];

inline i64 ksm (i64 a, i64 b) {
    i64 res = 1;
    i64 base = a % mod;
    while (b) {
        if (b & 1) { res *= base; res %= mod; }
        base *= base; base %= mod; b >>= 1;
    }
    return res;
}

inline i64 inv (i64 x) { return ksm (x, mod - 2); }

int fac[maxm], ifac[maxn];
int fac_pw[maxn][maxB], ifac_pw[maxn][maxB];
inline void init (int mx, int mxn, int mxB) {
    fac[0] = 1;
    rep (i, 1, mx) { fac[i] = 1ll * fac[i - 1] * i % mod; }
    
    ifac[mxn] = inv (fac[mxn]);
    per (i, mxn - 1, 0) { ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod; }

    rep (i, 1, mxn) {
        fac_pw[i][0] = 1;
        rep (j, 1, mxB) { fac_pw[i][j] = 1ll * fac_pw[i][j - 1] * fac[i] % mod; }
    
        ifac_pw[i][0] = 1;
        rep (j, 1, mxB) { ifac_pw[i][j] = 1ll * ifac_pw[i][j - 1] * ifac[i] % mod; }
    }
}

int fa[maxn];
int find (int x) {
    if (fa[x] == x) { return x; }
    return fa[x] = find (fa[x]);
}

int L[maxB], R[maxB], belong[maxn], B, tot;
int cnt[maxB][maxn];
int fst[maxB][maxn];

struct Answer {
    i64 sum;
    i64 prod;
    inline void init () { sum = 0; prod = 1; }
    Answer () { init (); }
} ans[maxB];

inline void pushDown (int id) { 
    rep (i, L[id], R[id]) { a[i] = a[find (i)]; } 
    rep (i, L[id], R[id]) { fst[id][a[i]] = cnt[id][a[i]] = 0; }
}

inline void build (int id) {
    ans[id].init ();
    rep (i, L[id], R[id]) { 
        if (fst[id][a[i]]) { fa[i] = fst[id][a[i]]; }
        else { fa[i] = i; fst[id][a[i]] = i; }
        cnt[id][a[i]] ++;
        (ans[id].sum += a[i]) %= mod;
        (ans[id].prod *= fac[a[i]]) %= mod;
    }
}

inline void blocking () {
    B = sqrt (n) + 1;
    rep (i, 1, n) {
        belong[i] = i / B + 1;
        L[belong[i]] = L[belong[i]] ? L[belong[i]] : i;
        R[belong[i]] = i;
    }
    tot = belong[n];
}

inline void modify (int l, int r, i64 x, i64 y) {
    if (x == y) { return; }

    auto small = [&] (int l, int r) -> void {
        int id = belong[l];
        pushDown (id);
        rep (i, l, r) { if (a[i] == x) { a[i] = y; } }
        build (id);
    };

    auto big = [&] (int l, int r) -> void {
        rep (i, l, r) {
            (((ans[i].sum -= x * cnt[i][x] % mod) %= mod) += mod) %= mod;
            (ans[i].sum += y * cnt[i][x] % mod) %= mod;
            
            (ans[i].prod *= 1ll * ifac_pw[x][cnt[i][x]]) %= mod;
            (ans[i].prod *= 1ll * fac_pw[y][cnt[i][x]]) %= mod;

            cnt[i][y] += cnt[i][x];
            cnt[i][x] = 0;

            if (fst[i][y]) { fa[fst[i][x]] = fst[i][y]; }
            else { fst[i][y] = fst[i][x]; a[fst[i][x]] = y; }
            fst[i][x] = 0;
        }
    };

    if (belong[l] == belong[r]) { small (l, r); return; }

    small (l, R[belong[l]]);
    small (L[belong[r]], r);
    big (belong[l] + 1, belong[r] - 1);
}

inline i64 query (int l, int r) {
    if (belong[l] == belong[r]) {
        pushDown (belong[l]);
        build (belong[l]);
        
        Answer res;
        rep (i, l, r) { (res.sum += a[i]) %= mod; (res.prod *= fac[a[i]]) %= mod; }

        return fac[res.sum] * inv (res.prod) % mod;
    } 

    Answer res;
    
    pushDown (belong[l]);
    rep (i, l, R[belong[l]]) { (res.sum += a[i]) %= mod; (res.prod *= fac[a[i]]) %= mod; }
    build (belong[l]);

    pushDown (belong[r]);
    rep (i, L[belong[r]], r) { (res.sum += a[i]) %= mod; (res.prod *= fac[a[i]]) %= mod; }
    build (belong[r]);

    rep (i, belong[l] + 1, belong[r] - 1) { (res.sum += ans[i].sum) %= mod; (res.prod *= ans[i].prod) %= mod; }

    return fac[res.sum] * inv (res.prod) % mod;
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    std::cin >> n >> q;
    rep (i, 1, n) { std::cin >> a[i]; }

    init (10000000, 100000, 330);

    blocking ();
    rep (i, 1, tot) { build (i); }

    rep (i, 1, q) {
        int op; std::cin >> op;
        int l, r; std::cin >> l >> r;
        
        if (op == 1) {
            int x, y; std::cin >> x >> y;
            modify (l, r, x, y);
        } else {
            std::cout << query (l, r) << "\n";
        }
    }

	return 0;
}
