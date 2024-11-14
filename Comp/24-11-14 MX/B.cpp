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
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 500005;


int n, q;
int a[maxn];

std::set<int> pos[maxn];
std::multiset<int> lens[maxn];

int mxlen[maxn];

std::set<int> b[maxn];
struct SegTree {
	struct Node {
		int mn;
		Node () { std::memset(&mn, 0x3f, sizeof mn); }
	} tr[maxn << 2];

	inline void pushUp(int now) { tr[now].mn = std::min(tr[now << 1].mn, tr[now << 1 | 1].mn); }

	void chg(int now, int l, int r, int pos, int val) {
		if (l == r) return tr[now].mn = val, void(0);
		int mid = (l + r) >> 1;
		if (pos <= mid) chg(now << 1, l, mid, pos, val);
		else chg(now << 1 | 1, mid + 1, r, pos, val);
		pushUp(now);
	}

	int qry(int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) return tr[now].mn;
		int mid = (l + r) >> 1;
		int mn; std::memset(&mn, 0x3f, sizeof mn);
		if (L <= mid) mn = std::min(mn, qry(now << 1, l, mid, L, R));
		if (R > mid) mn = std::min(mn, qry(now << 1 | 1, mid + 1, r, L, R));
		return mn;
	}
} tr;

inline void move(int x, int from, int to) {
	pos[x].erase(from);
	auto it = pos[x].upper_bound(from);
	int old = *lens[x].rbegin(); 
	lens[x].erase(lens[x].find(*it - from - 1));
	lens[x].erase(lens[x].find(from - *std::prev(it) - 1));

	it = pos[x].upper_bound(to);
	lens[x].insert(*it - to - 1);
	lens[x].insert(to - *std::prev(it) - 1);
	int now = *lens[x].rbegin();
	pos[x].insert(to);

	// update
	b[old].erase(x); tr.chg(1, 0, n, old, *b[old].begin());
	b[now].insert(x); tr.chg(1, 0, n, now, *b[now].begin());
}

void solve() {
	std::freopen("star.in", "r", stdin);
	std::freopen("star.out", "w", stdout);

	std::cin >> n >> q;
	rep (i, 1, n) std::cin >> a[i];
	
	rep (i, 1, n) pos[a[i]].insert(i);

	rep (x, 0, n) {
		pos[x].insert(n + 1);
		int lst = 0;
		for (auto p : pos[x]) lens[x].insert(p - lst - 1), lst = p;
		pos[x].insert(0);
		b[*lens[x].rbegin()].insert(x);
	}

	rep (i, 0, n) b[i].insert(0x3f3f3f3f);
	rep (i, 0, n) tr.chg(1, 0, n, i, *b[i].begin());

	while (q--) {
		int op; std::cin >> op;
		if (op == 1) {
			int i; std::cin >> i;
			if (a[i] == a[i + 1]) continue;
			move(a[i], i, i + 1);
			move(a[i + 1], i + 1, i);
			std::swap(a[i], a[i + 1]);
		} else {
			int x; std::cin >> x;

			// (mxlen, v) | mxlen >= x && min v
			// rep (v, 0, n) {
			// 	if (*lens[v].rbegin() >= x) {
			// 		std::cout << v << "\n";
			// 		break;
			// 	}
			// }

			std::cout << tr.qry(1, 0, n, x, n) << "\n";
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
