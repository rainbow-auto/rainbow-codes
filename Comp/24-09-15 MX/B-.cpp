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

const i64 mod = 998244353;
const int maxn = 200005;

namespace Math {
    inline i64 ksm (i64 a, i64 b) {
        i64 base = a % mod;
        i64 res = 1;
        while (b) {
            if (b & 1) { (res *= base) %= mod; }
            (base *= base) %= mod; b >>= 1;
        }
        return res;
    }

    inline i64 inv (i64 x) { return ksm (x, mod - 2); }
    
    inline void add (i64& x, i64 y) {
        x += y;
        if (x > mod) { x -= mod; }
    }

    inline void sub (i64& x, i64 y) {
        x -= y;
        if (x < 0) { x += mod; }
    }
};
using namespace Math;

namespace Task1 {
    inline void solve (int n, int m) {
        i64 ans = 0;
        rep (len, 1, n) {
            auto f = [&] (i64 mn, i64 mx) -> i64 { 
                if (mx - mn + 1 <= 0) { return 0; }
                return ksm ((mx - mn + 1) * inv (m) % mod, len); 
            };

            i64 sum = 0;
            rep (mn, 1, m) {
                rep (mx, mn, m) {
                    i64 g = f (mn, mx);
                    sub (g, f (mn + 1, mx));
                    sub (g, f (mn, mx - 1));
                    add (g, f (mn + 1, mx - 1));
                    (sum += g * mn % mod * mx % mod) %= mod;
                }
            }
            (ans += sum * (n - len + 1) % mod * inv (n * (n + 1) / 2)) %= mod;
        }
        std::cout << ans << "\n";
    }
}

namespace Task2 {
    i64 s1[maxn];
    i64 s2[maxn];
    inline void solve (int n, int m) {
        rep (i, 1, m) { s1[i] = (s1[i - 1] + i) % mod; }
        rep (i, 1, m) { s2[i] = (s2[i - 1] + i * i % mod) % mod; }
        
        i64 inv_m = inv (m);

        i64 ans = 0;
        rep (len, 1, n) {
            auto f = [&] (i64 c) -> i64 { 
                if (c <= 0) { return 0; }
                return ksm (c * inv_m % mod, len); 
            };

            i64 sum = 0;
            rep (c, 1, m) {
                i64 g = f (c);
                sub (g, f (c - 1));
                sub (g, f (c - 1));
                add (g, f (c - 2));

                i64 s = (s1[m - c + 1] * (c - 1) % mod + s2[m - c + 1]) % mod;
                (sum += s * g % mod) %= mod;
            }
            (ans += sum * (n - len + 1) % mod * inv (n * (n + 1) / 2)) %= mod;
        }
        std::cout << ans << "\n";
    }
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    freopen ("jadeite.in", "r", stdin);
    freopen ("jadeite.out", "w", stdout);

    int _; std::cin >> _;
    while (_--) {
        int n, m; std::cin >> n >> m;
        Task2::solve (n, m);
    }

	return 0;
}
