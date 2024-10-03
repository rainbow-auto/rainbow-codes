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

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	std::freopen("A.in", "w", stdout);

	int n = 5000;
	std::cout << n << " ";

	// std::cout << rng() << ' ' << rng() << "\n";
	std::cout << "0 0\n";

	const int up = 1e9;

	rep (i, 1, n) {
		// i64 a = rng();
		// std::cout << (a) % up << " " << (a + rng()) % up << " ";
		// i64 c = rng();	
		// std::cout << (c) % up << " " << (c + rng()) % up << "\n";
		std::cout << "0 1000000000 ";
		std::cout << "0 1000000000\n";
	}
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
