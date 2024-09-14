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

const int maxn = 2005;
const i64 mod = 1e9 + 7;

int n;
int a[maxn];

namespace Solution {
    std::vector <int> vals;

    struct Fenwick {
        i64 tr[maxn];

        inline int lowbit (int x) { return x & (-x); }

        inline void modify (int pos, int val) {
            for (int i = pos; i <= vals.size (); i += lowbit (i)) { (tr[i] += val) %= mod; }
        }

        inline i64 query (int pos) {
            i64 res = 0;
            for (int i = pos; i; i -= lowbit (i)) { (res += tr[i]) %= mod; }
            return res;
        }

        inline void clear () { memset (tr, 0, sizeof (tr)); }
    } tr;

    i64 f[maxn][maxn];
    i64 cnt[maxn];

    i64 fac[maxn];
    inline void init (int R) {
        fac[0] = 1;
        rep (i, 1, R) { fac[i] = fac[i - 1] * i % mod; }
    }

    inline void solve () {
        init (2000);

        rep (i, 1, n) { vals.push_back (a[i]); }
        std::sort (vals.begin (), vals.end ());
        vals.erase (std::unique (vals.begin (), vals.end ()), vals.end ());

        rep (i, 1, n) { a[i] = std::lower_bound (vals.begin (), vals.end (), a[i]) - vals.begin () + 1; }

        rep (i, 1, n) { f[i][1] = 1; }

        rep (len, 2, n) {
            tr.clear ();
            rep (i, 1, n) {
                f[i][len] = tr.query (a[i]);
                tr.modify (a[i], f[i][len - 1]);
            }
        }

        rep (len, 1, n) {
            rep (i, 1, n) {
                (cnt[len] += f[i][len] * fac[n - len] % mod) %= mod;
            }
        }
        
        i64 ans = 0;
        rep (len, 1, n) {
            (ans += (cnt[len] - cnt[len + 1] * (len + 1) % mod + mod) % mod) %= mod;
        }
        std::cout << ans << "\n";
    }
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    freopen ("delete.in", "r", stdin);
    freopen ("delete.out", "w", stdout);

    std::cin >> n;
    rep (i, 1, n) { std::cin >> a[i]; }

    Solution::solve ();

	return 0;
}
