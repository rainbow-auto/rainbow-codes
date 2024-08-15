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

const int maxn = 200005;

int n;
int a[maxn];

std::bitset <maxn> vis;

inline bool chk () {
	vis.reset ();

	vis[a[1]] = true;
	rep (i, 2, n) { 
		if ((not vis[a[i] - 1]) and (not vis[a[i] + 1])) { return false; } 
		vis[a[i]] = true;
	}

	return true;
}

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) {
		std::cin >> n;
		rep (i, 1, n) { std::cin >> a[i]; }
		
		if (chk ()) { std::cout << "YES\n"; }
		else { std::cout << "NO\n"; }
	}

	return 0;
}
