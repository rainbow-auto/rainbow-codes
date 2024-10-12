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

const int maxn = 1000005;

int n, m, q;
int u, v, t;

void solve() {
	std::cin >> n >> m >> q;

	std::cin >> u >> v >> t;
	f64 p = 1.0d * u / v;

	std::vector<int> nums;
	rep (i, 1, n) {
		int x; std::cin >> x;
		nums.push_back(x);
	}

	std::sort(nums.begin(), nums.end());
	std::reverse(nums.begin(), nums.end());

	std::queue<int> a;
	for(auto x : nums) a.push(x);

	std::queue<int> b, c;

	auto cut = [&](int x) -> std::pair<int, int> {
		int y = std::floor(p * x);
		return std::make_pair(y, x - y);
	};

	int delta = 0;

	auto ins = [&](int v) -> void {
		int x, y; std::tie(x, y) = cut(v);
		b.push(x - delta);
		c.push(y - delta);
	};

	auto get = [&]() -> std::pair<int, int> {
		std::pair<int, int> mx = { 0, 0 };

	 	if (not a.empty()) mx = std::max(mx, std::make_pair(a.front() + delta, 1));
		if (not b.empty()) mx = std::max(mx, std::make_pair(b.front() + delta, 2));
		if (not c.empty()) mx = std::max(mx, std::make_pair(c.front() + delta, 3));

		return mx;
	};

	auto clr = [&](std::pair<int, int> mx) {
		if (mx.second == 1) a.pop();
		if (mx.second == 2) b.pop();
		if (mx.second == 3) c.pop(); 
	};

	rep (i, 1, m) {
		auto mx = get();
		clr(mx);

		delta += q;
		ins(mx.first);

		if (i % t == 0) std::cout << mx.first << " ";
	}

	std::cout << "\n";

	int cur = 0;
	while (true) {
		auto mx = get();
		if (not mx.second) break;
		clr(mx);
		cur ++;
		if (cur % t == 0) std::cout << mx.first << " ";
	}

	std::cout << "\n";
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
