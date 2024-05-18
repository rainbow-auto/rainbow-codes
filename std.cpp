// LUOGU_RID: 113801128
// Problem: G - Minimum Xor Pair Query
// Contest: AtCoder - AtCoder Beginner Contest 308
// URL: https://atcoder.jp/contests/abc308/tasks/abc308_g
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<ll, ll> pii;

const int maxn = 300100;

int q, ch[maxn * 33][2], sz[maxn * 33], ntot, ans[maxn], res = (1 << 30);
vector<int> tree[maxn << 2];

struct node {
	int l, r, x;
	node(int a = 0, int b = 0, int c = 0) : l(a), r(b), x(c) {}
};

inline void insert(int x) {
	int p = 0;
	for (int i = 29; ~i; --i) {
		int t = ((x >> i) & 1);
		if (!ch[p][t]) {
			ch[p][t] = ++ntot;
		}
		p = ch[p][t];
		++sz[p];
	}
}

inline void erase(int x) {
	int p = 0;
	for (int i = 29; ~i; --i) {
		int t = ((x >> i) & 1);
		p = ch[p][t];
		--sz[p];
	}
}

void update(int rt, int l, int r, int ql, int qr, int x) {
	if (ql <= l && r <= qr) {
		tree[rt].pb(x);
		return;
	}
	int mid = (l + r) >> 1;
	if (ql <= mid) {
		update(rt << 1, l, mid, ql, qr, x);
	}
	if (qr > mid) {
		update(rt << 1 | 1, mid + 1, r, ql, qr, x);
	}
}

void dfs(int rt, int l, int r) {
	int lst = res;
	for (int x : tree[rt]) {
		int p = 0, s = 0;
		for (int i = 29; ~i; --i) {
			int t = ((x >> i) & 1);
			if (sz[ch[p][t]]) {
				p = ch[p][t];
			} else {
				s |= (1 << i);
				p = ch[p][t ^ 1];
			}
		}
		res = min(res, s);
		insert(x);
	}
	if (l == r) {
		ans[l] = res;
	} else {
		int mid = (l + r) >> 1;
		dfs(rt << 1, l, mid);
		dfs(rt << 1 | 1, mid + 1, r);
	}
	res = lst;
	for (int x : tree[rt]) {
		erase(x);
	}
}

void solve() {
	scanf("%d", &q);
	map< int, vector<int> > mp;
	int m = 0;
	vector<node> vc;
	for (int i = 1, op, x; i <= q; ++i) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d", &x);
			mp[x].pb(m + 1);
		} else if (op == 2) {
			scanf("%d", &x);
			int l = mp[x].back(), r = m;
			mp[x].pop_back();
			if (l <= r) {
				vc.pb(l, r, x);
			}
		} else {
			++m;
		}
	}
	if (!m) {
		return;
	}
	for (node u : vc) {
		update(1, 1, m, u.l, u.r, u.x);
	}
	for (auto p : mp) {
		int x = p.fst;
		for (int k : p.scd) {
			if (k <= m) {
				update(1, 1, m, k, m, x);
			}
		}
	}
	dfs(1, 1, m);
	for (int i = 1; i <= m; ++i) {
		printf("%d\n", ans[i]);
	}
}

int main() {
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
