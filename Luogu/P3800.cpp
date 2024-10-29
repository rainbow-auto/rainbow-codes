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

const int maxn = 4005;

int n, m, K, T;
int a[maxn][maxn];

int f[maxn][maxn];

void solve() {
	std::cin >> n >> m >> K >> T;
	
	rep (i, 1, K) {
		int x, y; std::cin >> x >> y;
		std::cin >> a[x][y];
	}

	rep (j, 1, m) f[1][j] = a[1][j];

	rep (i, 2, n) {
		std::deque<int> q; q.push_back(0);

		auto inq = [&](int j) -> void {
			if (j > m) return;
			while (not q.empty() and f[i - 1][q.back()] <= f[i - 1][j]) q.pop_back(); 
			q.push_back(j);
		};

		auto get = [&](int j) -> int {
			while (not q.empty() and q.front() < j - T) q.pop_front();
			return q.front();
		};

		rep (j, 1, T) inq(j); 

		rep (j, 1, m) {
			inq(j + T);
			f[i][j] = f[i - 1][get(j)] + a[i][j];
		}
	}

	int ans = 0;
	rep (j, 1, m) ans = std::max(ans, f[n][j]);
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
