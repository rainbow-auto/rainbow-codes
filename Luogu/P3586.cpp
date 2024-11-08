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

const int maxn = 1000005;

int n, m;

i64 a[maxn];

struct Node {
	int ls, rs;
	i64 sum; // 和
	i64 col; // 种类
} tr[maxn << 5];

int root, tot;

inline void pushUp (int now) {
	tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum;
	tr[now].col = tr[tr[now].ls].col + tr[tr[now].rs].col;
}

void modify (int& now, i64 l, i64 r, i64 pos, i64 val) {
	if (not now) { now = ++tot; }

	if (l == r) {
		tr[now].sum += val * l;
		tr[now].col += val;
		return;
	}

	i64 mid = (l + r) >> 1;

	if (pos <= mid) { modify (tr[now].ls, l, mid, pos, val); }	
	else { modify (tr[now].rs, mid + 1, r, pos, val); }

	pushUp (now);
}

i64 queryCol (int now, i64 l, i64 r, i64 L, i64 R) {
	if (not now) { return 0; }
	if (L <= l and r <= R) { return tr[now].col; }

	i64 mid = (l + r) >> 1;

	i64 res = 0;
	if (L <= mid) { res += queryCol (tr[now].ls, l, mid, L, R); }
	if (R > mid) { res += queryCol (tr[now].rs, mid + 1, r, L, R); }
	return res;
}

i64 querySum (int now, i64 l, i64 r, i64 L, i64 R) {
	if (not now) { return 0; }
	if (L <= l and r <= R) { return tr[now].sum; }

	i64 mid = (l + r) >> 1;

	i64 res = 0;
	if (L <= mid) { res += querySum (tr[now].ls, l, mid, L, R); }
	if (R > mid) { res += querySum (tr[now].rs, mid + 1, r, L, R); }
	return res;
}

int main () {
	fastread

	std::cin >> n >> m;

	while (m--) {
		char op; std::cin >> op;

		if (op == 'U') {
			i64 k, val; std::cin >> k >> val;
			if (a[k]) { modify (root, 0, 1e9, a[k], -1); }
			a[k] = val;
			modify (root, 0, 1e9, a[k], 1);
		} else if (op == 'Z') {
			i64 c, s; std::cin >> c >> s;
			i64 sum = querySum (root, 0, 1e9, 0, s - 1);
			i64 col = queryCol (root, 0, 1e9, s, 1e9);
		
			std::cout << (((c - col) * s <= sum) ? "TAK" : "NIE") << "\n";
		}
	}

	return 0;
}
