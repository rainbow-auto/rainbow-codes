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

std::string ops;
i64 k;

inline std::vector < std::pair <int, int> > get (int x, int y) {
	std::vector < std::pair <int, int> > res;
	res.push_back ({ x, y });
	for (auto c : ops) {
		if (c == 'U') { y --; }
		if (c == 'D') { y ++; }
		if (c == 'L') { x --; }
		if (c == 'R') { x ++; }
		res.push_back ({ x, y });
	}
	return res;
}

std::map < std::pair<int, int>, std::vector <i64> > ls;

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> ops;
	std::cin >> k;

	auto ps = get (0, 0);
	int dx, dy; std::tie (dx, dy) = ps.back ();

	if (dx == 0 and dy == 0) {
		std::set < std::pair <int, int> > uniqued;
		for (auto x : ps) { uniqued.insert (x); }
		std::cout << uniqued.size () << "\n";
		return 0;
	} else if (dx == 0) {
		std::swap (dx, dy);
		for (auto& p : ps) { std::swap (p.first, p.second); }
	} else if (dx < 0) {
		dx *= -1;
		for (auto& p : ps) { p.first *= -1; }
	}

	for (auto p : ps) {
		int x, y; std::tie (x, y) = p;

		i64 fx = (x % dx + dx) % dx;
		i64 c = (x - fx) / dx;
		i64 fy = y - dy * c;
		
		ls[std::pair { fx, fy }].push_back (c);
	} 

	i64 ans = 0;
	for (auto l : ls) {
		auto& now = l.second;
		std::sort (now.begin (), now.end ());

		rep (i, 1, now.size () - 1) { ans += std::min (k, now[i] - now[i - 1]); }
		
		ans += k;
	}

	std::cout << ans << "\n";

	return 0;
}
