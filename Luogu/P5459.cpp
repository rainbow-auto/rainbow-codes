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
const i64 maxv = 1e10;

template <int maxn, typename val_t>
struct SegmentTree {
	struct Node {
		int lson, rson;
		val_t sum;
	} tr[maxn << 4 + 5];

	int root;

	int tot;
	SegmentTree () { tot = 0; }

	inline void pushUp (int now) { tr[now].sum = tr[tr[now].lson].sum + tr[tr[now].rson].sum; }

	void add (int &now, val_t l, val_t r, val_t pos, val_t val) {
		if (not now) { now = ++tot; }
		if (l == r) { tr[now].sum += val; return; }

		val_t mid = (l + r) >> 1;
		if (pos <= mid) { add (tr[now].lson, l, mid, pos, val); }
		if (pos > mid) { add (tr[now].rson, mid + 1, r, pos, val); }
		
		pushUp (now);
	}

	val_t query (int now, val_t l, val_t r, val_t L, val_t R) {
		if (not now) { return 0; }
		if (L <= l and r <= R) { return tr[now].sum; }

		val_t mid = (l + r) >> 1;
		val_t res = 0;
		if (L <= mid) { res += query (tr[now].lson, l, mid, L, R); }
		if (R > mid) { res += query (tr[now].rson, mid + 1, r, L, R); }
		return res;
 	}
};

SegmentTree<maxn, i64> tr;

int n;
i64 L, R;
i64 sum[maxn];

int main () {
	fastread

	std::cin >> n >> L >> R;

	for (int i = 1; i <= n; i++) { std::cin >> sum[i]; sum[i] += sum[i - 1]; }
	
	tr.add (tr.root, -maxv, maxv, sum[0], 1);

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += tr.query (tr.root, -maxv, maxv, sum[i] - R, sum[i] - L);
		tr.add (tr.root, -maxv, maxv, sum[i], 1);
	}

	std::cout << ans << "\n";

	return 0;
}
