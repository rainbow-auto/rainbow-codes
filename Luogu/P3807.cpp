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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100005;

int p;

inline i64 ksm(i64 a, i64 b) {
	i64 res = 1;
	for (; b; b >>= 1, (a *= a) %= p) if (b & 1) (res *= a) %= p;
	return res;
}

inline i64 inv(i64 x) {
	return ksm(x, p - 2);
}

i64 fac[maxn], ifac[maxn];
inline void init(int n) {
	fac[0] = 1; rep (i, 1, n) fac[i] = fac[i - 1] * i % p;
	ifac[n] = inv(fac[n]); per (i, n - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % p;
}

inline i64 choose(i64 a, i64 b) {
	if (a < b) return 0;
	return fac[a] * ifac[a - b] % p * ifac[b] % p;
}

i64 lucas(i64 a, i64 b) {
	if (not b) return 1;
	return lucas(a / p, b / p) % p * choose(a % p, b % p) % p;
}

void solve() {
	i64 n, m; std::cin >> n >> m;
	std::cin >> p;
	init(p - 1);
	std::cout << lucas(n + m, n) << "\n";
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
