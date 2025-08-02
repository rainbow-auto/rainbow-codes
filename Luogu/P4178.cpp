#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

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
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 100005;

int n;
int q;

struct Edge {
	int u, v;
	int pre;
	int w;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v, int w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

std::bitset<maxn> rmv;

int siz[maxn], mx[maxn];
int tot, rt;

void get_rt(int now, int fa) {
	siz[now] = 1;
	mx[now] = 0;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		if (rmv[t]) continue;
		get_rt(t, now);
		mx[now] = std::max(mx[now], siz[t]);
		siz[now] += siz[t];
	}
	mx[now] = std::max(mx[now], tot - siz[now]);
	if (mx[now] < mx[rt]) rt = now;
}

int dis[maxn];
std::vector<int> diss;
void get_dis(int now, int fa) {
	diss.push_back(dis[now]);
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		if (rmv[t]) continue;
		dis[t] = dis[now] + es[i].w;
		get_dis(t, now);
	}
}	

struct SegTree {
	struct Node {
		int ls, rs;
		i64 sum;
	} tr[maxn << 4];

	int tot, rt;

	void mdf(int &now, int l, int r, int pos, int v) {
		if (not now) now = ++tot;
		if (l == r) return tr[now].sum += v, void(0);
		int mid = (l + r) >> 1;
		if (pos <= mid) mdf(tr[now].ls, l, mid, pos, v);
		else mdf(tr[now].rs, mid + 1, r, pos, v);
		tr[now].sum = tr[tr[now].ls].sum + tr[tr[now].rs].sum;
	}

	i64 qry(int now, int l, int r, int L, int R) {
		if (not now) return 0;
		if (L <= l and r <= R) return tr[now].sum;
		int mid = (l + r) >> 1;
		if (R <= mid) return qry(tr[now].ls, l, mid, L, R);
		if (L > mid) return qry(tr[now].rs, mid + 1, r, L, R);
		return qry(tr[now].ls, l, mid, L, R) + qry(tr[now].rs, mid + 1, r, L, R);
	}
} tr;

constexpr int maxv = 20000000;

i64 ans;
void calc(int now) {
	std::vector<int> del;
	del.push_back(0);
	tr.mdf(tr.rt, 0, maxv, 0, 1);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (rmv[t]) continue;

		dis[t] = es[i].w;
		get_dis(t, now);
		
		for (auto d : diss) {
			if (q - d >= 0) ans += tr.qry(tr.rt, 0, maxv, 0, q - d);
		}
		
		for (auto d : diss) {
			tr.mdf(tr.rt, 0, maxv, d, 1);
			del.push_back(d);
		}
		diss.clear();
	}

	for (auto d : del) tr.mdf(tr.rt, 0, maxv, d, -1);
}

void divide(int now) {
	rmv[now] = true;
	calc(now);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (rmv[t]) continue;

		tot = siz[t];
		mx[rt] = 0x3f3f3f3f;
		get_rt(t, now);
		get_rt(rt, rt);

		divide(rt);
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		int w; std::cin >> w;
		addEdge(u, v, w);
		addEdge(v, u, w);
	} 	

	std::cin >> q;

	tot = n;
	mx[rt] = 0x3f3f3f3f;
	get_rt(1, 0);
	get_rt(rt, rt);

	divide(rt);

	std::cout << ans << "\n";
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
