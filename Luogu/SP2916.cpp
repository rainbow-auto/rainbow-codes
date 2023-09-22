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

const int maxn = 100005;

int n, m;
int a[maxn];

namespace SegmentTree {
	struct Node {
		int sum;
		int maxL, maxR;
		int maxSum;
	} tr[maxn << 4];
	
	Node merge (Node l, Node r) {
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

	Node query (int now, int l, int r, int L, int R) {
		if (L > R) { return Node { 0, 0, 0, 0 }; }

		if (L <= l and r <= R) { return tr[now]; }

		int mid = (l + r) >> 1;

		if (R <= mid) { return query (now << 1, l, mid, L, R); }
		if (L > mid) { return query (now << 1 | 1, mid + 1, r, L, R); }

		return merge ( query (now << 1, l, mid, L, R), query (now << 1 | 1, mid + 1, r, L, R) );
	}
}

int query (int x1, int y1, int x2, int y2) {
	if (y1 < x2) { // 不存在交集
		SegmentTree::Node midNode = SegmentTree::query (1, 1, n, y1 + 1, x2 - 1);
		SegmentTree::Node lNode = SegmentTree::query (1, 1, n, x1, y1);
		SegmentTree::Node rNode = SegmentTree::query (1, 1, n, x2, y2);

		return midNode.sum + lNode.maxR + rNode.maxL;
	} else {
		SegmentTree::Node midNode = SegmentTree::query (1, 1, n, x2, y1);
		SegmentTree::Node lNode = SegmentTree::query (1, 1, n, x1, x2 - 1);
		SegmentTree::Node rNode = SegmentTree::query (1, 1, n, y1 + 1, y2);

		int res = midNode.maxSum;
		res = max (res, SegmentTree::merge (lNode, midNode).maxR + rNode.maxL );
		res = max (res, SegmentTree::merge (midNode, rNode).maxL + lNode.maxR );

		return res;
	}
}

int main () {
	// fastread
	
	int T; cin  >> T;

	while (T--) {
		cin >> n;

		for (int i = 1; i <= n; i++) { cin >> a[i]; }
		
		SegmentTree::build (1, 1, n);
		
		cin >> m;

		while (m --) {
			int a, b, c, d;

			cin >> a >> b >> c >> d;

			cout << query (a, b, c, d) << endl;
		}
	}


	return 0;
}
