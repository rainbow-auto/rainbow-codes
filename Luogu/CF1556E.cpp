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

#define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 200005;

int n, q;
i64 a[maxn], b[maxn];
i64 c[maxn];

struct Node {
	i64 mx, mn;
	Node () { mx = -1e18; mn = 1e18; }
	friend Node operator + (Node a, Node b) { 
		Node res;
		res.mx = std::max (a.mx, b.mx);
		res.mn = std::min (a.mn, b.mn);
		return res;
	}
} tr[maxn << 4];

inline void pushUp (int now) { tr[now] = tr[now << 1] + tr[now << 1 | 1]; }

void modify (int now, int l, int r, int pos, i64 val) {
	if (l == r) { tr[now].mn = std::min (tr[now].mn, val); tr[now].mx = std::max (tr[now].mx, val); return; }
	int mid = (l + r) >> 1;
	if (pos <= mid) { modify (now << 1, l, mid, pos, val); }
	else { modify (now << 1 | 1, mid + 1, r, pos, val); }
	pushUp (now);
}

Node query (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) { return tr[now]; }
	int mid = (l + r) >> 1;
	Node res;
	if (L <= mid) { res = res + query (now << 1, l, mid, L, R); }
	if (R > mid) { res = res + query (now << 1 | 1, mid + 1, r, L, R); }
	return res;
} 

i64 sum[maxn];

int main () {
	fastread
	
	std::cin >> n >> q;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
	for (int i = 1; i <= n; i++) { std::cin >> b[i]; }

	for (int i = 1; i <= n; i++) { c[i] = a[i] - b[i]; }
	for (int i = 1; i <= n; i++) { sum[i] = sum[i - 1] + c[i]; modify (1, 1, n, i, sum[i]); }

	while (q--) {
		int l, r; std::cin >> l >> r;

		auto info = query (1, 1, n, l, r);

		if (info.mx - sum[l - 1] > 0) { std::cout << "-1\n"; continue; }
		if (sum[r] - sum[l - 1] != 0) { std::cout << "-1\n"; continue; }

		std::cout << sum[l - 1] - info.mn << "\n";
	}

	return 0;
}
