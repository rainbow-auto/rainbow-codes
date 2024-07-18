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

const int maxn = 15;
const int maxm = 2005;
const int maxS = (1 << 15) + 10;

int n, m;

int a[maxn][maxm];
int dp[maxn][maxS];

int val[maxS];

struct Node {
	int mx, id;

	friend bool operator < (Node a, Node b) {
		return a.mx > b.mx;
	}
} col[maxm];

inline void clear () {
	for (int j = 1; j <= m; j++) { col[j].mx = -0x3f3f3f3f; col[j].id = j; }

	for (int i = 1; i <= std::min (n, m); i++) {
		for (int S = 0; S < (1 << n); S++) {
			dp[i][S] = -0x3f3f3f3f;
		}
	}
}

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) {
		std::cin >> n >> m;

		clear ();

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				std::cin >> a[i][j];
				col[j].mx = std::max (col[j].mx, a[i][j]);
			}
		}

		std::sort (col + 1, col + m + 1);

		m = std::min (n, m);

		for (int i = 1; i <= m; i++) {
			for (int S = 0; S < (1 << n); S ++) {
				val[S] = -0x3f3f3f3f;
				for (int k = 0; k < n; k++) {
					int curr = 0;
					for (int pos = 0; pos < n; pos ++) {
						if (S & (1 << pos)) { curr += a[(pos + k) % n + 1][col[i].id]; }
					}
					val[S] = std::max (val[S], curr);
				}
			}
		
			for (int S = 0; S < (1 << n); S++) {
				dp[i][S] = dp[i - 1][S];
				for (int SS = S; SS; SS = (SS - 1) & S)	{
					dp[i][S] = std::max (dp[i][S], dp[i - 1][S ^ SS] + val[SS]); // S ^ SS: 去除SS中的元素
				}
			}
		}

		std::cout << dp[m][(1 << n) - 1] << "\n";
	}


	return 0;
}
