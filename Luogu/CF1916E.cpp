#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

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
bool MemST;

const int maxn = 300005;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

struct SegTree {
	struct Node {
		int mx;
		int tag;
	} tr[maxn << 3];

	inline void pushUp (int now) { 
		tr[now].mx = std::max (tr[now << 1].mx, tr[now << 1 | 1].mx);
	}

	inline void apply (int now, int l, int r, int val) {
		tr[now].mx += val;
		tr[now].tag += val;
	}

	inline void pushDown (int now, int l, int r) {
		if (not tr[now].tag) { return; }
		int mid = (l + r) >> 1;
		apply (now << 1, l, mid, tr[now].tag);
		apply (now << 1 | 1, mid + 1, r, tr[now].tag);
		tr[now].tag = 0;
	}

	void modify (int now, int l, int r, int L, int R, int val) {
		if (L <= l and r <= R) { apply (now, l, r, val); return; }

		pushDown (now, l, r);

		int mid = (l + r) >> 1;
		if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
		if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }
		
		pushUp (now);
	}

	int querymx (int now, int l, int r, int L, int R) {
		if (L <= l and r <= R) { return tr[now].mx; }
		
		pushDown (now, l, r);

		int res = 0;
		int mid = (l + r) >> 1;
		if (L <= mid) { res = std::max (res, querymx (now << 1, l, mid, L, R)); }
		if (R > mid) { res = std::max (res, querymx (now << 1 | 1, mid + 1, r, L, R)); }
	
		return res;
	}
} tr;

int n;
int col[maxn];

int siz[maxn];

int dfn[maxn], dpos, id[maxn];
int L[maxn], R[maxn], leafcnt;
void getdfn (int now, int fa) {
	dfn[now] = ++dpos;
	L[now] = 0x3f3f3f3f;
	R[now] = 0;
	siz[now] = 1;

	id[dfn[now]] = now;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }
		getdfn (t, now);

		siz[now] += siz[t];
		L[now] = std::min (L[now], L[t]);
		R[now] = std::max (R[now], R[t]); 
	}

	if (siz[now] == 1) { R[now] = L[now] = ++leafcnt; }
}

i64 ans;

std::set <int> s[maxn];
void dfs (int now, int fa) {
	i64 mx1 = 0, mx2 = 0;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }
	
		dfs (t, now);
	
		auto st = s[col[now]].lower_bound (dfn[t]);
		auto ed = s[col[now]].lower_bound (dfn[t] + siz[t]);

		for (auto it = st; it != ed; it++) {
			tr.modify (1, 1, leafcnt, L[id[*it]], R[id[*it]], -1);
		}
		s[col[now]].erase (st, ed);

		int curr = tr.querymx (1, 1, leafcnt, L[t], R[t]);

		if (curr > mx1) {
			mx2 = mx1; 
			mx1 = curr;
		} else if (curr > mx2) {
			mx2 = curr;
		}
	}
	s[col[now]].insert (dfn[now]);
	tr.modify (1, 1, leafcnt, L[now], R[now], 1);

	ans = std::max (ans, (mx1 + 1) * (mx2 + 1));
}

inline void clear () {
	rep (i, 1, n) { last[i] = 0; }
	cnt = 0;
	rep (i, 1, n) { s[i].clear (); }
	ans = 0;
	dpos = 0;
	leafcnt = 0;
	rep (i, 1, (n << 3)) { tr.tr[i] = SegTree::Node { 0, 0 }; }
}

inline void solve () {
	clear ();

	std::cin >> n;
	rep (i, 2, n) {
		int fa; std::cin >> fa;
		addEdge (fa, i); addEdge (i, fa);
	}

	rep (i, 1, n) { std::cin >> col[i]; }

	getdfn (1, 0);

	dfs (1, 0);

	std::cout << ans << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem

	int T; std::cin >> T;

	while (T--) { solve (); }

	return 0;
}
