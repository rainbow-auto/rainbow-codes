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

const int maxn = 10000005;
const i64 mod = 998244353;

inline i64 ksm(i64 a, i64 b) {
	i64 res = 1;
	for (; b; (b >>= 1), (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
	return res;
}

inline i64 inv(i64 x) { return ksm(x, mod - 2); }

i64 fac[maxn], ifac[maxn];

inline void init(int R) {
	fac[0] = 1;
	rep (i, 1, R) fac[i] = fac[i - 1] * i % mod;
	ifac[R] = inv(fac[R]);
	per (i, R - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

inline i64 choose(i64 a, i64 b) {
	if (a < b) return 0;
	return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

inline i64 f(i64 x, int S) {
	if (x < 0) x = -x;
	if (S < x) return 0;
	if ((S - x) & 1) return 0;
	return choose(S, ((S - x) >> 1));
} 

inline i64 g(i64 x, i64 y, int S) {
	return f(x + y, S) * f(x - y, S) % mod;
}

void solve() {
	init(10000000);

	i64 n, x, y, z; std::cin >> n >> x >> y >> z;

	i64 ans = 0;
	// rep (i, 0, n) {
	// 	rep (j, 0, n) {
	// 		if (i + j > n) continue;
	// 		(ans += f(x, i) * f(y, j) % mod * f(z, n - i - j) % mod * fac[n] % mod * ifac[n - i - j] % mod * ifac[i] % mod * ifac[j] % mod) %= mod;
	// 	}
	// } 

	rep (i, 0, n) {
		(ans += g(x, y, i) * f(z, n - i) % mod * fac[n] % mod * ifac[i] % mod * ifac[n - i] % mod) %= mod;
	}

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
	
	while (_--) {
		solve();
	}

	return 0;
}
