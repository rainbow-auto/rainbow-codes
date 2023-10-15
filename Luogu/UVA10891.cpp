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

using std::cin;
using std::cout;

#define fastread std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

const int maxn = 105;

int n;
int a[maxn];

int sum[maxn];
inline int get_sum (int l, int r) { return sum[r] - sum[l - 1]; }
inline void init_sum () {
	for (int i = 1; i <= n; i++) { sum[i] = sum[i - 1] + a[i]; }
}

int dp[maxn][maxn];
int premin[maxn];
int sufmin[maxn];

inline void dp_clear () {
	memset (sum, 0, sizeof (sum));
	memset (dp, 0, sizeof (dp));
	memset (premin, 0, sizeof (premin));
	memset (sufmin, 0, sizeof (sufmin));
}

int main () {
	fastread

	while (true) {
		cin >> n;
		if (n == 0) { break; }
		dp_clear ();

		for (int i = 1; i <= n; i++) { cin >> a[i]; }
		init_sum ();

		for (int i = 1; i <= n; i++) { dp[i][i] = a[i]; sufmin[i] = premin[i] = std::min (0, a[i]); }

		for (int len = 2; len <= n; len ++) {
			for (int l = 1; l + len - 1 <= n; l++) {
				int r = l + len - 1;
				dp[l][r] = std::max ( get_sum(l, r) - sufmin[r], get_sum(l, r) - premin[l] );

				sufmin[r] = std::min (sufmin[r], dp[l][r]);
				premin[l] = std::min (premin[l], dp[l][r]);
			}
		}

		int res = dp[1][n] - (get_sum(1, n) - dp[1][n]);
		cout << res << endl;
	}


	return 0;
}
