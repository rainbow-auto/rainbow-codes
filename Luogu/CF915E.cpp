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

const int maxn = 300005;

int n, q;

struct Node {
	int sum;
	int tag;
	int ls, rs;

	Node () { sum = ls = rs = 0; tag = -1; }

} tr[maxn * 55];

int root, tot;

inline void pushUp (int now) { tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum; }

inline void update (int& now, int l, int r, int val) {
	if (not now) { now = ++tot; }
	tr[now].sum = (r - l + 1) * val;
	tr[now].tag = val;
}

inline void pushDown (int now, int l, int r) {
	if (tr[now].tag == -1) { return; }
	int mid = (l + r) >> 1;
	update (tr[now].ls, l, mid, tr[now].tag);
	update (tr[now].rs, mid + 1, r, tr[now].tag);
	tr[now].tag = -1;
}

void modify (int& now, int l, int r, int L, int R, int val) {
	if (not now) { now = ++tot; }
	if (L <= l and r <= R) { update (now, l, r, val); return; }

	pushDown (now, l, r);
	int mid = (l + r) >> 1;
	if (L <= mid) { modify (tr[now].ls, l, mid, L, R, val); }
	if (R > mid) { modify (tr[now].rs, mid + 1, r, L, R, val); }
	pushUp (now);
}

int main () {
	fastread

	std::cin >> n;
	
	modify (root, 1, n, 1, n, 1);

	std::cin >> q;

	while (q--) {
		int l, r, k; std::cin >> l >> r >> k;

		if (k == 1) { modify (root, 1, n, l, r, 0); }
		if (k == 2) { modify (root, 1, n, l, r, 1); }

		std::cout << tr[root].sum << "\n";
	}

	return 0;
}
