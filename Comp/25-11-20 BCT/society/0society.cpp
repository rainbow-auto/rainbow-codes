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

constexpr int maxn = 5000005;
constexpr int mod = 1e9 + 7;

inline i64 ksm(i64 a, i64 b) {
    i64 res = 1;
    for (; b; (b >>= 1), (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
    return res;
}

inline i64 inv(i64 x) {
    return ksm(x, mod - 2);
}

i64 fac[maxn], ifac[maxn];

inline void init(int N) {
    fac[0] = 1; rep (i, 1, N) fac[i] = fac[i - 1] * i % mod;
    ifac[N] = inv(fac[N]); per(i, N - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

inline i64 choose(i64 a, i64 b) {
    if (b < 0) return 0;
    if (a < 0 or b < 0 or a < b) return (b & 1) ;
    return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

inline i64 f(int n, int k, int i) {
    // return choose(n + 1 - k, i) * choose(n - 2 * i, k - i) % mod;
    return choose(n + 1 - k, i) * choose(n - 2 * i, n - k - i) % mod;
}

inline int calc(int n, int m, int k) {
    i64 ans = 0;
    rep (i, 0, k) {
        (((ans += ((i & 1) ? -1ll : 1ll) * f(n, k, i) % mod * f(m, k, i) % mod * fac[i] % mod * fac[k - i] % mod) %= mod) += mod) %= mod;
    }
    return ans;
}

void solve() {
    init(5000000);
    int n, m; std::cin >> n >> m;
    int q; std::cin >> q;
    while (q--) {
        int k; std::cin >> k;
        std::cout << calc(n, m, k) << " ";
    }
    std::cout << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

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
