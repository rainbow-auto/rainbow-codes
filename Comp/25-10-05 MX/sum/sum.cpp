#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100010;
constexpr i64 mod = 1e9 + 7;

int n, q;
int k;

i64 fac[maxn], ifac[maxn];

inline i64 ksm(i64 a, i64 b) {
    i64 res = 1;
    for (; b; (a *= a) %= mod, b >>= 1) if (b & 1) (res *= a) %= mod;
    return res;
}

inline i64 inv(i64 x) {
    return ksm(x, mod - 2);
}

inline void init() {
    int N = 100005;
    fac[0] = 1; rep (i, 1, N) fac[i] = fac[i - 1] * i % mod;
    ifac[N] = inv(fac[N]); per (i, N - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

inline i64 choose(i64 a, i64 b) {
    if (a < b or a < 0 or b < 0) return 0;
    return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

namespace Task1 {
    inline void solve() {
        while (q--) {
            int x, r; std::cin >> x >> r;
            
            i64 res = 0;
            rep (i, 0, n) {
                if (i % k == r) {
                    (res += choose(i, x)) %= mod;
                }
            }

            std::cout << res << "\n";
        }
    }
}

namespace Task2 {
    inline void solve() {
        while (q--) {
            int x, r; std::cin >> x >> r;
            std::cout << choose(n + 1, x + 1) << "\n";
        }
    }
}

void solve() {
    std::cin >> n >> k >> q;

	init();

    if (k == 1) Task2::solve();
    else Task1::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

    file("sum")

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
