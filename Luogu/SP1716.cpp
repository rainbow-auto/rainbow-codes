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

const int maxn = 50005;

int n;
int a[maxn];

namespace SegmentTree {
	struct Node {
		int sum;
		int maxL, maxR;
		int maxSum;
	} tr[maxn << 4];

	inline Node merge (Node l, Node r) {
		Node res;

		res.sum = l.sum + r.sum;

		res.maxL = max (l.maxL, l.sum + r.maxL);
		res.maxR = max (r.maxR, r.sum + l.maxR);

		res.maxSum = max ( max (l.maxSum, r.maxSum), l.maxR + r.maxL );

		return res;
	}

	void build (int now, int l, int r) {
		if (l == r) {
			tr[now].sum = tr[now].maxL = tr[now].maxR = tr[now].maxSum = a[l];
			return;
		}

		int mid = (l + r) >> 1;

		build (now << 1, l, mid);
		build (now << 1 | 1, mid + 1, r);

		tr[now] = merge (tr[now << 1], tr[now << 1 | 1]);
	}

	void change (int now, int l, int r, int pos, int val) {
		if (l == r) {
			tr[now].sum = tr[now].maxL = tr[now].maxR = tr[now].maxSum = val;
			return;
		}

		int mid = (l + r) >> 1;

		if (pos <= mid) { change (now << 1, l, mid, pos, val); }
		else { change (now << 1 | 1, mid + 1, r, pos, val); }

		tr[now] = merge (tr[now << 1], tr[now << 1 | 1]);
	}

	Node query (int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) { return tr[now]; }

		int mid = (l + r) >> 1;

		if (R <= mid) { return query (now << 1, l, mid, L, R); }
		if (L > mid) { return query (now << 1 | 1, mid + 1, r, L, R); }

		return merge ( query (now << 1, l, mid, L, R), query (now << 1 | 1, mid + 1, r, L, R) );
	}
}

int main () {
	fastread

	cin >> n;

	for (int i = 1; i <= n; i++) { cin >> a[i]; }

	SegmentTree::build (1, 1, n);

	int m; cin >> m;

	while (m --) {
		int op, x, y;
		cin >> op >> x >> y;

		if (op == 0) {
			SegmentTree::change (1, 1, n, x, y);
		} else if (op == 1) {
			cout << SegmentTree::query (1, 1, n, x, y).maxSum << endl;
		}
	}	

	return 0;
}
