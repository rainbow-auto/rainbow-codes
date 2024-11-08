// unsolved

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 1005;
const int mod = 1e9 + 7;

int n, m;
int a[maxn];
int vals[maxn], tot;

struct BIT {
	i64 tr[maxn];

	inline int lowbit (int x) { return x & (-x); }
	inline void modify (int pos, int val) { 
		for (int i = pos; i <= tot; i += lowbit (i)) { tr[i] += val; if (tr[i] > mod) { tr[i] -= mod; } }
	}

	inline i64 query (int pos) { 
		i64 res = 0;
		for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; if (res > mod) { res -= mod; } }
		return res;
	}

	inline void clear () { 
		for (int i = 1; i <= tot + 2; i++) { tr[i] = 0; }
	}

} dp[maxn]; // dp[i] : 长为 i

int main () {
	fastread

	int T; std::cin >> T;

 	for (int testcase = 1; testcase <= T; testcase ++) {
		std::cin >> n >> m;

		for (int i = 1; i <= n; i++) { std::cin >> a[i]; vals[++tot] = a[i]; }

		std::sort (vals + 1, vals + tot + 1);
		tot = std::unique (vals + 1, vals + tot + 1) - (vals + 1);
		
		for (int i = 1; i <= n; i++) {
			a[i] = std::lower_bound (vals + 1, vals + tot + 1, a[i]) - vals + 1;
		}

		i64 ans = 0;

		for (int i = 1; i <= n; i++) {
			dp[1].modify (a[i], 1);
			for (int len = 2; len <= m; len++) {
				i64 count = dp[len - 1].query (a[i] - 1);
				if (len == m) { ans += count; if (ans > mod) { ans -= mod; } }
				dp[len].modify (a[i], count);
			}
		}

		std::cout << "Case #" << testcase << ": " << ans << "\n";

		for (int len = 1; len <= m; len++) { dp[len].clear (); }
		tot = 0;
	}


	return 0;
}