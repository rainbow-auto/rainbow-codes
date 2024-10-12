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

#define MutliTask true

void solve() {
	int n; std::cin >> n;

	std::vector<i64> a(n);
	rep (i, 0, n - 1) std::cin >> a[i];

	std::sort(a.begin(), a.end());

	i64 cur = a[0];
	rep (i, 1, n - 1) {
		cur = (a[i] + cur) >> 1;
	}

	std::cout << cur << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

#ifndef MutliTask
	int _ = 1;
#endif
#ifdef MutliTask
	int _; std::cin >> _;
#endif
	while (_--) {
		solve();
	}

	return 0;
}
