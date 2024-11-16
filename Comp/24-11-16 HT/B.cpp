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
#define MultiTask lovely_fairytale

const int maxn = 1000005;

int n;
int a[maxn];

namespace Task1 {
	bool can[maxn];
	int val[maxn];
	bool col[maxn];

	void dfs(int now) {
		if (now > ((n - 1) >> 1)) {
			rep (i, 1, n) if (col[i]) can[val[i]] = true;
			return;
		}

		std::vector<int> ps;
		rep (i, 1, n) if (col[i]) ps.push_back(i);

		rep (i, 1, (int) ps.size() - 1 - 1) {
			col[ps[i]] = col[ps[i + 1]] = 0;
			
			int x = val[ps[i - 1]];
			int y = val[ps[i]];
			int z = val[ps[i + 1]];

			val[ps[i - 1]] = std::min({x, y, z});
			dfs(now + 1);
			val[ps[i - 1]] = std::max({x, y, z});
			dfs(now + 1);
			val[ps[i - 1]] = x;
			
			col[ps[i]] = col[ps[i + 1]] = 1;
		}
	}

	inline void solve() {
		rep (i, 1, n) val[i] = a[i];
		rep (i, 1, n) col[i] = true;
		rep (i, 1, n) can[i] = false;

		dfs(1);
		rep (i, 1, n) std::cout << char {'0' + (int) can[i]};
		std::cout << "\n";
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	Task1::solve();
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
