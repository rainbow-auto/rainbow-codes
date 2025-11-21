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

using Range = std::pair<int, int>;

void solve() {
	int n; std::cin >> n;

	std::vector<std::pair<i64, Range>> b;
	i64 ans = 0;
	rep (i, 1, n) {
		int l, r; std::cin >> l >> r;
		ans += r - l;
		b.push_back({l + r, {l, r}});
		ans += r;
	}

	std::sort(b.begin(), b.end());
	i64 del = 0;
	rep (i, 0, n / 2 - 1) del += b[i].first;

	if (n & 1) {
		i64 dt = 1e18;
		rep (i, 0, n - 1) {
			if (i < n / 2) dt = std::min(dt, del + b[n / 2].first - b[i].second.first);
			else dt = std::min(dt, del + b[i].second.second);
		}
		std::cout << ans - dt << "\n";
	} else {
		std::cout << ans - del << "\n";
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
