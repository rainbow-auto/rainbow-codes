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

int n, m, o;

std::multiset<std::pair<int, int>> hotel;
std::vector<std::pair<int, int>> tsk;

void solve() {
	std::cin >> n >> m >> o;
	
	rep (i, 1, n) {
		int c, p; std::cin >> c >> p;
		hotel.insert(std::make_pair(p, c));
	}

	rep (i, 1, m) {
		int v, d; std::cin >> v >> d;
		tsk.push_back(std::make_pair(-v, d));
	}

	std::priority_queue<int> vals;

	std::sort(tsk.begin(), tsk.end());
	for (auto _ : tsk) {
		int v, d; std::tie(v, d) = _;
		v *= -1;

		auto it = hotel.lower_bound(std::make_pair(d, 0));
		if (it == hotel.end()) continue;
		if (v - it -> second <= 0) continue;
		vals.push(v - it -> second);
		hotel.erase(it);
	}

	int tot = 0;
	i64 ans = 0;
	while (not vals.empty() and tot + 1 <= o) {
		++tot;
		ans += vals.top(); vals.pop();
	}
	std::cout << ans << "\n";
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
