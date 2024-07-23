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

// #define RainbowAutomatonDebugFlag

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << #x << " : " << x << "\n";
#else
#define db(x) void (0);
#endif

const int maxn = 500005;

int n, m;

struct Node {
	int ls, rs;
	int mx;
	int tag;
} tr[maxn << 5];

inline void pushUp (int now) { tr[now].mx = std::max (tr[now << 1].mx, tr[now << 1 | 1].mx); }

inline void update (int now, int val) {
	tr[now].mx += val;
	tr[now].tag += val;
}

inline void pushDown (int now) {
	if (not tr[now].tag) { return; }

	update (now << 1, tr[now].tag);
	update (now << 1 | 1, tr[now].tag);
	tr[now].tag = 0;
}

void modify (int now, int l, int r, int L, int R, int val) {
	if (L <= l and r <= R) { update (now, val); return; }
	
	pushDown (now);
	
	i64 mid = (l + r) >> 1;
	if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
	if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }

	pushUp (now);
}

inline int query_all () { return tr[1].mx; }

struct Range {
	i64 l, r;
	i64 len;

	friend bool operator < (Range a, Range b) {
		return a.len < b.len; 
	}
} rs[maxn];

int vals[maxn << 1], cnt;

int main () {
	fastread
	
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) { 
		std::cin >> rs[i].l >> rs[i].r; 
		rs[i].len = rs[i].r - rs[i].l; 
		
		vals[++cnt] = rs[i].r;
		vals[++cnt] = rs[i].l;
	}
	std::sort (rs + 1, rs + n + 1);

	std::sort (vals + 1, vals + cnt + 1);
	cnt = std::unique (vals + 1, vals + cnt + 1) - (vals + 1);

	for (int i = 1; i <= n; i++) { 
		rs[i].l = std::lower_bound (vals + 1, vals + cnt + 1, rs[i].l) - vals;
		rs[i].r = std::lower_bound (vals + 1, vals + cnt + 1, rs[i].r) - vals;
	}

	i64 ans = 2e9;
	int l = 1;
	for (int r = 1; r <= n; r++) {
		modify (1, 1, cnt, rs[r].l, rs[r].r, 1); // 每次直接加入 r

		while (query_all () >= m) {
			ans = std::min (ans, rs[r].len - rs[l].len);
			modify (1, 1, cnt, rs[l].l, rs[l].r, -1);
			l++;
		}
	}

	if (ans == 2e9) { std::cout << "-1\n"; }
	else { std::cout << ans << "\n"; }

	return 0;
}
