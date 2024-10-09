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

const int maxn = 50005;

struct Tree {
	struct Node {
		int ls, rs;
		i64 sum;
	} tr[maxn << 8];

	int rt, tot;

	inline void pushUp(int now) { tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum; }

	void mdfy(int &now, int l, int r, int pos, int val) {
		if (not now) now = ++tot;
		if (l == r) return tr[now].sum += val, void(0);
		int mid = (l + r) >> 1;
		if (pos <= mid) mdfy(tr[now].ls, l, mid, pos, val);
		else mdfy(tr[now].rs, mid + 1, r, pos, val);
		pushUp(now);
	}

	i64 qry(int now, int l, int r, int L, int R) {
		if (not now) return 0;
		if (L <= l and r <= R) return tr[now].sum;

		i64 res = 0;
		int mid = (l + r) >> 1;
		if (L <= mid) res += qry(tr[now].ls, l, mid, L, R);
		if (R > mid) res += qry(tr[now].rs, mid + 1, r, L, R);
		return res;
 	}

	void clr() {
		rep (i, 1, tot) tr[i] = Node { 0, 0, 0 };
		tot = rt = 0;
	}
} tr;

bool rainbow() {
	int n; std::cin >> n;

	if (not n) return false;

	i64 ans = 0;
	rep (i, 1, n) {
		int a; std::cin >> a;
		tr.mdfy(tr.rt, 0, 1e9, a, 1);
		ans += tr.qry(tr.rt, 0, 1e9, a + 1, 1e9);
	}

	std::cout << ans << "\n";

	tr.clr();

	return true;
}

void solve() {
	while (rainbow());
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
