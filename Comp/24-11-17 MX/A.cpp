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
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 200005;

int n, m;

struct Task {
	i64 t, s;
	int id;
	friend bool operator < (Task a, Task b) {
		return a.t < b.t;
	}
} a[maxn];

std::vector<int> ans[maxn];

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) {
		std::cin >> a[i].s >> a[i].t;
		a[i].id = i;
	}
	std::sort(a + 1, a + n + 1);

	std::set<std::pair<i64, int>> rst;
	std::set<int> unusd;
	rep (i, 1, m) unusd.insert(i);

	// auto display = [&]() -> void {
	// 	db << "rst: "; for (auto x : rst) db << "(" << x.first << ", " << x.second << ") "; dbendl;
	// 	db << "unusd: "; for (auto x : unusd) db << x << " "; dbendl;
	// };

	rep (i, 1, n) {
		// db << a[i].t << " " << a[i].s << " | " << a[i].id << "\n";

		for (auto it = rst.begin(); it -> first <= a[i].t and it != rst.end(); it = rst.erase(it)) unusd.insert(it -> second);

		// display();
		if (rst.empty()) {
			int x = *unusd.begin(); unusd.erase(x);
			rst.insert(std::make_pair(a[i].t + a[i].s, x));
			// db << "ins " << x << " " << a[i].t + a[i].s << "\n";
			ans[x].push_back(a[i].id);
			// db << a[i].id << " choose " << x << "\n";
		} else if (unusd.empty() or std::make_pair(a[i].t, *unusd.begin()) > *rst.begin()) {
			auto t = *rst.begin();
			rst.erase(t); rst.insert(std::make_pair(t.first + a[i].s, t.second));
			ans[t.second].push_back(a[i].id);
			// db << a[i].id << " choose " << t.second << "\n";
		} else {
			int x = *unusd.begin(); unusd.erase(x);
			rst.insert(std::make_pair(a[i].t + a[i].s, x));
			// db << "ins " << x << " " << a[i].t + a[i].s << "\n";
			ans[x].push_back(a[i].id);
			// db << a[i].id << " choose " << x << "\n";
		}
		// dbendl;
	}

	rep (i, 1, m) {
		std::cout << ans[i].size() << " ";
		std::sort(ans[i].begin(), ans[i].end());
		for (auto x : ans[i]) std::cout << x << " ";
		std::cout << "\n";
	} 
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
