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

const int maxn = 200005;

int n; 
int a[maxn];

namespace Task1 {
	inline void solve() {
		auto get = [&](int S, int pos) -> bool {
			return (S >> (pos - 1)) & 1;
		};

		i64 ans = 0;
		rep (S, 0, (1 << n) - 1) {
			i64 sum = 0;
			int lst[2]; std::memset(lst, -1, sizeof lst);
			rep (i, 1, n) {
				int cur = get(S, i);
				if (~lst[cur]) sum += (a[lst[cur]] == a[i]) * a[i];
				lst[cur] = i;
			}

			if (sum == 18) {
				rep (i, 1, n) db << get(S, i) << " ";
				dbendl;
			}

			ans = std::max(ans, sum);
		}

		std::cout << ans << "\n";
	}
}

namespace Task2 {
	const int maxn = 2005;

	template <typename T>
	inline bool chkmax(T &x, T y) { return x < y ? x = y, 1 : 0; }

	int f[maxn][2][maxn];
	inline void solve() {
		std::memset(f, 0, sizeof f);

		rep (i, 1, n) {
			rep (k, 1, i - 1) {
				f[i][0][k] = f[i - 1][0][k] + (a[i] == a[i - 1]) * a[i];
				f[i][1][k] = f[i - 1][1][k] + (a[i] == a[i - 1]) * a[i];
			}

			rep (k, 1, i - 1) {
				chkmax(f[i][0][i - 1], f[i - 1][1][k] + (a[i] == a[k]) * a[i]);
				chkmax(f[i][1][i - 1], f[i - 1][0][k] + (a[i] == a[k]) * a[i]);
			}
		}

		int ans = 0;
		rep (i, 1, n) chkmax(ans, f[n][0][i]);
		rep (i, 1, n) chkmax(ans, f[n][1][i]);

		std::cout << ans << "\n";
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];

	// Task1::solve();
	Task2::solve();
	// Task3::solve();
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
