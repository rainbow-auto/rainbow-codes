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

int n;
std::map<int, std::set<int>> pos;

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		int x; std::cin >> x;
		pos[x].insert(i);
	}

	int tot = 1;

	bool st = false; // status false: down | true: up
	int lst = 2e9;
	for (auto _ : pos) {
		auto p = _.second;

		int mn = *p.begin();
		int mx = *p.rbegin();

		if (not st) {
			if (mx < lst) lst = mn;
			else lst = mx, st = true; 
		} else {
			if (mn > lst) lst = mx;
			else ++tot, lst = mn, st = false;
		}
	}

	std::cout << tot << "\n";
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
