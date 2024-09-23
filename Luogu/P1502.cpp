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

	int rt, tot;

	void pushUp(int now) {
		tr[now].mx = std::max(tr[tr[now].ls].mx, tr[tr[now].rs].mx);
	}

	void apply(int& now, i64 val) {
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

	i64 querymx(int now, i64 l, i64 r, i64 L, i64 R) {
		if (not now) return 0;
		if (L <= l and r <= R) return tr[now].mx;

		pushDown(now);

		i64 mid = (l + r) >> 1;
		i64 res = 0;
		if (L <= mid) res = std::max (res, querymx(tr[now].ls, l, mid, L, R));
		if (R > mid) res = std::max (res, querymx(tr[now].rs, mid + 1, r, L, R));
		return res;
	}

	i64 querymx() {
		return tr[rt].mx;
	}

	void clear() {
		rep (i, 1, tot) tr[i] = Node { 0, 0, 0ll, 0ll };
		rt = tot = 0;
	}
} tr;

int W, H;

struct Node {
	int x, y;
	i64 w;

	friend bool operator < (Node a, Node b) { 
		return a.y < b.y; 
	}
} a[maxn];

void solve() {
	int n; std::cin >> n;

	std::cin >> W >> H;

	if (W < 0) {
		std::cout << "0\n";
		return;
	}

	if (H < 0) {
		std::cout << "0\n";
		return;
	}

	rep (i, 1, n) {
		int x, y; std::cin >> x >> y;
		i64 w; std::cin >> w;
		a[i] = Node { x, y, w };
	}

	std::sort(a + 1, a + n + 1);

	// rep (i, 1, n) db << a[i].w << " ";
	// dbendl;

	auto output = [&]() -> void {
		rep (i, 1, 8) db << tr.querymx(tr.rt, 1, 1ll << 31, i, i) << " ";
		dbendl;
	};

	auto add = [&](int pos) -> void {
		// db << "add " << pos << "\n"; 
		// db << "modify " << a[pos].x << " " << a[pos].x + W << " w: " << a[pos].w << "\n";
		
		// db << "before: ";
		// output();
		
		tr.modify(tr.rt, 1, 1ll << 32, a[pos].x, a[pos].x + W - 1, a[pos].w);
		
		// db << "after: ";
		// output();
	};

	auto del = [&](int pos) -> void {
		tr.modify(tr.rt, 1, 1ll << 32, a[pos].x, a[pos].x + W - 1, -a[pos].w);
		// db << "modify " << a[pos].x << " " << a[pos].x + W << " w: " << -a[pos].w << "\n";
		// db << "before: ";
		// output();
	};


	i64 ans = 0;
	int l = 1, r = 0;
	while (l <= n) {
		// db << "l = " << l << "\n";
		while (r + 1 <= n and a[r + 1].y < a[l].y + H) {
			add(++r);	
		}
		// db << "currans: " << tr.querymx(tr.rt, 1, 1ll << 31, 1, 1ll << 31) << "\n";
		ans = std::max(ans, tr.querymx());
		del(l++);
		// db << "after: ";
		// output();
	}

	std::cout << ans << "\n";

	tr.clear();
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
