#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 500005;

i64 n;

std::bitset<maxn> np;
std::vector<int> ps;
inline void sieve(int R) {
	rep (i, 2, R) {
		if (not np[i]) ps.push_back(i);	
		for (auto p : ps) {
			if (i * p > R) break;
			np[i * p] = true;
			if (i % p == 0) break;
		}
	}
}
inline i64 calc_phi(i64 x) {
	i64 res = x;
	for (auto p : ps) {
		if (1ll * p * p > x) break;
		if (x % p) continue;
		res = res / p * (p - 1);
		while (not (x % p)) x /= p;
	}
	if (x > 1) res = res / x * (x - 1);
	return res;
}

void solve() {
	std::cin >> n;

	sieve(sqrt(n) + 1);

	i64 ans = 0;
	for (int d = 1; 1ll * d * d <= n; d++) {
		if (n % d == 0) {
			ans += calc_phi(d) * (n / d);
			if (n / d == d) continue;
			ans += calc_phi(n / d) * (d);
		}
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
