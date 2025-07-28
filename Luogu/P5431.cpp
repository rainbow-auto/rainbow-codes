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

i64 a[maxn];

i64 n;
i64 mod, k;

inline i64 ksm(i64 a, i64 b) {
	i64 res = 1;
	for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
	return res;
}

inline i64 inv(i64 x) {
	return ksm(x, mod - 2);
}

i64 fac[maxn], ifac[maxn];
inline void init() {
	fac[0] = 1; rep (i, 1, n) fac[i] = fac[i - 1] * a[i] % mod;
	ifac[n] = inv(fac[n]); per (i, n - 1, 0) ifac[i] = ifac[i + 1] * a[i + 1] % mod;
}

inline void read(i64 &x) {
	x = 0;
	char ch = getchar(); while (not isdigit(ch)) ch = getchar();
	while (isdigit(ch)) (x = x * 10 + ch - '0'), ch = getchar();
}

void solve() {
	read(n);
	read(mod);
	read(k);
	// std::cin >> n >> mod >> k;
	rep (i, 1, n) read(a[i]);
	// rep (i, 1, n) std::cin >> a[i];

	init();

	i64 ans = 0;
	i64 pw = k;
	rep (i, 1, n) {
		i64 iv = ifac[i] * fac[i - 1] % mod;
		(ans += pw * iv % mod) %= mod;
		(pw *= k) %= mod;
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
