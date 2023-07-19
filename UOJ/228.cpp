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

#define int long long

using namespace std;

const int maxn = 100005;

int n, m;

int a[maxn];

struct Node {
	int mn, mx, sum;
	int tag; // 用于加法的懒标记
};

Node tr[maxn << 2];

inline void push_up (int x) {
	tr[x].mn = min (tr[x << 1].mn, tr[x << 1 | 1].mn);
	tr[x].mx = max (tr[x << 1].mx, tr[x << 1 | 1].mx);
	tr[x].sum = tr[x << 1].sum + tr[x << 1 | 1].sum;
}

inline void push_down (int x, int l, int r) { // 懒标记下传
	int tag = tr[x].tag;
	int mid = (l + r) >> 1;

	tr[x << 1].tag += tag;
	tr[x << 1 | 1].tag += tag;
	tr[x << 1].mn += tag;
	tr[x << 1 | 1].mn += tag;
	tr[x << 1].mx += tag;
	tr[x << 1 | 1].mx += tag;
	tr[x << 1].sum += tag * (mid - l + 1);
	tr[x << 1 | 1].sum += tag * (r - mid);
	tr[x].tag = 0;
}

void build_tree (int now, int l, int r) {
	if (l == r) {
		tr[now].mn = a[l];
		tr[now].mx = a[l];
		tr[now].sum = a[l];
		tr[now].tag = 0;
		return;
	}

	int mid = (l + r) >> 1;

	build_tree (now << 1, l, mid);
	build_tree (now << 1 | 1, mid + 1, r);

	push_up (now);
}

void range_add (int now, int l, int r, int L, int R, int val) {
	if (L <= l and r <= R) {
		tr[now].mn += val;
		tr[now].mx += val;
		tr[now].sum += val * (r - l + 1);
		tr[now].tag += val;
		return;
	}

	push_down (now, l, r);

	int mid = (l + r) >> 1;	

	if (L <= mid) {
		range_add (now << 1, l, mid, L, R, val);
	}
	if (R > mid) {
		range_add (now << 1 | 1, mid + 1, r, L, R, val);
	}
	
	push_up (now);
} 

inline int _sqrt (int x) { return sqrt(x); }  // 很巧妙的强制类型转换

inline void range_sqrt (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) {
		if ( _sqrt(tr[now].mn) - _sqrt(tr[now].mx) == tr[now].mn - tr[now].mx) { // 开根前的差等于开根后的差
			int delta = tr[now].mn - _sqrt(tr[now].mn);
			tr[now].mn -= delta;
			tr[now].mx -= delta;
			tr[now].tag -= delta;
			tr[now].sum -= (r - l + 1) * delta;
			return;
		}
		push_down (now, l, r);

		int mid = (l + r) >> 1;
		range_sqrt (now << 1, l, mid, L, R); // 暴力开根
		range_sqrt (now << 1 | 1, mid + 1, r, L, R); // 暴力开根
	
		push_up(now);
		return;
	}
	
	push_down (now, l, r); // 先进行push_down
	
	int mid = (l + r) >> 1;
	if (L <= mid) {
		range_sqrt (now << 1, l, mid, L, R);
	}
	if (R > mid) {
		range_sqrt (now << 1 | 1, mid + 1, r, L, R);
	}

	push_up(now); // 最后不要忘了更新
}

int query (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) {
		return tr[now].sum;
	}

	push_down(now, l, r);

	int mid = (l + r) >> 1;

	int res = 0;
	if (L <= mid) {
		res += query (now << 1, l, mid, L, R);
	}
	if (R > mid) {
		res += query (now << 1 | 1, mid + 1, r, L, R);
	}
	
	return res;
}

signed main () {
	// fastread

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	build_tree(1, 1, n);

	for (int i = 1; i <= m; i++) {
		int op; cin >> op;
		
		if (op == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			range_add (1, 1, n, l, r, x);
		} else if (op == 2) {
			int l, r;
			cin >> l >> r;
			range_sqrt (1, 1, n, l, r);
		} else if (op == 3) {
			int l, r;
			cin >> l >> r;
			cout << query (1, 1, n, l, r) << endl;
		}
	}

	return 0;
}
