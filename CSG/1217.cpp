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

const int maxn = 200005;
const int inf = 0x3f3f3f3f;
const i64 mod = 1e9 + 7;

struct SegTree1 {
	struct Node {
		i64 s1, s2;
		i64 tag1, tag2;
	} tr[maxn << 3];

	inline void pushUp (int now) {
		tr[now].s1 = ((tr[now << 1].s1 + tr[now << 1 | 1].s1) % mod + mod) % mod;
		tr[now].s2 = ((tr[now << 1].s2 + tr[now << 1 | 1].s2) % mod + mod) % mod;
	}

	inline void apply (int now, int l, int r, i64 val1, i64 val2) {
		tr[now].s1 = ((tr[now].s1 + (val1 * (r - l + 1)) % mod) % mod + mod) % mod;
		tr[now].s2 = ((tr[now].s2 + (val2 * (r - l + 1)) % mod) % mod + mod) % mod;
		tr[now].tag1 = ((tr[now].tag1 + val1) % mod + mod) % mod;
		tr[now].tag2 = ((tr[now].tag2 + val2) % mod + mod) % mod;
	}

	inline void pushDown (int now, int l, int r) {
		if (not tr[now].tag1 and not tr[now].tag2) { return; }
		int mid = (l + r) >> 1;
		apply (now << 1, l, mid, tr[now].tag1, tr[now].tag2);
		apply (now << 1 | 1, mid + 1, r, tr[now].tag1, tr[now].tag2);
		tr[now].tag1 = tr[now].tag2 = 0;
	}

	void modify (int now, int l, int r, int L, int R, i64 val1, i64 val2) {
		if (L <= l and r <= R) { apply (now, l, r, val1, val2); return; }
		pushDown (now, l, r);

		int mid = (l + r) >> 1;
		if (L <= mid) { modify (now << 1, l, mid, L, R, val1, val2); }
		if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val1, val2); }
		pushUp (now);
	}

	i64 querys1 (int now, int l, int r, int pos) {
		if (l == r) { return tr[now].s1; }
		pushDown (now, l, r);
		
		int mid = (l + r) >> 1;
		if (pos <= mid) { return querys1 (now << 1, l, mid, pos); }
		if (pos > mid) { return querys1 (now << 1 | 1, mid + 1, r, pos); }
	}

	i64 querys2 (int now, int l, int r, int pos) {
		if (l == r) { return tr[now].s2; }
		pushDown (now, l, r);
		
		int mid = (l + r) >> 1;
		if (pos <= mid) { return querys2 (now << 1, l, mid, pos); }
		if (pos > mid) { return querys2 (now << 1 | 1, mid + 1, r, pos); }
	}
} tr;

struct SegTree2 {
	struct Node {
		int mn;
		
		int tag;
		bool cov;

		Node () { mn = tag = inf; cov = false; }
	} tr[maxn << 3];

	inline void pushUp (int now) { tr[now].mn = std::min (tr[now << 1].mn, tr[now << 1 | 1].mn); }

	inline void cover (int now, int val) {
		tr[now].mn = std::min (tr[now].mn, val);
		tr[now].tag = std::min (tr[now].tag, val); tr[now].cov = true;
	}

	inline void pushDown (int now) {
		if (not tr[now].cov) { return; }
		cover (now << 1, tr[now].tag);
		cover (now << 1 | 1, tr[now].tag);
		tr[now].tag = inf; tr[now].cov = false;
	}

	void modify (int now, int l, int r, int L, int R, int val) {
		if (L <= l and r <= R) { cover (now, val); return; }
		pushDown (now);
		int mid = (l + r) >> 1;
		if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
		if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }
		pushUp (now);
	}

	inline int query (int now, int l, int r, int pos) {
		if (l == r) { return tr[now].mn; }
		pushDown (now);
		int mid = (l + r) >> 1;
		if (pos <= mid) { return query (now << 1, l, mid, pos); }
		if (pos > mid) { return query (now << 1 | 1, mid + 1, r, pos); }
	}
} time_tr;

struct Edge {
	int u, v; 
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int dep[maxn];
int siz[maxn];
int dfn[maxn], dpos;
void dfs (int now, int fa) {
	dfn[now] = ++dpos;
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) { continue; }
		dep[t] = dep[now] + 1;
		dfs (t, now);
		siz[now] += siz[t];
	}
}

int n, q;

struct Event {
	int t;
	int op;
	int u;
	i64 a, b;
};

std::vector <Event> events;

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n >> q;
	rep (i, 2, n) {
		int fa; std::cin >> fa;
		addEdge (fa, i); addEdge (i, fa);
	}

	dpos = 0;
	dep[1] = 1;
	dfs (1, 0);

	rep (t, 1, q) {
		int op; std::cin >> op;
		if (op == 1) {
			int u; std::cin >> u;
			i64 a, b; std::cin >> a >> b;
			events.push_back (Event { t, op, u, a, b });
		} else if (op == 2) {
			int u; std::cin >> u;
			events.push_back (Event { t, op, u, 0, 0 });
		} else if (op == 3) {
			int u; std::cin >> u;
			events.push_back (Event { t, op, u, 0, 0 });
		}
	}

	std::sort (events.begin (), events.end (), [](Event x, Event y) -> bool { return x.t > y.t; });

	rep (i, 0, q - 1) {
		Event curr = events[i];
		if (curr.op == 3) {
			time_tr.modify (1, 1, dpos, dfn[curr.u], dfn[curr.u] + siz[curr.u] - 1, curr.t);			
		} else if (curr.op == 1) {
			int t = time_tr.query (1, 1, dpos, dfn[curr.u]);
			events.push_back (Event { t, 4, curr.u, curr.a, curr.b });
		}
	}

	std::sort (events.begin (), events.end (), [](Event x, Event y) -> bool { return x.t < y.t; });

	for (auto curr : events) {
		i64 c = ((dep[curr.u] & 1) ? -1ll : 1ll);

		if (curr.op == 1) {
			i64 s1 = c * (curr.a - dep[curr.u] * curr.b);
			i64 s2 = c * curr.b;

			s1 = (s1 % mod + mod) % mod;
			s2 = (s2 % mod + mod) % mod;

			tr.modify (1, 1, dpos, dfn[curr.u], dfn[curr.u] + siz[curr.u] - 1, s1, s2);
		} else if (curr.op == 2) {
			i64 s1 = tr.querys1 (1, 1, dpos, dfn[curr.u]);
			i64 s2 = tr.querys2 (1, 1, dpos, dfn[curr.u]);

			i64 val = (c * (s1 + dep[curr.u] * s2 % mod) % mod + mod) % mod;
			std::cout << val << "\n";
		} else if (curr.op == 4) {
			i64 s1 = -1ll * c * (curr.a - dep[curr.u] * curr.b);
			i64 s2 = -1ll * c * curr.b;
			
			s1 = (s1 % mod + mod) % mod;
			s2 = (s2 % mod + mod) % mod;

			tr.modify (1, 1, dpos, dfn[curr.u], dfn[curr.u] + siz[curr.u] - 1, s1, s2);
		}
	}

	return 0;
}
