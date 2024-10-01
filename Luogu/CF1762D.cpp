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

	std::set <int> rst;
	rep (i, 1, n) rst.insert(i);

	while (rst.size() >= 3) {
		auto it = rst.begin();
		int a = *it; it++;
		int b = *it; it++;
		int c = *it;

		std::cout << "? " << a << " " << b << std::endl;
		int r1; std::cin >> r1;
		std::cout << "? " << a << " " << c << std::endl;
		int r2; std::cin >> r2;

		// b == 0 => (a, b) > (a, c)
		// (a, b) < (a, c) => b != 0

		if (r1 == r2) {
			rst.erase(a);
		} else if (r1 < r2) {
			rst.erase(b);
		} else {
			rst.erase(c);
		}
	}

	std::cout << "! " << (*rst.begin()) << " " << (*std::next(rst.begin())) << std::endl;

	int _; std::cin >> _;
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
