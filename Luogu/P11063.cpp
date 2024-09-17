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
	i64 a, b, c, d; std::cin >> a >> b >> c >> d;
	
	if (a * b < c * d) { std::cout << "-1\n"; return; }
	if (c * d == 1) {
		if (a * b != 1) {
			std::cout << "-1\n";
		} else {
			std::cout << "0\n";
		}
		return;
	}

	std::vector <std::pair <int, i64>> ops;

	auto op = [&](int pos, i64 k) -> void {
		ops.push_back ({ pos, k });
		if (pos == 1) {
			a /= k;
			b *= k;
		} else {
			b /= k;
			a *= k;
		}	
	};

	op (1, a);
	while (a * b > c * d and a * b / 2ll + 1 > c * d) {
		i64 t = a * b / 2ll + 1;
		if (a > 1) {
			op (1, t);
		} else {
			op (2, t);
		}
	}

	if (a > 1) {
		// (x, 1)
		// x 有可能是 cd 的倍数
		op (1, c * d); // 变成 (1, cd)
		op (2, c);
	} else {
		op (2, c * d);
		op (1, d);
	}

	std::cout << ops.size () << "\n";
	for (auto x : ops) {
		std::cout << x.first << " " << x.second << "\n";
	}
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
