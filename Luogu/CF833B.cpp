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

const int maxn = 35005;
const int maxk = 51;

int n, k;
int a[maxn];

int pre[maxn];

struct Tree {
	struct Node {
		int mx;
		int tag;
	} tr[maxn << 2];

	inline void update (int now, int l, int r, int val) {
		tr[now].mx += val;
		tr[now].tag += val;
	}

	inline void pushDown (int now, int l, int r) {
		if (not tr[now].tag) { return; }
		int mid = (l + r) >> 1;
		update (now << 1, l, mid, tr[now].tag);
		update (now << 1 | 1, mid + 1, r, tr[now].tag);
		tr[now].tag = 0;
	}

	inline void pushUp (int now) {
		tr[now].mx = std::max (tr[now << 1].mx, tr[now << 1 | 1].mx);
	}

	void modify (int now, int l, int r, int L, int R, int val) {
		if (L <= l and r <= R) { update (now, l, r, val); return; }

		pushDown (now, l, r);

		int mid = (l + r) >> 1;
		if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
		if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }

		pushUp (now);
	}

	int query (int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) { return tr[now].mx; }

		pushDown (now, l, r);

		int res = 0;

		int mid = (l + r) >> 1;
		if (L <= mid) { res = std::max (res, query (now << 1, l, mid, L, R)); }
		if (R > mid) { res = std::max (res, query (now << 1 | 1, mid + 1, r, L, R)); }

		return res;
	}
} dp[maxk];

int main () {
	fastread
	
	std::cin >> n >> k;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

	for (int i = 1; i <= n; i++) {
		
		// update w in dp[]
		for (int j = 0; j <= k; j++) { dp[j].modify (1, 0, n, pre[a[i]], i - 1, 1); }
		
		for (int j = 1; j <= k; j++) {
			dp[j].modify (1, 0, n, i, i, dp[j - 1].query (1, 0, n, 0, i - 1));
		}
		
		pre[a[i]] = i;
	}

	std::cout << dp[k].query (1, 0, n, n, n) << "\n";

	return 0;
}
