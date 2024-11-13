#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

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

const i64 mod = 1e9 + 7;
const int maxn = 1000005;

inline i64 ksm(i64 a, i64 b) {
	i64 res = 1;
	for (; b; b >>= 1, (a *= a) %= mod) if (b & 1) (res *= a) %= mod;
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

inline i64 choose(int a, int b) {
	if (a < b) return  0;
	return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

i64 d[maxn];
inline void initd(int R) {
	d[0] = 1, d[1] = 0;
	rep (i, 2, R) d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % mod;
}

void solve() {
	int n, m; std::cin >> n >> m;  
	std::cout << choose(n, m) * d[n - m] % mod << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

	init(1000000);
	initd(1000000);

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
