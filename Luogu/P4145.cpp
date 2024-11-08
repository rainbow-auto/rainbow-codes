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

inline void pushUp (int x) {
	tr[x].sum = tr[x << 1].sum + tr[x << 1 | 1].sum;
	tr[x].mx = max (tr[x << 1].mx, tr[x << 1 | 1].mx);
}

void buildTree (int now, int l, int r) {
	if (l == r) {
		tr[now].mx = tr[now].sum = a[l];
		return;
	}

	int mid = (l + r) >> 1;
	buildTree (now << 1, l, mid);
	buildTree (now << 1 | 1, mid + 1, r);

	pushUp (now);
}

void range_sqrt (int now, int l, int r, int L, int R) {
	if (l == r) {
		tr[now].mx = sqrt (tr[now].mx);
		tr[now].sum = sqrt (tr[now].sum);
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

	long long res = 0;
	if (L <= mid) { res += query (now << 1, l, mid, L, R); }
	if (R > mid) { res += query (now << 1 | 1, mid + 1, r, L, R); }

	return res;
}

int main () {
	fastread
	
	cin >> n;

	for (int i = 1; i <= n; i++) { cin >> a[i]; }

	buildTree (1, 1, n);

	cin >> m;

	while (m --) {
		int opt, l, r; cin >> opt >> l >> r;
		
		if (l > r) { swap (l, r); }

		if (opt == 0) {
			range_sqrt (1, 1, n, l, r);
		} else if (opt == 1) {
			cout << query (1, 1, n, l, r) << endl;
		}
	}

	return 0;
}
