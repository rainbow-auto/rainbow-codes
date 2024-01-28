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

const int maxn = 100005;

int n, m;

i64 a[maxn];

struct Node {
	i64 sum;

	i64 tag;
	bool cov;
} tr[maxn << 4];

inline void pushUp (int now) {
	tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
}

inline void update (int now, int l, int r, i64 val) {
	tr[now].sum += 1ll * (r - l + 1) * val;
	tr[now].tag += val;
	tr[now].cov = true;
}

inline void pushDown (int now, int l, int r) {
	if (not tr[now].cov) { return; }
	int mid = (l + r) >> 1;
	update (now << 1, l, mid, tr[now].tag);
	update (now << 1 | 1, mid + 1, r, tr[now].tag);
	tr[now].cov = false; tr[now].tag = 0;
}

void build (int now, int l, int r) {
	if (l == r) {
		// tr[now] = Node { a[l], 0, false };
		tr[now].sum = a[l];
		return;
	}

	int mid = (l + r) >> 1;
	build (now << 1, l, mid);
	build (now << 1 | 1, mid + 1, r);
	
	pushUp (now);
}

void modify (int now, int l, int r, int L, int R, i64 val) {
	if (L <= l and r <= R) { update (now, l, r, val); return; }
	
	pushDown (now, l, r);

	int mid = (l + r) >> 1;
	if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
	if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }

	pushUp (now);
}

i64 query (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) { return tr[now].sum; }

	pushDown (now, l, r);

	int mid = (l + r) >> 1;
	
	i64 res = 0;
	if (L <= mid) { res += query (now << 1, l, mid, L, R); }
	if (R > mid) { res += query (now << 1 | 1, mid + 1, r, L, R); }

	return res;
}

int main () {
	fastread

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

	build (1, 1, n);

	for (int i = 1; i <= m; i++) {
		int op; std::cin >> op;

		if (op == 1) {
			int x, y; std::cin >> x >> y;
			i64 k; std::cin >> k;

			modify (1, 1, n, x, y, k);
		} else {
			int x, y; std::cin >> x >> y;
			std::cout << query (1, 1, n, x, y) << "\n";
		}
	}		

	return 0;
}
