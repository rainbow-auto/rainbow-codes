#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
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

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

const int maxn = 200005;

int n, q;
int l[maxn], u[maxn];

struct Node {
	int pos; // 终点
	i64 cost; // 代价
} jmpL[maxn][25], jmpU[maxn][25];

int mx[maxn][25], mn[maxn][25]; // max {l} | min {u}

int lg2[maxn];
inline void st_init () {
	lg2[1] = 0;
	rep (i, 2, n) { lg2[i] = lg2[i >> 1] + 1; }

	rep (i, 1, n) { mx[i][0] = l[i]; mn[i][0] = u[i]; }
	rep (j, 1, 20) {
		rep (i, 1, n - (1 << j) + 1) {
			mx[i][j] = std::max (mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
			mn[i][j] = std::min (mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
		}
	}
}

inline Node calc (int pos, int L, int R) {
	int t = L;
	per (i, lg2[R - L + 1], 0) {
		if (mx[t][i] <= pos and pos <= mn[t][i]) { t += (1 << i); }
	}

	if (t > R) { return Node { pos, R - L }; }

	int len = lg2[R - t + 1];
	if (pos < l[t]) {
		auto res = calc (jmpL[t][len].pos, t + (1 << len) - 1, R);
		res.cost += jmpL[t][len].cost + i64 (t - L) + i64 (l[t] - pos);
		return res;
	} else if (pos > u[t]) {
		auto res = calc (jmpU[t][len].pos, t + (1 << len) - 1, R);
		res.cost += jmpU[t][len].cost + (t - L) + (pos - u[t]);
		return res;
	}
}

bool MemED;
int main () {
	fastread
	// lookMem

	std::cin >> n;

	rep (i, 1, n) { std::cin >> l[i] >> u[i]; }

	st_init ();

	rep (i, 1, n) {
		jmpL[i][0] = Node { l[i], 0 };
		jmpU[i][0] = Node { u[i], 0 };
	}

	rep (j, 1, 20) {
		rep (i, 1, n - (1 << j) + 1) {
			jmpU[i][j] = calc (u[i], i, i + (1 << j) - 1);
			jmpL[i][j] = calc (l[i], i, i + (1 << j) - 1);
		}
	}

	std::cin >> q;
	while (q--) {
		int sx, sy; std::cin >> sx >> sy;
		int tx, ty; std::cin >> tx >> ty;

		if (sx > tx) { std::swap (sx, tx); std::swap (sy, ty); }
		
		auto ans = calc (sy, sx, tx); // sx -> tx
		ans.cost += abs (ans.pos - ty);

		std::cout << ans.cost << "\n";
	}

	return 0;
}
