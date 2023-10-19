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

const int maxn = 1000005;

int n, m;
int a[maxn];

template <int maxn, typename val_t>
struct PresistentSegmentTree {
	struct Node {
		int ls, rs;
		val_t val;
	} tr[maxn << 5];

	int tot, root[maxn]; 
	inline int newNode (Node old = Node { 0, 0, 0 }) { tr[++tot] = old; return tot; }

	PresistentSegmentTree () { tot = 0; memset (root, 0, sizeof (root)); }

	void build (int &now, int l, int r) {
		now = newNode ();

		if (l == r) { tr[now].val = a[l]; return; }

		int mid = (l + r) >> 1;
		build (tr[now].ls, l, mid);
		build (tr[now].rs, mid + 1, r);
	}

	void modify (int &now, int old, int l, int r, int pos, val_t val) {
		now = newNode (tr[old]);

		if (l == r) { tr[now].val = val; return; }

		int mid = (l + r) >> 1;
		if (pos <= mid) { modify (tr[now].ls, tr[old].ls, l, mid, pos, val); }
		if (pos > mid) { modify (tr[now].rs, tr[old].rs, mid + 1, r, pos, val); }
	}

	val_t query (int now, int l, int r, int pos) {
		if (not now) { return 0; }
		if  (l == r) { return tr[now].val; }

		int mid = (l + r) >> 1;
		if (pos <= mid) { return query (tr[now].ls, l, mid, pos); }
		if (pos > mid) { return query (tr[now].rs, mid + 1, r, pos); }
		return 0;
	}
};

PresistentSegmentTree<maxn, int> tr;

int main () {
	fastread

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
	tr.build (tr.root[0], 1, n);

	for (int now = 1; now <= m; now ++) {
		int v, op, pos; std::cin >> v >> op >> pos;

		if (op == 1) {
			int val; std::cin >> val;
			tr.modify (tr.root[now], tr.root[v], 1, n, pos, val);
		} else if (op == 2) {
			std::cout << tr.query (tr.root[v], 1, n, pos) << "\n";
			tr.root[now] = tr.root[v];
		}
	}

	return 0;
}
