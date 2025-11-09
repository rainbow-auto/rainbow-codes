#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using u64 = unsigned long long;
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

constexpr u64 msk = ((1ull << 63) - 1);

struct Tree {
	using info = std::pair<int, int>;

	struct Node {
		info mx;
		int tg;
		u64 all0, all1, c, cov;

		Node () {
			mx = {0, 1};
			tg = 0;
			all0 = all1 = c = cov = 0;
		}
	} tr[maxn << 2];

	info mrg(info a, info b) {
		info res;
		res.first = std::max(a.first, b.first);
		if (a.first == b.first) {
			res.second = a.second + b.second;
		} else if (a.first > b.first) {
			res.second = a.second;
		} else {
			res.second = b.second;
		}
		return res;
	}

	inline void pushUp(int now) {
		tr[now].all0 = (tr[now << 1].all0 | tr[now << 1 | 1].all0);
		tr[now].all1 = (tr[now << 1].all1 & tr[now << 1 | 1].all1);
		tr[now].mx = mrg(tr[now << 1].mx, tr[now << 1 | 1].mx);
	}

	inline void apply_sum(int now, int l, int r, int v) {
		tr[now].mx.first += v;
		tr[now].tg += v;
	}

	inline void apply_col(int now, int x, u64 v) {
		tr[now].cov |= (1ull << x);
		if (v == 0) {
			tr[now].all0 &= msk ^ (1ull << x);
			tr[now].all1 &= msk ^ (1ull << x);
			tr[now].c &= msk ^ (1ull << x);
		} else {
			tr[now].all0 |= (1ull << x);
			tr[now].all1 |= (1ull << x);
			tr[now].c |= (1ull << x);
		}
	}

	inline void pushDown(int now, int l, int r) {
		if (tr[now].tg) {
			int mid = (l + r) >> 1;
			apply_sum(now << 1, l, mid, tr[now].tg);
			apply_sum(now << 1 | 1, mid + 1, r, tr[now].tg);
			tr[now].tg = 0;
		}
		rep (b, 0, 63) {
			if (tr[now].cov & (1ull << b)) {
				apply_col(now << 1, b, bool(tr[now].c & (1ull << b)));
				apply_col(now << 1 | 1, b, bool(tr[now].c & (1ull << b)));
				tr[now].cov ^= (1ull << b);
				tr[now].c &= (msk ^ (1ull << b));
			}
		}
	}

	void add(int now, int l, int r, int L, int R, int x) {
		if (L <= l and r <= R) {
			if (tr[now].all1 & (1ull << x)) return;
			if (not(tr[now].all0 & (1ull << x))) {
				// db << "add " << l << " " << r << " " << 1 << "\n";
				return apply_sum(now, l, r, 1), apply_col(now, x, 1), void(0);
			}
		}
		
		pushDown(now, l, r);
		int mid = (l + r) >> 1;
		if (L <= mid) add(now << 1, l, mid, L, R, x);
		if (R > mid) add(now << 1 | 1, mid + 1, r, L, R, x);
		pushUp(now);
	}
	
	void del(int now, int l, int r, int L, int R, int x) {
		// db << now << " | " << l << ", " << r << " | all0:" << std::bitset<4>(tr[now].all0) << " | all1:" << std::bitset<4>(tr[now].all1) << "\n";
		if (L <= l and r <= R) {
			if ((tr[now].all1 & (1ull << x))) {
				// db << "sub " << l << " " << r << " " << "\n";
				return apply_sum(now, l, r, -1), apply_col(now, x, 0), void(0);
			}
			if (not(tr[now].all0 & (1ull << x))) return;
		}
		pushDown(now, l, r);
		int mid = (l + r) >> 1;
		if (L <= mid) del(now << 1, l, mid, L, R, x);
		if (R > mid) del(now << 1 | 1, mid + 1, r, L, R, x);
		pushUp(now);
	}

	info qry(int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) return tr[now].mx;
		pushDown(now, l, r);
		int mid = (l + r) >> 1;
		if (R <= mid) return qry(now << 1, l, mid, L, R);
		if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R);
		return mrg(qry(now << 1, l, mid, L, R), qry(now << 1 | 1, mid + 1, r, L, R));
	}
	
	void build(int now, int l, int r) {
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(now << 1, l, mid);
		build(now << 1 | 1, mid + 1, r);
		pushUp(now);
	}
} tr;
 
void solve() {
	int n, q; std::cin >> n >> q;

	tr.build(1, 1, n);

	while (q--) {
		int op; std::cin >> op;
		if (op == 1) {
			int l, r; std::cin >> l >> r;
			int x; std::cin >> x;
			tr.add(1, 1, n, l, r, x);
			// db << "finish\n";
		} else if (op == 2) {
			int l, r; std::cin >> l >> r;
			int x; std::cin >> x;
			tr.del(1, 1, n, l, r, x);
		} else if (op == 3) {
			int l, r; std::cin >> l >> r;
			auto [mx, cnt] = tr.qry(1, 1, n, l, r);
			std::cout << mx << " " << cnt << "\n";
			// db << mx << " " << cnt << "\n";
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
