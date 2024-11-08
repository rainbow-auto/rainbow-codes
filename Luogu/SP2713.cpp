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

int n;
long long a[maxn];

namespace SegmentTree {
	struct Node {
		long long sum;
		long long mx;
	} tr[maxn << 4];

	inline void pushUp (int now) {
		tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
		tr[now].mx = max (tr[now << 1].mx, tr[now << 1 | 1].mx);
	}

	void build (int now, int l, int r) {
		if (l == r) {
			tr[now].sum = tr[now].mx = a[l];
			return;
		}

		int mid = (l + r) >> 1;

		build (now << 1, l, mid);
		build (now << 1 | 1, mid + 1, r);

		pushUp (now);
	}

	void range_sqrt (int now, int l, int r, int L, int R) {
		if (l == r) {
			tr[now].sum = sqrt (tr[now].sum);
			tr[now].mx = sqrt (tr[now].mx);
			return;
		}

		int mid = (l + r) >> 1;

		if (L <= mid and tr[now << 1].mx > 1) { range_sqrt (now << 1, l, mid, L, R); }
		if (R > mid and tr[now << 1 | 1].mx > 1) { range_sqrt (now << 1 | 1, mid + 1, r, L, R); }

		pushUp (now); 
	}

	long long query (int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) {
			return tr[now].sum;
		}

		int mid = (l + r) >> 1;
		long long res = 0ll;

		if (L <= mid) { res += query (now << 1, l, mid, L, R); }
		if (R > mid) { res += query (now << 1 | 1, mid + 1, r, L, R); }

		return res;
	}
}

int main () {
	fastread
	
	int tot = 0;

	while (cin >> n) {
		cout << "Case #" << (++tot) << ":" << endl;
		
		for (int i = 1; i <= n; i++) { cin >> a[i]; }

		SegmentTree::build (1, 1, n);

		int m; cin >> m;

		while (m --) {
			int op, x, y; cin >> op >> x >> y;

			if (x > y) { swap (x, y); }

			if (op == 0) {
				SegmentTree::range_sqrt (1, 1, n, x, y);
			} else if (op == 1) {
				cout << SegmentTree::query (1, 1, n, x, y) << endl;
			}
		}

		cout << endl;
	}

	return 0;
}
