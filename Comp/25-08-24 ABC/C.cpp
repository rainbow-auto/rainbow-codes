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

int n, q;
int a[maxn], b[maxn];

void solve() {
	std::cin >> n >> q;

	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) std::cin >> b[i];

	i64 ans = 0;
	rep (i, 1, n) ans += std::min(a[i], b[i]);

	while (q--) {
		char c; std::cin >> c;
		int x, y; std::cin >> x >> y;

		if (c == 'A') {
			i64 old = std::min(a[x], b[x]);
			ans -= old;
			a[x] = y;
			ans += std::min(a[x], b[x]);
		} else {
			i64 old = std::min(a[x], b[x]);
			ans -= old;
			b[x] = y;
			ans += std::min(a[x], b[x]);
		}

		std::cout << ans << "\n";
	}

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
