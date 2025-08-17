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

constexpr int maxn = 1000005;

int n, k;
int d[maxn];

int L[maxn], R[maxn];

int c[maxn];
int f[maxn];

struct Tree {
	struct Node {
		i64 mn, tag;
	} tr[maxn << 2];

	inline void pushUp(int now) {
		tr[now].mn = std::min(tr[now << 1].mn, tr[now << 1 | 1].mn);
	}

	inline void apply(int now, int v) {
		tr[now].mn += v;
		tr[now].tag += v;
	}

	inline void pushDown(int now) {
		if (not tr[now].tag) return;
		apply(now << 1, tr[now].tag);
		apply(now << 1 | 1, tr[now].tag);
		tr[now].tag = 0;
	}

	void build(int now, int l, int r) {
		tr[now].tag = 0;
		if (l == r) return tr[now] = { f[l], 0 }, void(0);
		int mid = (l + r) >> 1;
		build(now << 1, l, mid);
		build(now << 1 | 1, mid + 1, r);
		pushUp(now);
	}

	void mdf(int now, int l, int r, int L, int R, int x) {
		if (L <= l and r <= R) return apply(now, x), void(0);
		pushDown(now);
		int mid = (l + r) >> 1;
		if (L <= mid) mdf(now << 1, l, mid, L, R, x);
		if (R > mid) mdf(now << 1 | 1, mid + 1, r, L, R, x);
		pushUp(now);
	}

	int qry(int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) return tr[now].mn;
		pushDown(now);
		int mid = (l + r) >> 1;
		if (R <= mid) return qry(now << 1, l, mid, L, R);
		if (L > mid) return qry(now << 1 | 1, mid + 1, r, L, R);
		return std::min(qry(now << 1, l, mid, L, R), qry(now << 1 | 1, mid + 1, r, L, R));
	}
} tr;

struct Task {
	int L;
	int w;
};
std::vector<Task> tsk[maxn];

void solve() {
	std::cin >> n >> k;
	rep (i, 2, n) std::cin >> d[i];
	rep (i, 1, n) std::cin >> c[i];

	// db << "d: "; rep (i, 1, n) db << d[i] << " "; dbendl;
	
	rep (i, 1, n) {
		int x; std::cin >> x;
		R[i] = std::upper_bound(d + 1, d + n + 1, d[i] + x) - d;
		L[i] = std::lower_bound(d + 1, d + n + 1, d[i] - x) - d - 1;

		// dbg(i);
		// dbg(x);
		// dbg(L[i]);
		// dbg(R[i]);
		// dbendl;
	}

	// db << "------------\n";

	rep (i, 1, n) {
		int w; std::cin >> w;
		tsk[R[i]].push_back({L[i], w});
	}
	
	std::memset(f, 0x3f, sizeof f);
	f[0] = 0;
	tr.build(1, 0, n + 1);
	
	// f_1: 2 3 12 60
	// f_2: 2 

	auto display = [&]() -> void {
		rep (i, 0, n + 1) db << tr.qry(1, 0, n + 1, i, i) << " "; dbendl;
	};

	rep (j, 1, k + 1) {
		// dbg(j);
		rep (i, 0, n + 1) {
			// dbg(i);
			// db << "tsk:\n";
			// for (auto [l, w] : tsk[i]) db << l << " " << w << "\n";
			// dbendl;
			
			for (auto [l, w] : tsk[i]) {
				// db << "mdf " << 0 << " " << l << " " << w << "\n";
				tr.mdf(1, 0, n + 1, 0, l, w);
			}
			
			if (i > 0) {
				// display();
				f[i] = tr.qry(1, 0, n + 1, 0, i - 1) + c[i];
				// dbg(f[i]);
			}
		}

		// db << "f: "; rep (i, 1, n + 1) db << f[i] << " "; dbendl;

		tr.build(1, 0, n + 1);
		rep (i, 1, n + 1) f[i] = 0x3f3f3f3f;

		// db << "--------------\n";
	}

	std::cout << tr.qry(1, 0, n + 1, n + 1, n + 1) << "\n";
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
