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

constexpr int maxn = 500005;

int n, q;
int a[maxn];

struct Node {
	std::pair<int, int> pre;
	std::pair<int, int> suf;
	bool same;
	int mx;

	friend Node operator + (Node a, Node b) {
		Node c;
		if (a.same and b.same and a.suf.first == b.pre.first) c.same = true;
		else c.same = false;

		c.mx = std::max(a.mx, b.mx);
		if (a.suf.first == b.pre.first) c.mx = std::max(c.mx, a.suf.second + b.pre.second);
		c.pre = a.pre;
		c.suf = b.suf;
		if (a.same and a.suf.first == b.pre.first) c.pre.second = a.suf.second + b.pre.second;
		if (b.same and a.suf.first == b.pre.first) c.suf.second = a.suf.second + b.pre.second;
		return c;
	}

} tr[maxn << 2];

void build(int now, int l, int r) {
	if (l == r) return tr[now] = Node { { a[l], 1 }, { a[l], 1 }, true, 1 }, void(0);
	int mid = (l + r) >> 1;
	build(now << 1, l, mid);
	build(now << 1 | 1, mid + 1, r);
	tr[now] = tr[now << 1] + tr[now << 1 | 1];
}

Node qry(int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) return tr[now];
	int mid = (l + r) >> 1;	
	if (R <= mid) return qry(now << 1, l, mid, L, R);
	if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R);
	return qry(now << 1, l, mid, L, R) + qry(now << 1 | 1, mid + 1, r, L, R);
}

void mdf(int now, int l, int r, int pos, int v) {
	if (l == r) return tr[now] = Node { { v, 1 }, { v, 1 }, true, 1 }, void(0);
	int mid = (l + r) >> 1;
	if (pos <= mid) mdf(now << 1, l, mid, pos, v);
	if (pos > mid) mdf(now << 1 | 1, mid + 1, r, pos, v);
	tr[now] = tr[now << 1] + tr[now << 1 | 1];
}

void solve() {
	std::cin >> n >> q;
	rep (i, 1, n) {
		char c; std::cin >> c;
		a[i] = c;
	}

	build(1, 1, n);

	while (q--) {
		int op; std::cin >> op;
		if (op == 1) {
			int x; std::cin >> x;
			char c; std::cin >> c;
			mdf(1, 1, n, x, c);
		} else {
			int l, r; std::cin >> l >> r;
			std::cout << qry(1, 1, n, l, r).mx << "\n";
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
