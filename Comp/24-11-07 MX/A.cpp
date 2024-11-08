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

const int maxn = 27;

int n;
int a[maxn];

std::vector<int> b[2];

namespace Task1 {
	int p[2][maxn];

	std::vector<int> cur[2];
	inline int calc() {
		cur[0].clear();
		rep (i, 0, (int) b[0].size() - 1) cur[0].push_back(b[0][p[0][i]]);
		cur[1].clear();
		rep (i, 0, (int) b[1].size() - 1) cur[1].push_back(b[1][p[1][i]]);

		int res = 0;

		int pos[2] = { 0, 0 };
		while (true) {
			if (pos[0] >= cur[0].size()) break;
			if (pos[1] >= cur[1].size()) break;

			int x = std::min(cur[0][pos[0]], cur[1][pos[1]]);
			cur[0][pos[0]] -= x;
			cur[1][pos[1]] -= x;

			res ++;			

			pos[0] += bool(cur[0][pos[0]] == 0);
			pos[1] += bool(cur[1][pos[1]] == 0);
		}

		return res;
	}

	inline void solve() {
		int ans; std::memset(&ans, 0x3f, sizeof ans);
		
		rep (i, 0, (int) b[0].size() - 1) p[0][i] = i;
		do {
			rep (i, 0, (int) b[1].size() - 1) p[1][i] = i;
			do {
				ans = std::min(ans, calc());				
			} while (std::next_permutation(p[1], p[1] + b[1].size()));
		} while (std::next_permutation(p[0], p[0] + b[0].size()));

		std::cout << ans << "\n";
	}
}

void solve() {
	// std::freopen("cloud.in", "r", stdin);
	// std::freopen("cloud.out", "w", stdout);

	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n + 1) {
		int cur = a[i] - a[i - 1];
		if (cur == 0) continue;
		if (cur < 0) b[0].push_back(-cur);
		if (cur > 0) b[1].push_back(cur);
	}

	if (b[0].size() == 1) return std::cout << b[1].size() << "\n", void(0);
	if (b[1].size() == 1) return std::cout << b[0].size() << "\n", void(0);

	Task1::solve();
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
/*
1063829 583667

1049048 598448
*/