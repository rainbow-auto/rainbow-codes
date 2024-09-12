#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 505;

int n, k;
int a[maxn][maxn];

#ifdef RunTask1
namespace Task1 {
	int cnt[maxn], col;

	inline void add (int x, int y) {
		if (col[a[x][y]] == 0) { col ++; }
		cnt[a[x][y]] ++;
	}

	inline void del (int x, int y) {
		cnt[a[x][y]] ++;
		if (col[a[x][y]] == 0) { col --; }
	}

	inline void solve () {
		int len = 0;
		int pre_i = 1, pre_j = 1;
		rep (i, 1, n) {
			len = 0;
			rep (j, 1, n) {
				while (i + len <= n and j + len <= n and col <= k) {
					len ++;
					rep (k, 1, len - 1) { add (i + len - 1, j + k - 1); }
					rep (k, 1, len - 1) { add (i + k - 1, j + len - 1); }
					add (i + len - 1, j + len - 1);
				}
				
				while (len > 0 and col > k) {
					rep (k, 1, len - 1) { del (i + len - 1, j + k - 1); }
					rep (k, 1, len - 1) { del (i + k - 1, j + len - 1); }
					del (i + len - 1, j + len - 1);
					len --;
				}

				std::cout << len << "\n";

				pre_i = i; pre_j = j;
			}
		}	
	}
}	
#endif

namespace Task2 {
	std::vector <int> colors;

	int sum[maxn][maxn][maxn];
	inline void init () {
		rep (i, 1, n) {
			rep (j, 1, n) {
				colors.push_back (a[i][j]);
			}
		}

		std::sort (colors.begin (), colors.end ());
		colors.erase (std::unique (colors.begin (), colors.end ()), colors.end ());

		rep (i, 1, n) {
			rep (j, 1, n) {
				a[i][j] = std::lower_bound (colors.begin (), colors.end (), a[i][j]) - colors.begin ();
			}
		}

		rep (c, 0, colors.size () - 1) {
			rep (i, 1, n) {
				rep (j, 1, n) {
					sum[c][i][j] = sum[c][i - 1][j] + sum[c][i][j - 1] - sum[c][i - 1][j - 1] + (a[i][j] == c);
				}
			}
		}
	}

	inline int query (int c, int x1, int y1, int x2, int y2) {
		return sum[c][x2][y2] - sum[c][x1 - 1][y2] - sum[c][x2][y1 - 1] + sum[c][x1 - 1][y1 - 1];
	}

	inline bool check (int x, int y, int len) {
		int col = 0;
		rep (c, 0, colors.size () - 1) {
			col += bool (query (c, x, y, x + len - 1, y + len - 1) > 0);
		}
		return col <= k;
	}

	inline void solve () {
		init ();

		rep (i, 1, n) {
			rep (j, 1, n) {
				int l = 1, r = std::min (n - i + 1, n - j + 1);
				int len = 1;
				while (l <= r) {
					int mid = (l + r) >> 1;
					if (check (i, j, mid)) { len = mid; l = mid + 1; }
					else { r = mid - 1; }
				}	
				
				std::cout << len << " ";
			}
			std::cout << "\n";
		}	
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	// freopen ("square.in", "r", stdin);
	// freopen ("square.out", "w", stdout);

	std::cin >> n >> k;
	rep (i, 1, n) {
		rep (j, 1, n) {
			std::cin >> a[i][j];
		}
	}

	Task2::solve ();

	return 0;
}
