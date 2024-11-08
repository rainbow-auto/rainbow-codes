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

int n, k, m;

double dp[maxn];
double p[maxn];

inline double ksm (double a, int b) {
	double ans = 1.0;
	while (b) {
		if (b & 1) { ans *= a; }
		b >>= 1; a *= a;
	}
	return ans;
}

inline void solve (int caseID) {
	memset (dp, 0, sizeof (dp));
	
	std::cin >> n >> k >> m;

	for (int i = 0; i < n; i++) { std::cin >> p[i]; }

	dp[1] = p[0];
	for (int i = 2; i <= m; i++) { 
		for (int j = 0; j < n; j++) {
			dp[i] += ksm (dp[i - 1], j) * p[j];
		}
	}

	printf ("Case #%d: %.7lf\n", caseID, ksm (dp[m], k));
}

int main () {
	fastread

	int T; std::cin >> T;

	int caseID = 0;
	while (T--) {
		solve (++caseID);
	}

	return 0;
}
