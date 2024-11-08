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

int n, q;
int a[maxn];

struct FenwickTree {
	struct SegmentTree {
		struct Node {
			int ls, rs;
			int sum;
		} tr[maxn << 9];

		std::vector<int> Add;
		std::vector<int> Sub;
		
		int root[maxn], tot;

		void modify (int& now, int l, int r, int pos, int val) {
			if (not now) { now = ++tot; }
			tr[now].sum += val;

			if (l == r) { return; }	
			
			int mid = (l + r) >> 1;

			if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }
			if (pos > mid) { modify (tr[now].rs, mid + 1, r, pos, val); }
		}

		int query (int l, int r, int k) {
			if (l == r) { return l; }
			
			int sum = 0; 
			for (auto x : Add) { sum += tr[tr[x].ls].sum; }
			for (auto x : Sub) { sum -= tr[tr[x].ls].sum; }

			for (auto& x : Add) { x = (k <= sum) ? tr[x].ls : tr[x].rs; }
			for (auto& x : Sub) { x = (k <= sum) ? tr[x].ls : tr[x].rs; }

			int mid = (l + r) >> 1;

			return (k <= sum) ? query (l, mid, k) : query (mid + 1, r, k - sum);
		}
	} seg;
	
	inline int lowbit (int x) { return x & (-x); }

	inline void ins (int pos, int val) {
		for (int i = pos; i <= n; i += lowbit (i)) { seg.modify (seg.root[i], 0, 1e9, val, 1); }	
	}
	
	inline void del (int pos, int val) {
		for (int i = pos; i <= n; i += lowbit (i)) { seg.modify (seg.root[i], 0, 1e9, val, -1); }
	}

	inline int query (int l, int r, int k) {
		seg.Add.clear (); for (int i = r; i; i -= lowbit (i)) { seg.Add.push_back (seg.root[i]); }
		seg.Sub.clear (); for (int i = l - 1; i; i -= lowbit (i)) { seg.Sub.push_back (seg.root[i]); }

		return seg.query (0, 1e9, k);
	}
} tr;


int main () {
	fastread
	
	std::cin >> n >> q;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; tr.ins (i, a[i]); }

	while (q --) {
		char op; std::cin >> op;

		if (op == 'Q') {
			int l, r; std::cin >> l >> r;
			int k; std::cin >> k;

			std::cout << tr.query (l, r, k) << "\n";

		} else if (op == 'C') {
			int x, y; std::cin >> x >> y;
			
			tr.del (x, a[x]);
			a[x] = y;
			tr.ins (x, a[x]);
		}
	}

	return 0;
}
