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

const int maxn = 1000005;

int n, m;
int a[maxn];

struct Query {
	int l, r;

	int ans;
	int id;

	friend bool operator < (Query a, Query b) {
		if (a.r != b.r) { return a.r < b.r; }
		else { return a.l < b.l; }
	}
} q[maxn];

inline bool sort_by_id (Query a, Query b) { return a.id < b.id; }

namespace BIT {
	int tr[maxn];

	inline int lowbit (int x) { return x & (-x); }

	inline void add (int pos, int val) { for (int i = pos; i <= n; i += lowbit (i)) { tr[i] += val; } }
	inline int _query (int pos) { int res = 0; for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; } return res; }
	inline int query (int l, int r) { return _query (r) - _query (l - 1); }
}


int last[maxn];

int main () {
	fastread
	
	cin >> n;

	for (int i = 1; i <= n; i++) { cin >> a[i]; }

	cin >> m;

	for (int i = 1; i <= m; i++) {
		int l, r; cin >> l >> r;
		q[i] = Query { l, r, 0, i };
	}

	sort (q + 1, q + m + 1);

	int last_r = 0;
	for (int i = 1; i <= m; i++) {
		int l = q[i].l;
		int r = q[i].r;

		for (int j = last_r + 1; j <= r; j++) {
			if (last[a[j]]) { BIT::add (last[a[j]], -1); }
			BIT::add (j, 1); last[a[j]] = j; 
		}
		last_r = r;

		q[i].ans = BIT::query (l, r);
	}

	sort (q + 1, q + m + 1, sort_by_id);

	for (int i = 1; i <= m; i++) { cout << q[i].ans << endl; }

	return 0;
}
