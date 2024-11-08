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

const int maxn = 1000005;
const i64 mod = 998244353;

int n;
int a[maxn];

namespace Task0 {
	inline void solve () {
		int R = 0;
		rep (i, 1, n) { R |= (a[i] << (n - i)); }

		int ans = 0;
		rep (i, 0, R) {
			rep (j, 0, R) {
				if ((i | j) == (i ^ j)) { 
					ans ++;
				}
			}
		}
		std::cout << ans << "\n";
	}
}

namespace Solution {

	i64 pw3[maxn];

	inline void init () {
		pw3[0] = 1;
		rep (i, 1, n) { pw3[i] = pw3[i - 1] * 3ll % mod; }
	}

	int dp[maxn][2][2];

	i64 dfs (int now, bool xlim, bool ylim) {
		if (now > n) { return 1; }

		if (not xlim and not ylim) { return pw3[n - now + 1]; }
		if (dp[now][xlim][ylim]) { return dp[now][xlim][ylim]; }

		i64 res = 0;
		rep (x, 0, xlim ? a[now] : 1) {
			rep (y, 0, ylim ? a[now] : 1) {
				if ((x | y) != (x ^ y)) { continue; }
				res += dfs (now + 1, xlim and x == a[now], ylim and y == a[now]);
				res %= mod;
			}
		}

		dp[now][xlim][ylim] = res;
		return res;
	}


	inline void solve () {
		init ();
		i64 res = dfs (1, true, true);
		std::cout << res << "\n";
	}
}		

bool MemED;
int main () {
	fastread
	// lookMem	

	freopen ("pair.in", "r", stdin);
	freopen ("pair.out", "w", stdout);

	std::string s; std::cin >> s; 
	n = s.size (); 
	s = " " + s;
	rep (i, 1, n) { a[i] = s[i] - '0'; }

	// Task0::solve ();	
	Solution::solve ();

	return 0;
}
