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

const int maxn = 4005;
const i64 inf = 1e17;

int n;
struct Line {
	i64 l, r;
	
	friend bool operator < (Line a, Line b) {
		if (a.l != b.l) { return a.l < b.l; }
		else { return a.r < b.r; }
	}
} a[maxn];

i64 dp[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n;
	rep (i, 1, n) {
		i64 l, r; std::cin >> l >> r;
		a[i] = Line { l, r };
	}

	std::sort (a + 1, a + n + 1);

	rep (i, 1, n) { dp[i] = inf; }
	a[0].r = -inf;

	rep (i, 1, n) {
		i64 mxl = -inf;
		per (j, i - 1, 0) {
			if (a[j].r >= a[i].l) { continue; }
			if (a[j].r < mxl) { continue; }
			dp[i] = std::min (dp[i], dp[j] + a[i].r - a[i].l);
			mxl = std::max (mxl, a[j].l);
		}
	}

	i64 ans = inf;
	rep (i, 1, n) { 
		if (a[i].r >= a[n].l) { ans = std::min (ans, dp[i]); }
	}

	std::cout << ans << "\n";

	return 0;
}