#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100005;
constexpr int mod = 571373;

using tag = std::pair<i64, i64>;
constexpr tag z = { 1, 0 };

int n, q, m;

int a[maxn];

struct Node {
	i64 sum;
	tag t;
} tr[maxn << 2];

inline void compose(tag &cur, tag t) {
	(cur.first *= t.first) %= mod;
	(((cur.second *= t.first) %= mod) += t.second) %= mod;
}

inline void apply(int now, int l, int r, tag t) {
	(tr[now].sum *= t.first) %= mod;
	(tr[now].sum += 1ll * t.second * (r - l + 1) % mod) %= mod;
	compose(tr[now].t, t);
}

inline void pushdown(int now, int l, int r) {
	int mid = (l + r) >> 1;
	apply(now << 1, l, mid, tr[now].t);
	apply(now << 1 | 1, mid + 1, r, tr[now].t);
	tr[now].t = z;
}

inline void pushup(int now) {
	tr[now].sum = (tr[now << 1].sum + tr[now << 1 | 1].sum) % mod;
}

void build(int now, int l, int r) {
	if (l == r) {
		tr[now] = Node { a[l], z };
		return;
	}
	int mid = (l + r) >> 1;
	build(now << 1, l, mid);
	build(now << 1 | 1, mid + 1, r);
	pushup(now);
	tr[now].t = z;
}

/*
不是

我咋

写了一个小时？？？？？

*/

void mdf(int now, int l, int r, int L, int R, tag t) {
	if (L <= l and r <= R) return apply(now, l, r, t), void(0);

	pushdown(now, l, r);

	int mid = (l + r) >> 1;
	if (L <= mid) mdf(now << 1, l, mid, L, R, t);
	if (R > mid) mdf(now << 1 | 1, mid + 1, r, L, R, t);
	
	pushup(now);
}

int qry(int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) return tr[now].sum;

	pushdown(now, l, r);

	int mid = (l + r) >> 1;
	if (R <= mid) return qry(now << 1, l, mid, L, R);
	if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R);

	return (qry(now << 1, l, mid, L, R) + qry(now << 1 | 1, mid + 1, r, L, R)) % mod;
}

inline void display() {
	rep (i, 1, n) db << qry(1, 1, n, i, i) << " "; dbendl;
}

void solve() {
	std::cin >> n >> q >> m;

	rep (i, 1, n) std::cin >> a[i];

	build(1, 1, n);

	while (q--) {
		int op; std::cin >> op;
		int l, r; std::cin >> l >> r;
		if (op == 1) {
			int k; std::cin >> k;	
			mdf(1, 1, n, l, r, tag{k, 0});
		} else if (op == 2) {
			int k; std::cin >> k;
			mdf(1, 1, n, l, r, tag{1, k});
		} else if (op == 3) {
			std::cout << qry(1, 1, n, l, r) << "\n";
		}
	}
}

bool MemED;
int main() {
	fastread
	// lookMem	

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (_--) {
		solve();
	}

	return 0;
}
