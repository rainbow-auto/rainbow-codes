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

const int maxn = 2000005;

int n, q, k;

int a[maxn];

struct Query {
	int l, r;
	int id;

	friend bool operator < (Query x, Query y) {
		if (x.r != y.r) { return x.r < y.r; }
		else { return x.l < y.l; }
	}
};

std::vector <Query> qs;

int ans[maxn];

int tr[maxn];
inline int lowbit (int x) { return x & (-x); }

inline void _add (int pos, int val) { for (int i = pos; i <= n; i += lowbit (i)) { tr[i] += val; } }
inline void add (int l, int r, int val) { _add (r + 1, -val); _add (l, val); }

inline int query (int pos) { int res = 0; for (int i = pos; i; i -= lowbit (i)) { res += tr[i]; } return res; }

int pre[maxn];
int prepre[maxn];

int main () {
	fastread
	
	std::cin >> n >> k >> q;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

	for (int i = 1; i <= q; i++) {
		int l, r; std::cin >> l >> r;
		qs.push_back (Query { l, r, i });
	}

	std::sort (qs.begin (), qs.end ());

	int last_r = 0;
	for (auto now : qs) {
		for (int rnow = last_r + 1; rnow <= now.r; rnow ++) {
			if (pre[a[rnow]] == 0) { pre[a[rnow]] = rnow; continue; }

			add (prepre[a[rnow]] + 1, pre[a[rnow]], 1);

			prepre[a[rnow]] = pre[a[rnow]];
			pre[a[rnow]] = rnow;
		} 

		last_r = now.r;

		ans[now.id] = query (now.l);
	}

	for (int i = 1; i <= q; i++) { std::cout << ans[i] << "\n"; }

	return 0;
}
