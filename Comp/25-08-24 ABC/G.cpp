#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

void solve() {
	i64 X; std::cin >> X;

	std::vector<i64> ans;
	auto add = [&](i64 x, i64 y) -> void {
		if ((x + y) % 4) return;
		i64 t = (x + y) / 4;
		if ((x - y - 2) % 4) return;
		i64 n = (x - y - 2) / 4;
		ans.push_back(n);
	};

	X = 4ll * X - 1;

	for (i64 i = 1; i * i <= std::abs(X); i++) {
		if (X % i) continue;
		add(i, X / i);
		add(-i, -X / i);
		if (X / i == i) continue;
		add(X / i, i);
		add(-X / i, -i);
	}

	std::sort(ans.begin(), ans.end());
	ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

	std::cout << ans.size() << "\n";
	for (auto x : ans) std::cout << x << " ";
}

bool MemED;
int main() {
	fastread
	// lookMem	

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
