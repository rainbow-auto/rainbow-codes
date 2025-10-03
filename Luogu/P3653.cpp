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

constexpr int maxn = 1000005;
constexpr int N = 1000000;

using i128 = __int128;
constexpr i128 $1 = 1;

i64 l, r;

std::vector<i64> ps;
inline void sieve() {
	std::bitset<maxn> vis;
	rep (i, 2, N) {
		if (not vis[i]) ps.push_back(i);
		for (auto p : ps) {
			if (i * p > N) break;
			vis[i * p] = true;
			if (i % p == 0) break;
		}
	}
}

i64 a[maxn], mu[maxn];

inline i128 ksm(i128 a, i128 b, i128 m) {
	i128 res = 1;
	for (; b; (a *= a) %= m, b >>= 1) if (b & 1) (res *= a) %= m;
	return res;
}

inline bool test(i64 a, i64 p) {
	if (ksm(a, p - 1, p) != 1) return false;
	i64 x = p - 1;
	while (x % 2 == 0) {
		i64 v = ksm(a, x / 2, p);
		if (v == p - 1) return true;
		if (v != 1) return false;		
		x /= 2;
	}
	return true;
}

inline bool MillerRabin(i64 p) {
	rep (k, 0, 9) if (not test(ps[k], p)) return false;
	return true;
}

void solve() {
	std::cin >> l >> r;

	sieve();

	rep (i, l, r) a[i - l] = i;
	rep (i, l, r) mu[i - l] = 1;

	for (auto p : ps) {
		for (i64 k = (l / p); k <= (r / p); k++) {
			if (p * k < l) continue;
			if (p * k > r) break;

			i128 x = p * k;

			int tot = 0;
			while (a[x - l] % p == 0) {
				tot++;
				mu[x - l] *= -1;
				a[x - l] /= p;
			}

			if (tot >= 2) mu[x - l] = 0;
		}
	}

	rep (i, l, r) {
		i64 x = a[i - l];
		if (x == 1) continue;

		i64 sq = std::sqrt(x);
		if (sq * sq == x) mu[i - l] = 0;
		if (MillerRabin(x)) mu[i - l] *= -1;
	}
	
	i64 ans = 0;
	rep (i, l, r) ans += mu[i - l];

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
