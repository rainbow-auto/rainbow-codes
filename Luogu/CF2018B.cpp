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

void solve() {
	int n; std::cin >> n;
	
	std::map<int, std::vector<int>> pos;
	std::vector<int> a(n + 1);

	rep (i, 1, n) {
		std::cin >> a[i];
		if (not pos.count(a[i])) pos[a[i]] = std::vector<int>(1, i);
		else pos[a[i]].push_back(i);
	}	

	int inf; std::memset(&inf, 0x3f, sizeof inf);
	int l = inf, r = -inf;

	for (auto [val, ps] : pos) {
		for (auto i : ps) {
			l = std::min(l, (int) i);
			r = std::max(r, (int) i);
		}

		if (r - l + 1 > val) {
			std::cout << 0 << "\n";
			return;
		}
	}

	l = 1; r = n;
	rep (i, 1, n) {
		l = std::max(l, (int) i - a[i] + 1);
		r = std::min(r, (int) i + a[i] - 1);
	}

	std::cout << std::max(0, r - l + 1) << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
