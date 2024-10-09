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

const int maxn = 5005;

int n, m;
int a[maxn][maxn];

int sum[maxn][maxn];

void solve() {
	std::cin >> n >> m;

	int mx = 0;
	rep (i, 1, n) {
		int x, y; std::cin >> x >> y; 
		x ++; y ++;
		int v; std::cin >> v;
		mx = std::max({ mx, x, y });
		a[x][y] += v;
	}

	rep (i, 1, mx) {
		rep (j, 1, mx) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
		}
	}

	auto qry = [&](int x1, int y1, int x2, int y2) -> int {
		return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
	};

	int ans = 0;

	rep (i, 1, mx - m + 1) {
		rep (j, 1, mx - m + 1) {
			ans = std::max(ans, qry(i, j, i + m - 1, j + m - 1));
		}
	}

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
