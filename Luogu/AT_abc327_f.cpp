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

const int maxn = 200005;

struct Tree {
	struct Node {
		int ls, rs;
		int mx;
		int tag;
	} tr[maxn << 3];

	int tot, rt;

	void pushUp(int now) {
		tr[now].mx = std::max(tr[tr[now].ls].mx, tr[tr[now].rs].mx);
	}

	void apply(int& now, int val) {
		if (not now) now = ++tot;
		tr[now].tag += val;
		tr[now].mx += val;
	}

	void pushDown(int now) {
		if (not tr[now].tag) return;
		apply(tr[now].ls, tr[now].tag);
		apply(tr[now].rs, tr[now].tag);
		tr[now].tag = 0;
	}

	void modify(int& now, int l, int r, int L, int R, int val) {
		if (not now) now = ++tot;
		if (L <= l and r <= R) { apply(now, val); return; }
		pushDown(now);
		int mid = (l + r) >> 1;
		if (L <= mid) modify(tr[now].ls, l, mid, L, R, val);
		if (R > mid) modify(tr[now].rs, mid + 1, r, L, R, val);
		pushUp(now);
	}

	int querymx() {
		return tr[rt].mx;
	}
} tr;

struct Point {
	int x, y;
	friend bool operator < (Point a, Point b) {
		return a.x < b.x;
	}
} a[maxn];

int n;
int D, W;

void solve() {
	std::cin >> n >> D >> W;
	rep (i, 1, n) {
		int x, y; std::cin >> x >> y;
		a[i] = Point { x, y };
	}

	std::sort(a + 1, a + n + 1);

	auto add = [&](int x) -> void {
		tr.modify(tr.rt, 0, 1e6, a[x].y, a[x].y + W - 1, 1);
	};

	auto del = [&](int x) -> void {
		tr.modify(tr.rt, 0, 1e6, a[x].y, a[x].y + W - 1, -1);
	};

	int l = 1, r = 0;
	int ans = 0;

	while (l <= n) {
		while (r + 1 <= n and a[r + 1].x <= a[l].x + D - 1) add (++r);
		ans = std::max(ans, tr.querymx());
		del(l++);
	}

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
