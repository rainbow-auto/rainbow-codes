#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 500005;
const int inf = 0x3f3f3f3f;

int n, m, w;
int a[maxn];

struct Tree {
	struct Node {
		int mn;
		Node () { mn = inf; }
	} tr[maxn << 3];

	inline void pushUp (int now) { 
		tr[now].mn = std::min (tr[now << 1].mn, tr[now << 1 | 1].mn);
	}

	void modify (int now, int l, int r, int pos, int val) {
		if (l == r) { tr[now].mn = val; return; }

		int mid = (l + r) >> 1;
		if (pos <= mid) { modify (now << 1, l, mid, pos, val); }
		else { modify (now << 1 | 1, mid + 1, r, pos, val); }
		
		pushUp (now);
	}

	int query (int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) { return tr[now].mn; }

		int res = inf;
		int mid = (l + r) >> 1;
		if (L <= mid) { res = std::min (res, query (now << 1, l, mid, L, R)); }
		if (R > mid) { res = std::min (res, query (now << 1 | 1, mid + 1, r, L, R)); }

		return res;
	}
} tr;

std::set <int> pos[maxn];
std::bitset <maxn> vis;

inline int findnxt (int x) {
	auto it = pos[w - a[x]].upper_bound (x);
	auto nxt_x = pos[a[x]].upper_bound (x);

	if (it == pos[w - a[x]].end ()) { return inf; } // 未找到
	if (nxt_x != pos[a[x]].end () and (*nxt_x) < (*it)) { return inf; } // 有更优选择
	else { return (*it); }
}

inline void modify (int x, int val) {
	std::vector <int> upd;
	
	auto it = pos[a[x]].lower_bound (x);
	if (it != pos[a[x]].begin ()) { upd.push_back (*std::prev (it)); }
	
	it = pos[w - a[x]].lower_bound (x);
	if (it != pos[w - a[x]].begin ()) { upd.push_back (*std::prev (it)); }
	
	upd.push_back (x);
	pos[a[x]].erase (x);
	a[x] = val;
	pos[a[x]].insert (x);

	it = pos[a[x]].lower_bound (x);
	if (it != pos[a[x]].begin ()) { upd.push_back (*std::prev (it)); }
	
	it = pos[w - a[x]].lower_bound (x);
	if (it != pos[w - a[x]].begin ()) { upd.push_back (*std::prev (it)); }

	for (auto t : upd) { tr.modify (1, 1, n, t, findnxt (t)); }
}

inline bool query (int l, int r) { return tr.query (1, 1, n, l, r) <= r; }

inline int read () {
	char ch = getchar ();
	int res = 0;
	while (not isdigit (ch)) { ch = getchar (); }
	while (isdigit (ch)) { res = res * 10 + ch - '0'; ch = getchar (); }
	return res;
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	n = read (); m = read (); w = read ();
	rep (i, 1, n) { a[i] = read (); pos[a[i]].insert (i); }

	rep (i, 1, n) { tr.modify (1, 1, n, i, findnxt (i)); }

	int cnt = 0;
	while (m--) {
		int op = read ();
		if (op == 1) {
			int x = read ();
			int val = read ();
			modify (x, val);
		} else {
			int l = read (); int r = read ();
			l ^= cnt; r ^= cnt;
			if (query (l, r)) { std::cout << "Yes\n"; cnt ++; }
			else { std::cout << "No\n"; }
		}
	}

	return 0;
}
