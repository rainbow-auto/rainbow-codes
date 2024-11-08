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

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

#define int long long

using namespace std;

const int maxn = 5005;

struct Hole {
	int pos, c;
	friend bool operator < (Hole a, Hole b) {
		return a.pos < b.pos;
	}
};
Hole hs[maxn];

int n, m;
int a[maxn];

int dp[maxn][maxn], val[maxn];
int sum[maxn];

signed main () {
	fastread
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) { cin >> a[i]; }
	sort (a + 1, a + n + 1);

	for (int i = 1; i <= m; i++) { cin >> hs[i].pos >> hs[i].c; }
	sort (hs + 1, hs + m + 1);

	memset (dp, 0x3f, sizeof (dp));
	dp[0][0] = 0;
	
	int limit = 0;
	for (int i = 1; i <= m; i++) {
		dp[i][0] = 0; deque<int> q;
		limit += hs[i].c;
		
		for (int j = 1; j <= n; j++) { sum[j] = sum[j - 1] + abs(a[j] - hs[i].pos); }

		for (int j = 0; j <= min (limit, n); j++) {
			while (not q.empty() and q.front() < j - hs[i].c) { q.pop_front(); }
			while (not q.empty() and val[q.back()] >= dp[i - 1][j] - sum[j]) { q.pop_back(); }

			q.push_back (j); val[j] = dp[i - 1][j] - sum[j];
			
			dp[i][j] = sum[j] + val[q.front()];
		}
	}

	if (limit < n) { cout << -1 << endl; }
	else { cout << dp[m][n] << endl; }

	return 0;
}
