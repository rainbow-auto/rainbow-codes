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

const int maxn = 200005;

int n, m;

int a[maxn];

struct Node {
	int sum;
	int ls, rs;
} tr[maxn << 7];

inline void pushUp (int now) { tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum; }

int tot;
inline int clone (Node old) { tr[++tot] = old; return tot; }

int root[maxn];

int r_max;

void modify (int &now, int old, int l, int r, int pos) {
	now = clone (tr[old]);

	if (l == r) { tr[now].sum ++; return; }

	int mid = (l + r) >> 1;

	if (pos <= mid) { modify (tr[now].ls, tr[old].ls, l, mid, pos); }
	else { modify (tr[now].rs, tr[old].rs, mid + 1, r, pos); }

	pushUp (now);
}

int query (int now, int old, int l, int r, int L, int R) {
	if (not (tr[now].sum - tr[old].sum)) { return 0; }
	if (L <= l and r <= R) { return tr[now].sum - tr[old].sum; }

	int res = 0;
	int mid = (l + r) >> 1;
	
	if (L <= mid) { res += query (tr[now].ls, tr[old].ls, l, mid, L, R); }
	if (R > mid) { res += query (tr[now].rs, tr[old].rs, mid + 1, r, L, R); }

	return res;
}

inline bool get (int x, int pos) { return (x >> pos) & 1; }

inline bool check (int l, int r, int L, int R) {
	L = std::max (0, L);
	R = std::min (r_max, R);
	if (L > R) { return false; }
	return query (root[r], root[l - 1], 0, r_max, L, R);
}

int main () {
	fastread
	
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { std::cin >> a[i]; r_max = std::max (r_max, a[i]); }

	root[0] = ++tot;
	for (int i = 1; i <= n; i++) {
		modify (root[i], root[i - 1], 0, r_max, a[i]);
	}

	for (int i = 1; i <= m; i++) {
		int b, x, l, r; std::cin >> b >> x >> l >> r;

		int ans = 0;

		for (int i = 18; i >= 0; i--) {
			if (get (b, i)) { 
				if (not check (l, r, ans - x, ans + (1 << i) - 1 - x)) { ans += (1 << i); }
			} else { 
				if (check (l, r, ans + (1 << i) - x, ans + (1 << (i + 1)) - 1 - x)) { ans += (1 << i); }
			}
		}

		std::cout << (ans xor b) << "\n";
	}

	return 0;
}
