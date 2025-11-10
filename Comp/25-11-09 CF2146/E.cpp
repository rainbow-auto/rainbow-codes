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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 300005;

int n;
int a[maxn];

struct Tree {
	struct Node {
		int mx;
		int tg;
	} tr[maxn << 2];

	inline void pushUp(int now) {
		tr[now].mx = std::max(tr[now << 1].mx, tr[now << 1 | 1].mx);
	}

	inline void apply(int now, int v) {
		tr[now].mx += v;
		tr[now].tg += v;
	}

	inline void pushDown(int now) {
		if (not tr[now].tg) return;
		apply(now << 1, tr[now].tg);
		apply(now << 1 | 1, tr[now].tg);
		tr[now].tg = 0;
	}

	void build(int now, int l, int r) {
		tr[now] = {0, 0};
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(now << 1, l, mid);
		build(now << 1 | 1, mid + 1, r);
	}

	void mdf(int now, int l, int r, int L, int R, int v) {
		if (L <= l and r <= R) return apply(now, v), void(0);
		pushDown(now);
		int mid = (l + r) >> 1;
		if (L <= mid) mdf(now << 1, l, mid, L, R, v);
		if (R > mid) mdf(now << 1 | 1, mid + 1, r, L, R, v);
		pushUp(now);
	}

	void mdf(int now, int l, int r, int pos, int v) {
		if (l == r) return tr[now] = {v, 0}, void(0);
		pushDown(now);
		int mid = (l + r) >> 1;
		if (pos <= mid) mdf(now << 1, l, mid, pos, v);
		else mdf(now << 1 | 1, mid + 1, r, pos, v);
		pushUp(now);
	}

	inline int mx() {
		return tr[1].mx;
	}
} tr;

void solve() {
	std::cin >> n;

	tr.build(1, 0, n);

	rep (i, 1, n) {
		std::cin >> a[i];
		tr.mdf(1, 0, n, a[i], 0);
		if (a[i] > 0) tr.mdf(1, 0, n, 0, a[i] - 1, 1);
		std::cout << tr.mx() << " ";
 	}
	std::cout << "\n";
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
