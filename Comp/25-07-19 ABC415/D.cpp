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

i64 n, m;
i64 a[maxn], b[maxn];

std::map<i64, i64> c;

void solve() {
	std::cin >> n >> m;
	rep (i, 1, m) std::cin >> a[i] >> b[i];

	rep (i, 1, m) {
		i64 x = a[i] - b[i];
		if (not c.count(x)) {
			c[x] = a[i];
		} else {
			c[x] = std::min(c[x], a[i]);
		}
	}

	i64 ans = 0;
	for (auto [x, req] : c) {
		// db << x << " " << req << "\n";
		if (n >= req) {
			i64 t = (n - req) / x;
			// dbg(t);
			n -= t * x;
			if (n >= req) {
				n -= x;
				t++;
			}

			ans += t;
			// dbg(n);
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
