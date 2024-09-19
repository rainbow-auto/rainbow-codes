#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

inline void solve () {
	rep (i, 1, 3) {
		char c; std::cin >> c;
		int x = c - '0';
		if (x & (1 << 2)) { std::cout << 'r'; }
		else { std::cout << '-'; }
		if (x & (1 << 1)) { std::cout << 'w'; }
		else { std::cout << '-'; }
		if (x & (1 << 0)) { std::cout << 'x'; }
		else { std::cout << '-'; }
	}
	std::cout << "\n";	
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _; std::cin >> _;
	while (_--) {
		solve ();
	}

	return 0;
}
