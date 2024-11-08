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

int n, m;
int a[maxn];

struct Node {
	i64 sum, sumTag;
	int mx, mn, colTag;
	bool cov;

} tr[maxn << 3];

inline void applyCol (int now, int l, int r, int c) {
	tr[now].colTag = c; tr[now].cov = true;
	tr[now].mx = tr[now].mn = c;
}

inline void applySum (int now, int l, int r, i64 val) {
	tr[now].sumTag += val;
	tr[now].sum += val * (r - l + 1);
}

inline void pushDown (int now, int l, int r) {
	int mid = (l + r) >> 1;
	if (tr[now].cov) {
		applyCol (now << 1, l, mid, tr[now].colTag);
		applyCol (now << 1 | 1, mid + 1, r, tr[now].colTag);
		tr[now].cov = false; tr[now].colTag = 0;
	}
	if (tr[now].sumTag) {
		applySum (now << 1, l, mid, tr[now].sumTag);
		applySum (now << 1 | 1, mid + 1, r, tr[now].sumTag);
		tr[now].sumTag = 0;
	}
}

inline void pushUp (int now) {
	tr[now].mx = std::max (tr[now << 1].mx, tr[now << 1 | 1].mx);
	tr[now].mn = std::min (tr[now << 1].mn, tr[now << 1 | 1].mn);
	tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
}

void build (int now, int l, int r) {
	if (l == r) {
		tr[now].mx = tr[now].mn = l;
		return;
	}

	int mid = (l + r) >> 1;
	build (now << 1, l, mid);
	build (now << 1 | 1, mid + 1, r);
	pushUp (now);
}

void modify (int now, int l, int r, int L, int R, i64 c) {
	if (L <= l and r <= R) {
		if (tr[now].mx == tr[now].mn) {
			applySum (now, l, r, abs (tr[now].mx - c));
			applyCol (now, l, r, c);
			return;
		}
	}

	pushDown (now, l, r);

	int mid = (l + r) >> 1;
	if (L <= mid) { modify (now << 1, l, mid, L, R, c); }
	if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, c); }
	pushUp (now);
}

i64 query (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) { return tr[now].sum; }

	pushDown (now, l, r);

	i64 res = 0;
	int mid = (l + r) >> 1;
	if (L <= mid) { res += query (now << 1, l, mid, L, R); }
	if (R > mid) { res += query (now << 1 | 1, mid + 1, r, L, R); }
	return res;
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n >> m;

	build (1, 1, n);

	rep (i, 1, m) {
		int op; std::cin >> op;
		if (op == 1) {
			int l, r, c; std::cin >> l >> r >> c;
			modify (1, 1, n, l, r, c);
		} else {
			int l, r; std::cin >> l >> r;
			std::cout << query (1, 1, n, l, r) << "\n";
		}
	}

	return 0;
}
