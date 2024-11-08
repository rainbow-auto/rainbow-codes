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

using namespace std;

#define int long long

const int maxn = 500005;

int T;
int n;

bool vis[maxn];
int prime[maxn], pcnt;
int mu[maxn];

int sum[maxn];

inline void init () {
	memset (vis, false, sizeof(vis));
	mu[1] = 1;

	int n = maxn - 5;
	for (int i = 2; i <= n; i++) {
		if (not vis[i]) { mu[i] = -1; prime[++pcnt] = i; }

		for (int j = 1; j <= pcnt and i * prime[j] <= n; j++) {
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				mu[i * prime[j]] = 0;
				break;
			}
			mu[i * prime[j]] = -mu[i]; // 多了一个质因子
		}
	}
	
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + mu[i];
	}
}

signed main () {
	fastread

	cin >> T;

	init ();

	while (T--) {
		int n, m, k; cin >> n >> m >> k;

		n = n / k;
		m = m / k;

		if (n < m) { swap(n, m); }

		int l, r = 0;

		int ans = 0;
		for (l = 1; l <= m; l = r + 1) {
			r = min (n / (n / l), m / (m / l));
			ans += (sum[r] - sum[l - 1]) * (n / l) * (m / l);
		}
		cout << ans << endl;
	}

	return 0;
}
