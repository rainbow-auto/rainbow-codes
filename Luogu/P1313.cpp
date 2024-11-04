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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 100005;
const i64 mod = 10007;

int n;

inline i64 ksm(i64 a, i64 b) {
	i64 res = 1;
	while (b) {
		if (b & 1) (res *= a) %= mod;
		(a *= a) %= mod; b >>= 1;
	}
	return res;
}

inline i64 inv(i64 x) { return ksm(x, mod - 2); } 

i64 fac[maxn], ifac[maxn];
inline void init(int MX) {
	fac[0] = 1;
	rep (i, 1, MX) fac[i] = fac[i - 1] * i % mod;
	ifac[MX] = inv(fac[MX]);
	per (i, MX - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

inline i64 choose(int a, int b) {
	if (a < b) return 0;
	return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

void solve() {
	i64 a, b, k, n, m;
	std::cin >> a >> b >> k >> n >> m;

	init(1000);

	std::cout << ksm(a, n) * ksm(b, m) % mod * choose(k, n) % mod << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

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
