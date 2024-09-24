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

const int maxn = 10005;

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
		if (L <= l and r <= R) { apply(now, val); return; }

		pushDown(now);
		i64 mid = (l + r) >> 1;
		if (L <= mid) modify(tr[now].ls, l, mid, L, R, val);
		if (R > mid) modify(tr[now].rs, mid + 1, r, L, R, val);
		pushUp(now);
	}

	i64 query() {
		return tr[rt].mx;
	}

	void clear() {
		rep (i, 1, tot) tr[i] = Node { 0, 0, 0ll, 0ll };
		tot = rt = 0;
	}
} tr;

int n, c;
std::pair <int, int> a[maxn];

bool chk(int len) {
	tr.clear();

	auto add = [&](int x) -> void {
		tr.modify(tr.rt, 0, 1e8, a[x].second, a[x].second + len - 1, 1);
	};

	auto del = [&](int x) -> void {
		tr.modify(tr.rt, 0, 1e8, a[x].second, a[x].second + len - 1, -1);
	};

	i64 res = 0;
	int l = 1, r = 0;
	while (l <= n) {
		while (r + 1 <= n and a[r + 1].first - a[l].first + 1 <= len) {
			add(++r);
		}
		res = std::max(res, tr.query());
		del(l++);
	}
	return res >= c;
}

void solve() {
	std::cin >> c >> n;
	rep(i, 1, n) std::cin >> a[i].first >> a[i].second;

	std::sort(a + 1, a + n + 1);

	int l = 1, r = 1e9;
	int res = 0;

	while (l <= r) {
		int mid = (l + r) >> 1;
		if (chk(mid)) {
			r = mid - 1;
			res = mid;
		} else {
			l = mid + 1;
		}
	}

	std::cout << res << "\n";
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
