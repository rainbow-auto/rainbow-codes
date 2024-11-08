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

const int lim = 12;

std::set <int> nums;
inline void solve (int rest, int curr) {
	if (not rest) { nums.insert (curr); return; }
	for (int nxt : { 1, 5, 10, 50 }) {
		solve (rest - 1, curr + nxt);
	}
}

const i64 d[] = { 0, 4, 6, 10, 15, 21, 27, 33, 39, 43, 46, 48, 49 };

bool MemED;
int main () {
	fastread
	// lookMem	
 
	int n; std::cin >> n;

	i64 ans = 0;
	rep (i, 1, std::min (n, lim)) { ans += d[i]; }
	
	if (n > lim) { ans += d[lim] * (n - lim); }
	
	std::cout << ans << "\n";

	return 0;
}
