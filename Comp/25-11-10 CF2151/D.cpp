#include<bits/stdc++.h>
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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 200005;
constexpr int mod = 998244353;

int a[maxn];

inline i64 ksm(i64 a, i64 b) {
    i64 res = 1;
    for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
    return res;
}

inline i64 inv(i64 x) {
    return ksm(x, mod - 2);
}
 
i64 fac[maxn], ifac[maxn];
inline void init(int N) {
    fac[0] = 1; rep (i, 1, N) fac[i] = fac[i - 1] * i % mod;
    ifac[N] = inv(fac[N]); per (i, N - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

inline i64 choose(int a, int b) {
    if (a < b or a < 0 or b < 0) return 0;
    return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

void solve() {
	int n; std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];
    
    i64 ans = 1;
    int cur = 0;
    per (i, n, 1) {
        if (i == n - i + 1) {
            cur++;
        } else if (i < n - i + 1) {
            cur += 2;
        }
        (ans *= choose(cur, a[i])) %= mod;
        cur -= a[i];
        if (cur < 0) break;
    }

    if (cur != 0) ans *= 0;

    std::cout << ans << "\n";
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

    init(200000);
	
	while (_--) {
		solve();
	}

	return 0;
}
