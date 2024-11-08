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

const int maxn = 50005;

int T;

int prime[maxn], pcnt;
int mu[maxn];
bool vis[maxn];
int sum[maxn];

inline void init () {
	mu[1] = 1;

	int n = maxn - 5;
	for (int i = 2; i <= n; i++) {
		if (not vis[i]) { mu[i] = -1; prime[++pcnt] = i; }
		
		for (int j = 1; j <= pcnt and i * prime[j] <= n; j++) {
			vis[i * prime[j]] = true;
			if (i % prime[j] == 0) { mu[i * prime[j]] = 0; break; }
			mu[i * prime[j]] = -mu[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + mu[i];
	}
}

int k;
inline int get_ans (int a, int b) { // 每次get i: 1 ~ a; j: 1 ~ b 的ans
	a /= k; b /= k;
	
	int m = min (a, b); // 要不然下取整以后就是0
	int l = 1, r = 0;

	int ans = 0;
	for (l = 1; l <= m; l = r + 1) {
		r = min (a / (a / l), b / (b / l));
		ans += (a / l) * (b / l) * (sum[r] - sum[l - 1]);
	}

	return ans;
}

signed main () {
	fastread
	
	init();

	cin >> T;
	while (T--) {
		int a, b, c, d; cin >> a >> b >> c >> d >> k;
		
		int ans = get_ans(b, d) - get_ans(b, c - 1) - get_ans(a - 1, d) + get_ans(a - 1, c - 1);

		cout << ans << endl;
	}

	return 0;
}
