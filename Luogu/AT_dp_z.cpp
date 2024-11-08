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

struct Line {
	i64 k, b;
} a[maxn];

int tot;

inline void addLine (i64 k, i64 b) {
	a[++tot] = Line {k, b};
}

inline i64 calc (int id, i64 x) { return a[id].k * x + a[id].b; }

int tr[maxn << 2];

void insert (int p, int l, int r, int f) {
	int &g = tr[p];
	int mid = (l + r) >> 1;
	i64 val1 = calc (f, mid);
	i64 val2 = calc (g, mid);

	if (val1 < val2) { std::swap (f, g); }

	i64 fl = calc (f, l), fr = calc (f, r);
	i64 gl = calc (g, l), gr = calc (g, r);
	
	if (fl < gl) { insert (p << 1, l, mid, f); }
	if (fr < gr) { insert (p << 1 | 1, mid + 1, r, f); }
} 

void modify (int now, int l, int r, int L, int R, int id) {
	if (L <= l and r <= R) { 
		if (!tr[now]) { tr[now] = id; }
		else { insert (now, l, r, id); }
		return;
	}

	int mid = (l + r) >> 1;
	if (L <= mid) { modify (now << 1, l, mid, L, R, id); }
	if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, id); }
}

i64 query (int now, int l, int r, int pos) {
	i64 val = calc (tr[now], pos);
	if (l == r) { return val; }
	int mid = (l + r) >> 1;
	if (pos <= mid)	{ val = std::min (val, query (now << 1, l, mid, pos)); }
	if (pos > mid) { val = std::min (val, query (now << 1 | 1, mid + 1, r, pos)); }
	return val;
}

const i64 hmax = 1e6;

int n;
i64 c;
i64 h[maxn];

i64 dp[maxn];

int main () {
	fastread

	std::cin >> n >> c;

	for (int i = 1; i <= n; i++) { std::cin >> h[i]; }

	addLine (-2 * h[1], h[1] * h[1]);
	modify (1, 1, hmax, 1, hmax, tot);

	for (int i = 2; i <= n; i++) {
		dp[i] = query (1, 1, hmax, h[i]) + h[i] * h[i] + c;
		addLine (-2 * h[i], dp[i] + h[i] * h[i]);
		modify (1, 1, hmax, 1, hmax, tot);
	}

	std::cout << dp[n] << "\n";

	return 0;
}
