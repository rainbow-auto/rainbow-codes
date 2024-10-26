#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
#define MultiTask lovely_fairytale

const int maxn = 100005;

int n, m, L;
i64 V;
i64 p[maxn];

struct Node {
	int st;
	i64 v, a;
} a[maxn];

struct SegTree {
	struct Node {
		std::set<int> s;
		std::pair<int, int> mx;
		int tag;
	} tr[maxn << 2];

	inline void pushUp(int now) {
		tr[now].mx = std::max(tr[now << 1].mx, tr[now << 1 | 1].mx);
	}

	inline void apply(int now, int val) {
		tr[now].mx.first += val;
		tr[now].tag += val;
	}

	inline void pushDown(int now) {
		if (not tr[now].tag) return;
		apply(now << 1, tr[now].tag);
		apply(now << 1 | 1, tr[now].tag);
		tr[now].tag = 0;
	}

	void init(int now, int l, int r) {
		tr[now].mx.first = tr[now].mx.second = tr[now].tag = 0;
		std::set<int>().swap(tr[now].s);
		if (l == r) return tr[now].mx.second = l, void(0);
		int mid = (l + r) >> 1;
		init(now << 1, l, mid);
		init(now << 1 | 1, mid + 1, r);
		pushUp(now);
	}

	void mdf(int now, int l, int r, int L, int R, int col) {
		if (L <= l and r <= R) return tr[now].s.insert(col), apply(now, 1), void(0);
		pushDown(now);
		int mid = (l + r) >> 1;
		if (L <= mid) mdf(now << 1, l, mid, L, R, col);
		if (R > mid) mdf(now << 1 | 1, mid + 1, r, L, R, col);
		pushUp(now);
	}

	std::vector<int> cols;
	void cal(int now, int l, int r, int pos) {
		for (auto x : tr[now].s) cols.push_back(x);
		if (l == r) return;
		pushDown(now);
		int mid = (l + r) >> 1;
		if (pos <= mid) cal(now << 1, l, mid, pos);
		else cal(now << 1 | 1, mid + 1, r, pos);
		pushUp(now);
	}

	void rmv(int now, int l, int r, int L, int R, int id) {
		if (L <= l and r <= R) return tr[now].s.erase(id), apply(now, -1), void(0);
		pushDown(now);
		int mid = (l + r) >> 1;
		if (L <= mid) rmv(now << 1, l, mid, L, R, id);
		if (R > mid) rmv(now << 1 | 1, mid + 1, r, L, R, id);
		pushUp(now);
	}

	inline std::pair<int, int> qry() {
		return tr[1].mx;
	}
} tr;

inline i64 calc(int id, i64 S) {
	if (S < 0) return -1e18;
	i64 x = 1ll * a[id].v * a[id].v + 2ll * a[id].a * S; 
	if (x < 0) return -1e18;
	return x;
}

inline int getR(int id, int st) {
	int l = st, r = m;
	int res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (calc(id, p[mid] - a[id].st) > V) {
			l = mid + 1;
			res = mid;
		} else {
			r = mid - 1;
		}
	}
	return res;
}

inline int getL(int id, int ed) {
	int l = 1, r = ed;
	int res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (calc(id, p[mid] - a[id].st) > V) {
			r = mid - 1;
			res = mid;
		} else {
			l = mid + 1;
		}
	}
	return res;
}

void solve() {

	std::cin >> n >> m >> L >> V;
	V *= V;
	rep (i, 1, n) std::cin >> a[i].st >> a[i].v >> a[i].a;
	rep (i, 1, m) std::cin >> p[i];

	std::vector<std::pair<int, int>> rgs;

	// db << "---look---\n";
	// db << calc(2, p[1] - a[2].st) << " " << V << "\n";
	// db << "----------\n";

	rep (i, 1, n) {
		if (a[i].a >= 0) {
			int ed = m;
			if (not (calc(i, p[ed] - a[i].st) > V)) continue;
			int st = getL(i, ed);
			if (not ~st) continue;
			rgs.push_back(std::make_pair(st, ed));
			// db << "i: " << i << " | " << st << " " << ed << "\n";
		} else {
			int st = std::lower_bound(p + 1, p + m + 1, a[i].st) - p;
			if (not (calc(i, p[st] - a[i].st) > V)) continue;
			int ed = getR(i, st);
			if (not ~ed) continue;
			rgs.push_back(std::make_pair(st, ed));
			// db << "i: " << i << " | " << st << " " << ed << "\n";
		}
	}

	tr.init(1, 1, m);
	rep (i, 0, (int) rgs.size() - 1) {
		int l, r; std::tie(l, r) = rgs[i];
		tr.mdf(1, 1, m, l, r, i);
	}

	int ans = 0;
	while (true) {
		int mx, id; std::tie(mx, id) = tr.qry();
		if (mx <= 0) break;
		std::vector<int>().swap(tr.cols);
		tr.cal(1, 1, m, id);
		// db << "mx: " << mx << " id: " << id << "\n";
		for (auto x : tr.cols) tr.rmv(1, 1, m, rgs[x].first, rgs[x].second, x);
		ans++;
	}

	std::cout << rgs.size() << " " << m - ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();
	
	// std::freopen("detect5.in", "r", stdin);
	// std::freopen("detect.out", "w", stdout);

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
