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
// #define MultiTask lovely_fairytale

const int maxn = 1000005;
const int mod = 998244353;

int n;
int a[maxn];

int p[maxn];

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
	if (a < b) return 0;
	return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}

i64 f[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];

	rep (i, 1, n) if (a[i]) p[a[i]] = i; 

	rep (i, 1, n) {
		if (not p[i]) continue;
		if (p[p[i]] != 0) {
			// p[i] = j
			// p[j] = i
			if (p[p[i]] != i) return std::cout << "0\n", void(0);
		} else {
			p[p[i]] = i;
		}
	}

	rep (i, 1, n) a[p[i]] = i;

	// rep (i, 1, n) db << a[i] << " "; dbendl;

	std::set<int> wait;
	rep (i, 1, n) if (not a[i]) wait.insert(i);
	rep (i, 1, n) if (not p[i]) if (not wait.count(i)) return std::cout << "0\n", void(0);

	int cnt = wait.size();

	init(n);

	f[0] = 1;
	f[1] = 1;
	rep (i, 2, cnt) f[i] = f[i - 1] * (2ll * i - 1) % mod;

	i64 ans = 0;
	rep (i, 0, cnt) {
		if ((cnt - i) & 1) continue;
		// dbg(i);
		// db << "ans += " << choose(cnt, i) % mod* f[(cnt - i) >> 1] % mod << "\n";
		(ans += choose(cnt, i) % mod * f[(cnt - i) >> 1] % mod) %= mod;
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
