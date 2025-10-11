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

constexpr int maxn = 200005;

int n, q;
int a[maxn];

struct Tree {
	struct Node {
		int mn;
	} tr[maxn << 2];

	inline void pushUp(int now) {
		tr[now].mn = std::min(tr[now << 1].mn, tr[now << 1 | 1].mn);
	} 

	void mdf(int now, int l, int r, int pos, int v) {
		if (l == r) return tr[now].mn = v, void(0);
		int mid = (l + r) >> 1;
		if (pos <= mid) mdf(now << 1, l, mid, pos, v);
		if (pos > mid) mdf(now << 1 | 1, mid + 1, r, pos, v);
		pushUp(now);
	}

	int qry(int now, int l, int r, int L) {
		if (l == r) return l;
		int mid = (l + r) >> 1;
		if (tr[now << 1].mn < L) return qry(now << 1, l, mid, L);
		else return qry(now << 1 | 1, mid + 1, r, L);
	}
} tr;

int lst[maxn];

struct Query {
	int l;
	int id;
};

std::vector<Query> qs[maxn];
int ans[maxn];

void solve() {
	std::cin >> n >> q;

	int m = 0;
	rep (i, 1, n) {
		std::cin >> a[i];
		m = std::max(m, a[i]);
	}
	m++;

	rep (t, 1, q) {
		int l, r; std::cin >> l >> r;
		qs[r].push_back(Query{l, t});
	}

	rep (r, 1, n) {
		lst[a[r]] = r;
		tr.mdf(1, 0, m, a[r], lst[a[r]]);
		
		for (auto [l, id] : qs[r]) {
			ans[id] = tr.qry(1, 0, m, l);
		}
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
