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

int n;
int a[maxn];

namespace Task1 {

	const int maxn = 505;

	int dp[maxn];

	inline int count () {
		rep (i, 1, n) { dp[i] = 0; }
		dp[0] = 1;
		rep (i, 1, n) {
			int mx = a[i];
			per (j, i - 1, 0) {
				if (not mx >= i - j) { continue; }
				dp[i] += dp[j];
				mx = std::max (mx, a[j]);
			}
		}
		return dp[n];
	}	

	inline void solve () {
		rep (i, 1, n) {
			int olda = a[i];
			a[i] = 1;

			std::cout << count () << " ";

			a[i] = olda;
		}
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	

	freopen ("tree.in", "r", stdin);
	freopen ("tree.out", "w", stdout);

	std::cin >> n;
	rep (i, 1, n) { std::cin >> a[i]; }

	Task1::solve ();

	return 0;
}
