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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

i64 n, m;

inline void get_ds(i64 x, std::vector<i64> &ds) {
	for (i64 i = 1; i * i <= x; i++) {
		if (x % i) continue;
		ds.push_back(i);
		if (i == x / i) continue;
		ds.push_back(x / i);
	}

	std::sort(ds.begin(), ds.end());
}

inline void get_masks(i64 x, std::vector<i64> &ms) {
	std::vector<i64> mx;
	i64 cur = x;
	for (i64 i = 2; i * i <= cur; i++) {
		i64 k = 1;
		while (not(cur % i)) k *= i, cur /= i;
		if (k != 1) mx.push_back(k);
	}
	if (cur > 1) mx.push_back(cur);

	// db << "mx: "; for (auto k : mx) db << k << " "; dbendl;

	rep (S, 0, (1 << int{mx.size()}) - 1) {
		i64 k = 1;
		rep (i, 0, (int) mx.size() - 1) {
			if ((S >> i) & 1) k *= mx[i];
		}
		ms.push_back(k);
	}

	db << "masks: "; for (auto msk : ms) db << msk << " "; dbendl;
}

inline i64 calc(i64 x) {
	dbg(x);

	std::vector<i64> ds;
	get_ds(x, ds);

	std::vector<i64> ms; // masks

	get_masks(x, ms);

	i64 res = 0;
	rep (i, 0, (int) ds.size() - 1) {
		i64 d1 = ds[i];

		db << d1 << "\n";
		// d1 * d2 <= n => d2 <= n / d1
		// x * x / (d1 * d2) <= m => 
		int ed = std::upper_bound(ms.begin(), ms.end(), n / d1) - ms.begin() - 1;
		int l = 0, r = ed;
		int st = -1;

		while (l <= r) {
			int mid = (l + r) >> 1;
			i64 d2 = ms[mid];
			if (x / d1 * x / d2 <= m) {
				r = mid - 1;
				st = mid;
			} else {
				l = mid + 1;
			}
		}

		if (~st) db << "st: " << st << " ed: " << ed << "\n";

		if (~st) res += (ed - st + 1);
	}

	dbg(res);

	dbendl;

	return res;
}

void solve() {
	std::cin >> n >> m;

	i64 ans = 0;
	for (i64 x = 1; x * x <= n * m; x++) {
		i64 cur = calc(x);
		ans += cur;
	}

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

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
