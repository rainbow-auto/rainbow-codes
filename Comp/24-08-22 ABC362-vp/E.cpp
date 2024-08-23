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

const int maxn = 85;
const int mod = 998244353;

int n;
int a[maxn];
int dp[maxn][maxn][maxn * maxn]; // dp[i][j][k] : i 为结尾 长度为 j 公差为 k

std::vector <int> vals;

inline int get (int x) {
	return std::lower_bound (vals.begin (), vals.end (), x) - vals.begin () + 1;
}

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n;
	rep (i, 1, n) { std::cin >> a[i]; }

	rep (i, 1, n) {
		rep (j, 1, i) {
			vals.push_back (a[i] - a[j]);
		}
	}

	std::sort (vals.begin (), vals.end ());
	vals.erase (std::unique (vals.begin (), vals.end ()), vals.end ());

	rep (i, 1, n) {
		rep (d, 1, vals.size ()) { dp[i][1][d] = 1; }

		rep (pre, 1, i - 1) {
			rep (j, 0, i) { // 长度
				int d = get (a[i] - a[pre]);
				dp[i][j + 1][d] += dp[pre][j][d];  
				dp[i][j + 1][d] %= mod;  
			}
		}
	}

	rep (len, 1, n) {
		if (len == 1) { std::cout << n << " "; continue; }

		i64 res = 0;
		rep (i, 1, n) {
			rep (d, 1, vals.size ()) { res += dp[i][len][d]; res %= mod; }
		}
		std::cout << res << " ";
	}

	return 0;
}
