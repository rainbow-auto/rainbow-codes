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

const int maxn = 1000005;

struct Tree {
	struct Node {
		int ls, rs;
		i64 mx;
		i64 tag;
	} tr[maxn << 3];

	int tot, rt;

	void pushUp(int now) {
		tr[now].mx = std::max(tr[tr[now].ls].mx, tr[tr[now].rs].mx);
	}

	void apply(int& now, i64 val) {
		if (not now) now = ++tot;
		tr[now].mx += val;
		tr[now].tag += val;
	}

	void pushDown(int now) {
		if (not tr[now].tag) return;
		apply(tr[now].ls, tr[now].tag);
		apply(tr[now].rs, tr[now].tag);
		tr[now].tag = 0;
	}

	void modify(int& now, i64 l, i64 r, i64 L, i64 R, i64 val) {
		if (not now) now = ++tot;
		if (L <= l and r <= R) {
			apply(now, val);
			return;
		}

		pushDown(now);
		i64 mid = (l + r) >> 1;
		if (L <= mid) modify(tr[now].ls, l, mid, L, R, val);
		if (R > mid) modify(tr[now].rs, mid + 1, r, L, R, val);
		pushUp(now);
	}

	i64 querymx() {
		return tr[rt].mx;
	}

	i64 query(int now, i64 l,i64 r, i64 pos) {
		if (not now) return 0;
		if (l == r) return tr[now].mx;

		pushDown(now);
		i64 res = 0;
		int mid = (l + r) >> 1;
		if (pos <= mid) res = std::max(res, query(tr[now].ls, l, mid, pos));
		else res = std::max(res, query(tr[now].rs, mid + 1, r, pos));
		
		return res;
	}
} tr;

int n;

struct Point {
	int x, y;
	i64 w;
	friend bool operator < (Point a, Point b) {
		return a.y < b.y;
	}
} a[maxn];

int W;

void solve() {
	std::cin >> n >> W;
	W <<= 1;
	rep (i, 1, n) {
		i64 g; std::cin >> g;
		int x, y; std::cin >> x >> y;
		a[i] = Point { x - y, x + y, g };
	}

	std::sort(a + 1, a + n + 1);

	auto display = [&]() -> void {
		rep (i, 1, 14) db << tr.query(tr.rt, -1e9, 1e9, i) << " ";
		dbendl;
	};

	auto add = [&](int x) -> void {
		tr.modify(tr.rt, -1e9, 1e9, a[x].x, a[x].x + W, a[x].w);
	};

	auto del = [&](int x) -> void {
		tr.modify(tr.rt, -1e9, 1e9, a[x].x, a[x].x + W, -a[x].w);
	};

	i64 ans = 0;
	int l = 1, r = 0;
	while (l <= n) {
		while (r + 1 <= n and a[r + 1].y - a[l].y <= W) {
			add(++r);			
		}
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
