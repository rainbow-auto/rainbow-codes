#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = __int128;
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

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {	
	if (not b) { x = 1; y = 0; return a; }
	i64 g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

// x \equiv first \pmod second 
using Equation = std::pair<i64, i64>;

Equation mrg(Equation a, Equation b) {
	i64 k0, _; i64 g = exgcd(a.second, b.second, k0, _);
	i64 m = a.second / g * b.second;
	if ((b.first - a.first) % g) return Equation { -1, 0 };
	(k0 *= (b.first - a.first) / g) %= m;
	return Equation { ((a.second * k0 % m + a.first % m) % m + m) % m, m };
}

void solve() {
	int n; std::cin >> n;

	Equation a = Equation { 0, 1 };

	rep (i, 1, n) {
		unsigned long long x, y; std::cin >> x >> y;
		Equation b = { y, x };
		a = mrg(a, b);
		if (a.first == -1) return std::cout << "-1\n", void(0);
	}

	std::cout << (unsigned long long)a.first << "\n";
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
