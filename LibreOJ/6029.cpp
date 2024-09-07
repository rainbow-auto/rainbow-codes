#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 100005;

int n, q;
int a[maxn];

struct Node {
	i64 sum;
	i64 mx, mn;
	i64 tag;
} tr[maxn << 3];

inline void pushUp (int now) {
	tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
	tr[now].mx = std::max (tr[now << 1].mx, tr[now << 1 | 1].mx);
	tr[now].mn = std::min (tr[now << 1].mn, tr[now << 1 | 1].mn);
}

inline void add (int now, int l, int r, i64 c) {
	tr[now].sum += c * (r - l + 1);
	tr[now].mx += c; tr[now].mn += c;
	tr[now].tag += c;
}

inline void pushDown (int now, int l, int r) {
	if (not tr[now].tag) { return; }
	int mid = (l + r) >> 1;
	add (now << 1, l, mid, tr[now].tag);
	add (now << 1 | 1, mid + 1, r, tr[now].tag);
	tr[now].tag = 0;
}

void build (int now, int l, int r) {
	if (l == r) {
		tr[now].sum = tr[now].mx = tr[now].mn = a[l];
		return;
	}

	int mid = (l + r) >> 1;
	build (now << 1, l, mid);
	build (now << 1 | 1, mid + 1, r);
	pushUp (now);
}

void range_add (int now, int l, int r, int L, int R, i64 val) {
	if (L <= l and r <= R) { add (now, l, r, val); return; }

	pushDown (now, l, r);

	int mid = (l + r) >> 1;
	if (L <= mid) { range_add (now << 1, l, mid, L, R, val); }
	if (R > mid) { range_add (now << 1 | 1, mid + 1, r, L, R, val); }

	pushUp (now);
}

inline int div_floor (i64 x, i64 d) {
	if (x > 0) { return x / d; }
	else { return (x - (d - 1)) / d; }
}

void range_div (int now, int l, int r, int L, int R, i64 d) {
	if (L <= l and r <= R) {
		if (tr[now].mx - div_floor (tr[now].mx, d) == tr[now].mn - div_floor (tr[now].mn, d)) {
			i64 delta = div_floor (tr[now].mx, d) - tr[now].mx;
			add (now, l, r, delta);
			return;
		}
	}

	pushDown (now, l, r);

	int mid = (l + r) >> 1;
	if (L <= mid) { range_div (now << 1, l, mid, L, R, d); }
	if (R > mid) { range_div (now << 1 | 1, mid + 1, r, L, R, d); }

	pushUp (now);
}

i64 query_sum (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) { return tr[now].sum; }

	pushDown (now, l, r);
	
	i64 res = 0;

	int mid = (l + r) >> 1;
	if (L <= mid) { res += query_sum (now << 1, l, mid, L, R); }
	if (R > mid) { res += query_sum (now << 1 | 1, mid + 1, r, L, R); }

	return res;
}

i64 query_mn (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) { return tr[now].mn; }

	pushDown (now, l, r);

	i64 res = 0x3f3f3f3f3f3f3f3f;

	int mid = (l + r) >> 1;
	if (L <= mid) { res = std::min (res, query_mn (now << 1, l, mid, L, R)); }
	if (R > mid) { res = std::min (res, query_mn (now << 1 | 1, mid + 1, r, L, R)); }

	return res;
}


bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n >> q;
	rep (i, 1, n) { std::cin >> a[i]; }

	build (1, 1, n);

	while (q--) {
		int op; std::cin >> op;
		int l, r; std::cin >> l >> r;
		l ++; r ++;

		if (op == 1) {
			int c; std::cin >> c;
			range_add (1, 1, n, l, r, c);
		} else if (op == 2) {
			int c; std::cin >> c;
			range_div (1, 1, n, l, r, c);
		} else if (op == 3) {
			std::cout << query_mn (1, 1, n, l, r) << "\n";
		} else if (op == 4) {
			std::cout << query_sum (1, 1, n, l, r) << "\n";
		}
	}

	return 0;
}
