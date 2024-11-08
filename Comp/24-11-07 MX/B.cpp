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
#define MultiTask lovely_fairytale

const int maxn = 100005;

int n;
int b[maxn];

namespace Task1 {
	const int maxn = 7;

	int col;
	int a[maxn];

	inline bool chk() {
		// rep (i, 1, n) db << a[i] << " \n"[i == n];

		int mx = 0;
		rep (i, 1, n) mx = std::max(mx, a[i]);

		rep (i, 1, n) {
			std::bitset<maxn> vis;
			bool flg = false;
			rep (j, i, n) {
				if (not vis[a[j]]) vis.set(a[j]);

				bool cur = true;
				rep (k, 1, n) cur &= vis[a[k]];
				if (cur) {
					if (b[i] != j) return false;
					flg = true;
					break;
				}
			}
			if (not flg) if (b[i] != n + 1) return false;
		}
		return true;
	}

	bool found;
	void dfs(int now) {
		if (found) return;
		if (now > n) {
			if (chk()) {
				std::cout << "YES\n";
				rep (i, 1, n) std::cout << a[i] << " \n"[i == n];
				found = true;
			}
			return;
		}

		rep (i, 1, col) {
			a[now] = i;
			dfs(now + 1);
		}
	}

	inline void solve() {
		col = n;
		rep (i, 1, n) if (b[i] != n + 1) col = std::min(col, b[i] - (int) i + 1);
		found = false;
		dfs(1);
		if (not found) std::cout << "NO\n";
	}
}

namespace Task2 {
	inline void solve() {
		std::cout << "YES\n";
		rep (i, 1, n) std::cout << 1 << " \n"[i == n];
	}
}

namespace Task3 {
	inline void solve() {
		std::cout << "NO\n";
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> b[i];

	bool flg2 = true;
	rep (i, 1, n) flg2 &= (b[i] == i);
	if (flg2) return Task2::solve(), void(0);
	
	bool flg3 = (b[1] == n + 1);
	if (flg3) return Task3::solve(), void(0);
	
	Task1::solve();
}

bool MemED;
int main() {
	fastread

	std::freopen("sing.in", "r", stdin);
	std::freopen("sing.out", "w", stdout);

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
