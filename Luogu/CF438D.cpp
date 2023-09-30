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
long long a[maxn];

struct Node {
	long long mx;
	long long sum;
} tr[maxn << 3];

inline void pushUp (int now) {
	tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
	tr[now].mx = max (tr[now << 1].mx, tr[now << 1 | 1].mx);
}

void build (int now, int l, int r) {
	if (l == r) {
		tr[now] = Node { a[l], a[l] };
		return;		
	}

	int mid = (l + r) >> 1;

	build (now << 1, l, mid);
	build (now << 1 | 1, mid + 1, r);

	pushUp (now);
}

void modify (int now, int l, int r, int pos, long long val) {
	if (l == r) {
		tr[now].mx = val;
		tr[now].sum = val;
		return;
	}

	int mid = (l + r) >> 1;

	if (pos <= mid) { modify (now << 1, l, mid, pos, val); }
	else { modify (now << 1 | 1, mid + 1, r, pos, val); }

	pushUp (now);
}

long long query (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) {
		return tr[now].sum;	
	}

	int mid = (l + r) >> 1;
	
	long long res = 0;
	if (L <= mid) { res += query (now << 1, l, mid, L, R); }
	if (R > mid) { res += query (now << 1 | 1, mid + 1, r, L, R); }

	return res;
}

void range_mod (int now, int l, int r, int L, int R, long long p) {
	if (l == r) {
		tr[now].mx %= p;
		tr[now].sum %= p;
		
		return;
	}

	int mid = (l + r) >> 1;

	if (L <= mid and tr[now << 1].mx >= p) { range_mod (now << 1, l, mid, L, R, p); }
	if (R > mid and tr[now << 1 | 1].mx >= p) { range_mod (now << 1 | 1, mid + 1, r, L, R, p); }

	pushUp (now);
}	

int main () {
	fastread

	cin >> n >> m;

	for (int i = 1; i <= n; i++) { cin >> a[i]; }

	build (1, 1, n);

	while (m --) {
		int op; cin >> op;

		if (op == 1) {
			int l, r; cin >> l >> r;
			cout << query (1, 1, n, l, r) << endl;
		} else if (op == 2) {
			long long l, r, x; cin >> l >> r >> x;
			range_mod (1, 1, n, l, r, x);
		} else if (op == 3) {
			long long k, x; cin >> k >> x;
			modify (1, 1, n, k, x);
		}
	}

	return 0;
}
