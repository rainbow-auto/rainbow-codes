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
#define MultiTask lovely_fairytale

inline std::map<int, int> get() {
	int x; std::cin >> x;
	std::map<int, int> cnt;
	rep (i, 2, x) {
		if (i * i > x) break;
		while (x % i == 0) cnt[i]++, x /= i;
	}
	if (x > 1) cnt[x]++;

	return cnt;
}

void solve() {
	auto a0 = get(), a1 = get();
	auto b0 = get(), b1 = get();

	std::set<int> all;
	for (auto _ : a0) all.insert(_.first);
	for (auto _ : a1) all.insert(_.first);
	for (auto _ : b0) all.insert(_.first);
	for (auto _ : b1) all.insert(_.first);

	i64 ans = 1;
	for (auto p : all) {
		if (not a0.count(p)) a0[p] = 0;
		if (not a1.count(p)) a1[p] = 0;
		if (not b0.count(p)) b0[p] = 0;
		if (not b1.count(p)) b1[p] = 0;

		i64 cur = 0;
		if (a0[p] >= a1[p] and b0[p] <= b1[p]) {
			if (a0[p] == a1[p] and b0[p] == b1[p]) {
				cur = b0[p] - a0[p] + 1;
			} else if (a0[p] != a1[p] and b0[p] != b1[p] and a1[p] != b1[p]) {
				cur = 0;
			} else {
				cur = 1;
			}
		}
		ans *= cur;
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
