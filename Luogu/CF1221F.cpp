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

int n;

struct Range {
	int l, r;
	int c;
} rs[maxn];

int vals[maxn], tot;

struct Node {
	std::pair <i64, int> mx;
	i64 tag;
	bool cov;
} tr[maxn << 2];

inline void pushUp (int now) {
	tr[now].mx = std::max (tr[now << 1].mx, tr[now << 1 | 1].mx);
}

inline void update (int now, i64 val) {
	tr[now].mx.first += val;
	tr[now].tag += val;
	tr[now].cov = true;
}

inline void pushDown (int now) {
	if (not tr[now].cov) { return; }
	update (now << 1, tr[now].tag);
	update (now << 1 | 1, tr[now].tag);
	tr[now].tag = 0; tr[now].cov = false;
}

void build (int now, int l, int r) {
	if (l == r) { tr[now] = Node { { -vals[l], l } , 0, false }; return; }

	int mid = (l + r) >> 1;
	build (now << 1, l, mid);
	build (now << 1 | 1, mid + 1, r);

	pushUp (now);
}

void modify (int now, int l, int r, int L, int R, i64 val) {
	if (L <= l and r <= R) { update (now, val); return; }

	pushDown (now);

	int mid = (l + r) >> 1;
	if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
	if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }
	
	pushUp (now);
}

std::pair <i64, int> query (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) { return tr[now].mx; }

	pushDown (now);

	int mid = (l + r) >> 1;
	if (R <= mid) { return query (now << 1, l, mid, L, R); }
	if (L > mid) { return query (now << 1 | 1, mid + 1, r, L, R); }

	return std::max (query (now << 1, l, mid, L, R), query (now << 1 | 1, mid + 1, r, L, R));
}

std::vector < std::pair <int, i64> > add[maxn]; 

int main () {
	fastread

	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		int x, y, c; std::cin >> x >> y >> c;
		rs[i] = Range { std::min (x, y), std::max (x, y), c };
		vals[++tot] = x;
		vals[++tot] = y;
	}

	std::sort (vals + 1, vals + tot + 1);
	tot = std::unique (vals + 1, vals + tot + 1) - (vals + 1);
	
	for (int i = 1; i <= n; i++) {
		rs[i].l = std::lower_bound (vals + 1, vals + tot + 1, rs[i].l) - vals;
		rs[i].r = std::lower_bound (vals + 1, vals + tot + 1, rs[i].r) - vals;
		add[rs[i].l].push_back ({ rs[i].r, rs[i].c });
	}

	build (1, 1, tot);

	i64 ans = 0;

	int posL = 2e9, posR = 2e9;

	for (int l = tot; l >= 1; l--) {
		for (auto now : add[l]) {
			modify (1, 1, tot, now.first, tot, now.second);
		}

		std::pair <i64, int> mx = query (1, 1, tot, l, tot);
		i64 ansnow = mx.first + vals[l];

		if (ansnow >= ans) { ans = ansnow; posL = vals[l]; posR = vals[mx.second]; }
	}

	std::cout << ans << "\n";
	std::cout << posL << " " << posL << " " << posR << " " << posR << "\n";

	return 0;
}
