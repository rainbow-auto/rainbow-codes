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
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 200005;
constexpr f64 eps = 1e-8;

int n, k;
f64 m;

bool a[maxn];

// ax + b
struct Num {
	f64 a, b;
	friend Num operator + (Num a, Num b) {
		return Num { a.a + b.a, a.b + b.b };
	}
	friend Num operator - (Num a, Num b) {
		return Num { a.a - b.a, a.b - b.b };
	}
	friend Num operator * (Num a, f64 M) {
		return Num { a.a * M, a.b * M };
	}
};

Num f[maxn], suf;

void solve() {
	std::cin >> n >> m >> k;
	
	f[0] = Num { 1, 0 };
	
	rep (i, 1, k) {
		int x; std::cin >> x;
		a[x] = 1;
		f[x] = f[0];
	}

	if (a[n]) return std::cout << "-1\n", void(0);
	
	if (not a[n - 1]) f[n - 1] = Num { 0, 1 };
	suf = f[n - 1];
	per (i, n - 2, 0) {
		if (not a[i]) f[i] = Num { 0, 1 } + suf * (1.0 / m);
		suf = suf + f[i];
		suf = suf - f[i + (int) m];
	}

	if (std::abs(1.0 - f[0].a) < eps) return std::cout << "-1\n", void(0);

	f64 ans = f[0].b / (1.0 - f[0].a);
	std::cout << std::fixed << std::setprecision(4) << ans << "\n";
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
