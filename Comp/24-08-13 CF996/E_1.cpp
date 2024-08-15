#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

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

const int maxn = 200010;

int n, m, k, w;
i64 a[maxn];

std::vector <int> dif[maxn];

inline void init () {
	rep (i, 0, n + 1) { 
		rep (j, 0, m + 5) { 
			dif[i].push_back (0);
		}
	}
}

inline void clear () {
	rep (i, 0, n + 1) { dif[i].clear (); }
}

inline void add (int x1, int y1, int x2, int y2) {
	dif[x1][y1] ++;
	dif[x1][y2 + 1] --;
	dif[x2 + 1][y1] --;
	dif[x2 + 1][y2 + 1] ++;
}

int main () {
	fastread

	int T; std::cin>> T;

	while (T--) {
		std::cin >> n >> m >> k;
		std::cin >> w;

		rep (i, 1, w) { std::cin >> a[i]; }

		std::sort (a + 1, a + w + 1, [] (i64 x, i64 y) { return x > y; });

		init ();
		rep (i, 1, n - k + 1) {
			rep (j, 1, m - k + 1) {
				add (i, j, i + k - 1, j + k - 1);
			}
		}		

		std::priority_queue <int> q;
		rep (i, 1, n) {
			rep (j, 1, m) {
				dif[i][j] += dif[i - 1][j] + dif[i][j - 1] - dif[i - 1][j - 1];
				q.push (dif[i][j]);
			}
		}

		i64 ans = 0;
		rep (i, 1, w) {
			ans += q.top () * a[i]; q.pop ();
		}

		clear ();

		std::cout << ans << "\n";
	}

	return 0;
}
