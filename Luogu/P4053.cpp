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

void solve() {
	int n; std::cin >> n;
	std::vector<std::pair<int, int>> a;
	rep (i, 1, n) {
		int t1, t2; std::cin >> t1 >> t2;
		a.push_back(std::make_pair(t2, t1));
	}

	std::sort(a.begin(), a.end());

	int ans = 0;
	i64 cur = 0;
	std::priority_queue<int> q;
	for (auto t : a) {
		cur += t.second;
		q.push(t.second);
		if (cur <= t.first) {
			ans++;
		} else {
			cur -= q.top();
			q.pop();
		}
	}

	std::cout << ans << "\n";
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
