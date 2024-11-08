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

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

const int maxn = 1000005;

i64 n, m;
i64 f[40];

std::bitset <maxn * 40> cnt;
std::bitset <maxn> vis;

int main () {
	fastread
	
	std::cin >> n >> m;
	
	for (i64 i = 1; (1ll << i) <= n; i++) {
		rep (j, 1, m) { cnt[i * j] = true; }
		f[i] = cnt.count ();
	}

	vis[1] = true; 
	i64 ans = 1; // 1 ^ n = 1
	rep (i, 2, n) {
		if (vis[i]) { continue; }

		i64 tot = 0; for (i64 j = i; j <= n; j *= i) { vis[j] = true; tot ++; }
		ans += f[tot];
	}

	std::cout << ans << "\n";

	return 0;
}
