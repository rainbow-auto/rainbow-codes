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

const int maxn = 105;

int n, m;
int a[maxn][maxn];

inline int getdis (int nowx, int nowy, int dx, int dy) {
	int dis = 0;
	while (a[nowx + dx][nowy + dy]) { nowx += dx; nowy += dy; dis ++; }
	return dis;
}

int ans[maxn];

int main () {
	fastread

	std::cin >> n >> m;
	rep (i, 1, n) { rep (j, 1, m) { char ch; std::cin >> ch; a[i][j] = bool (ch == '#'); } }

	rep (i, 1, n) {
		rep (j, 1, m) {
			if (not a[i][j]) { continue; }
			
			int dis = 0x3f3f3f3f;

			for (auto dx : { -1, 1 }) {
				for (auto dy : { -1, 1 }) {
					dis = std::min (dis, getdis (i, j, dx, dy));
				}
			}
			ans[dis] ++;
		}
	}

	rep (i, 1, std::min (n, m)) { std::cout << ans[i] << " "; } std::cout << "\n";

	return 0;
}
