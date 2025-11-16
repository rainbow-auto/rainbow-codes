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

constexpr int maxn = 200005;

int n;
i64 X, Y;
i64 a[maxn];

void solve() {
	std::cin >> n >> X >> Y;
	rep (i, 1, n) std::cin >> a[i];
	
	std::sort(a + 1, a + n + 1);
	i64 v = X * a[1] % (Y - X);
	bool flg = true;
	rep (i, 2, n) flg &= (((X * a[i]) % (Y - X)) == v);

	if (not flg) return std::cout << "-1\n", void(0);

	i64 V = Y * a[1];
	i64 ans = 0;
	rep (i, 1, n) {
		assert((V - X * a[i]) % (Y - X) == 0);
		i64 t = (V - X * a[i]) / (Y - X);
		if (t < 0 or t > a[i]) return std::cout << "-1\n", void(0);
		ans += t;
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
