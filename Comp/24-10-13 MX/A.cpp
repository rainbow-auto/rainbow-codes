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

const int maxn = 105;
const i64 inf = 1e18;

int n;
i64 a[maxn];

i64 up[maxn];

int calc(std::multiset<i64> s) {
	for (auto x : s) db << x << " ";
	dbendl;

	bool rst = false;
	int ans = 0;
	while (not s.empty()) {
		int cur = 0;
		std::vector<std::set<i64>::iterator> del;
		for (auto it = s.begin(); it != s.end(); it++) {
			i64 x = *it;
			if (x >= cur + 1) { cur ++; del.push_back(it); }
		}

		if (cur == 1) {
			rst = true;
			break;
		}

		ans ++;

		for (auto it : del) s.erase(it);
	}

	if (not rst) return ans;

	if (s.size() == 1) ans += 1;
	else if (s.size() == 2) ans += 2;
	else ans += (int) s.size() - 1;

	return ans;
}

void solve() {
	std::freopen("coin.in", "r", stdin);
	std::freopen("coin.out", "w", stdout);

	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];

	if (n == 1) return std::cout << "1\n", void(0);

	rep (i, 1, n) {
		up[i] = inf;
		rep (j, i + 1, n) {
			if (a[j] % a[i]) continue;
			up[i] = std::min(up[i], a[j] / a[i] - 1);	
		}
	} 

	// int ans = 0;
	// std::bitset<maxn> vis;
	// rep (i, 1, n) {
	// 	if (vis[i]) continue;
	// 	vis.set(i);

	// 	std::multiset<i64> s; 
	// 	s.insert(up[i]);
	// 	rep (j, i + 1, n) {
	// 		if (a[j] % a[i]) continue;
	// 		if (vis[j]) continue;
	// 		vis.set(j);
	// 		s.insert(up[j]);
	// 	}

	// 	ans += calc(s);
	// }

	std::multiset<i64> s;
	rep (i, 1, n) s.insert(up[i]);

	int ans = calc(s);

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
