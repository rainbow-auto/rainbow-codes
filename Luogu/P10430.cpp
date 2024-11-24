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

const int maxn = 300005;

int n, q;
i64 c[maxn];
i64 d;

struct Tree {
	struct Node {
		i64 tag;
		i64 sum;
	} tr[maxn << 2];

	inline void pushUp(int now) {
		tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
	}

	inline void apply(int now, int l, int r, i64 v) {
		tr[now].sum += 1ll * (r - l + 1) * v;
		tr[now].tag += v;
	}

	inline void pushDown(int now, int l, int r) {
		if (not tr[now].tag) return;
		int mid = (l + r) >> 1;
		apply(now << 1, l, mid, tr[now].tag);
		apply(now << 1 | 1, mid + 1, r, tr[now].tag);
		tr[now].tag = 0;
	}

	void build(int now, int l, int r) {
		if (l == r) return tr[now] = { 0, 0 }, void(0);
		int mid = (l + r) >> 1;
		build(now << 1, l, mid);
		build(now << 1 | 1, mid + 1, r);
		pushUp(now);
	}

	inline void mdf(int now, int l, int r, int L, int R, i64 val) {
		if (L <= l and r <= R) return apply(now, l, r, val);
		pushDown(now, l, r);
		int mid = (l + r) >> 1;
		if (L <= mid) mdf(now << 1, l, mid, L, R, val);
		if (R > mid) mdf(now << 1 | 1, mid + 1, r, L, R, val);
		pushUp(now);
	}

	inline i64 qry(int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) return tr[now].sum;
		pushDown(now, l, r);
		int mid = (l + r) >> 1;
		i64 res = 0;
		if (L <= mid) res += qry(now << 1, l, mid, L, R);
		if (R > mid) res += qry(now << 1 | 1, mid + 1, r, L, R);
		return res;
	}
} tr;

std::vector<std::pair<int, int>> qs[maxn];
i64 ans[maxn];

void solve() {
	std::cin >> n >> d;
	rep (i, 1, n) std::cin >> c[i];	
	
	std::cin >> q;
	rep (i, 1, q) {
		int l, r; std::cin >> l >> r;
		qs[r].push_back(std::make_pair(l, (int) i));
	}

	tr.build(1, 1, n);
	auto calc = [&](int pos) -> i64 {
		return c[pos] - d * tr.qry(1, 1, n, pos, pos);
	};

	auto div = [&](i64 x, i64 y) -> i64 {
		return x / y + !!(x % y);
	};

	std::stack<int> stk;
	rep (r, 1, n) {
		int pos = r;
		while (not stk.empty() and calc(pos) < calc(pos - 1)) {
			int now = stk.top(); stk.pop();
			i64 x = calc(pos), y = calc(pos - 1);
			tr.mdf(1, 1, n, now, pos - 1, div(y - x, d));
			pos = now;
		}
		stk.push(pos);
		for (auto [l, id] : qs[r]) ans[id] = calc(l) < 0 ? -1 : tr.qry(1, 1, n, l, r);
	}

	rep (i, 1, q) std::cout << ans[i] << "\n";
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
