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
int a[maxn];
int id[maxn];

struct FenwickTree {
	struct SegmentTree {
		struct Node {
			i64 sum;
			int ls, rs;
		} tr[maxn << 10];

		int root[maxn], tot;

		void modify (int& now, int l, int r, int pos, i64 val) {
			if (not now) { now = ++tot; }
			tr[now].sum += val;
		
			if (l == r) { return; }

			int mid = (l + r) >> 1;

			if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }
			if (pos > mid) { modify (tr[now].rs, mid + 1, r, pos, val); }
		}

		i64 query (int now, int l, int r, int L, int R) {
			if (not now) { return 0; }
			if (L <= l and r <= R) { return tr[now].sum; }

			int mid = (l + r) >> 1;

			i64 res = 0;
			if (L <= mid) { res += query (tr[now].ls, l, mid, L, R); }
			if (R > mid) { res += query (tr[now].rs, mid + 1, r, L, R); }

			return res;
		}
	} seg;

	inline int lowbit (int x) { return x & (-x); }

	inline void modify (int pos, int val, int delta) {
		for (int i = pos; i <= n; i += lowbit (i)) { seg.modify (seg.root[i], 0, 1e9, val, delta); }
	}

	// L, R 为 pos; l, r 为 val
	inline i64 query (int L, int R, int l, int r) {
		if (L > R) { return 0; }
		if (l > r) { return 0; }

		i64 res = 0;
		for (int i = R; i; i -= lowbit (i)) { res += seg.query (seg.root[i], 0, 1e9, l, r); }
		for (int i = L - 1; i; i -= lowbit (i)) { res -= seg.query (seg.root[i], 0, 1e9, l, r); }
		return res;
	}
} tr;

int main () {
	fastread

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; tr.modify (i, a[i], 1); id[a[i]] = i; }

	i64 ansnow = 0;
	for (int i = 1; i <= n; i++) {
		ansnow += tr.query (1, i, a[i] + 1, n);
	}

	while (m--) {
		int x; std::cin >> x;
		
		int i = id[x];

		std::cout << ansnow << "\n";

		tr.modify (i, x, -1);

		ansnow -= tr.query (1, i, x + 1, n);
		ansnow -= tr.query (i, n, 0, x - 1);
	}

	return 0;
}
