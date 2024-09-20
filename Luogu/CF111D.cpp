#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const i64 mod = 1e9 + 7;

inline i64 ksm (i64 a, i64 b) {
    i64 res = 1;
    i64 base = a % mod;
    while (b) {
        if (b & 1) { (res *= base) %= mod; }
        (base *= base) %= mod; b >>= 1;
    }
    return res;
}

inline i64 inv (i64 x) { return ksm (x, mod - 2); }

const int maxn = 1005;
i64 fac[maxn * maxn], ifac[maxn * maxn];
inline void init (int R) {
    fac[0] = 1;
    rep (i, 1, R) { fac[i] = fac[i - 1] * i % mod; }
    ifac[R] = inv (fac[R]);
    per (i, R - 1, 0) { ifac[i] = ifac[i + 1] * (i + 1) % mod; }
}

inline i64 choose (int a, int b) {
    if (a < b) { return 0; }
    return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

int n, m;
int k;

i64 F[maxn];
inline void solve () {
    std::cin >> n >> m;
    std::cin >> k;

    if (m == 1) { std::cout << ksm (k, n) << "\n"; return; }

    init (1000000);

    rep (i, 0, n) {
        F[i] = ksm (i, n);
        rep (j, 0, i - 1) {
            (F[i] -= choose (i, j) * F[j]) %= mod;
        }
    }

    // rep (i, 0, n) {
    //     rep (j, 0, i) {
    //         (F[i] += choose (i, j) * ((i - j) & 1 ? -1 : 1) * ksm (j, n) % mod) %= mod;
    //         F[i] += mod; F[i] %= mod;
    //     }
    // }

    // auto g = [&](int col) -> i64 {
    //     return ksm (col, n);
    // };

    // auto f = [&](i64 col) -> i64 {
    //     return ((g (col) - col * g (col - 1) % mod) % mod + mod) % mod;
    // };

    i64 ans = 0;
    rep (i, 0, n) {
        i64 sum = 0;
        rep (j, 0, n) {
            if (i + j > n) { break; }
            if (i + j + j > k) { break; }
            if (i + j > 0) {
                (sum += choose (k, i) * choose (k - i, j) % mod * F[i + j] % mod * choose (k - i - j, j) % mod * F[i + j] % mod) %= mod;
            }
        }

        (ans += sum % mod * ksm (i, (m - 2) * n) % mod) %= mod;

        // i64 delta = 0;
        // (delta += sum * sum % mod * ksm (i, (m - 2) * n) % mod) %= mod;
        // db << "ins: " << i << " delta: " << delta << "\n";
        // db << "sum: " << sum << "\n";
    }

    std::cout << ans << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    int _ = 1;
    while (_--) {
        solve ();
    }

	return 0;
}
