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

const int maxn = 100005;

int cnt[maxn];

int main () {
	fastread

	int n; std::cin >> n;
	rep (c, 1, n) {
		for (int i = 1; i <= n; i += c) { cnt[i] ++; }
	}

	std::cout << cnt[1] << "\n";

	rep (i, 2, n) { if (not (i & 1)) { std::cout << cnt[i] << " "; } } std::cout << "\n";

	rep (i, 2, n) { if (i & 1) { std::cout << cnt[i] << " "; } } std::cout << "\n";

	return 0;
}
