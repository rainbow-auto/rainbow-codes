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
int col[maxn];

struct Edge {
	int u, v; 
	int pre;
} es[maxn << 1];

int last[maxn], cnt;
inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

bool rmv[maxn];

int tot;
int mx[maxn], siz[maxn];
int rt;
void get_rt(int now, int fa) {
	mx[now] = 0;
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		if (rmv[t]) continue;
		get_rt(t, now);
		siz[now] += siz[t];
		mx[now] = std::max(mx[now], siz[t]);
	}
	mx[now] = std::max(mx[now], tot - mx[now]);
	if (mx[rt] > mx[now]) rt = now;
}

i64 ans[maxn];

i64 f[maxn]; // 颜色对应联通块的并
int h[maxn]; // 到根链上的颜色

std::vector<int> cs;
bool vis[maxn];

void dfs1(int now, int fa, int c, i64 &dt) {
	if (not vis[col[now]]) {
		vis[col[now]] = true;
		cs.push_back(col[now]);
	}

	h[col[now]]++;
	if (h[col[now]] == 1) {
		f[col[now]] += c * siz[now];
		dt += siz[now];
	}

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		if (rmv[t]) continue;
		dfs1(t, now, c, dt);
	}

	h[col[now]]--;
}

void dfs2(int now, int fa, int all, int cur, i64 sum) {
	h[col[now]]++;
	if (h[col[now]] == 1) {
		sum -= f[col[now]];
		cur++;
	}
	ans[now] += 1ll * cur * all + sum;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		if (rmv[t]) continue;
		dfs2(t, now, all, cur, sum);
	}
	h[col[now]]--;
}

void calc(int now) {
	i64 fsum = 0;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (rmv[t]) continue;
		h[col[now]] = 1;
		dfs1(t, now, 1, fsum);
	}
	cs.push_back(col[now]);
	vis[col[now]] = true;

	f[col[now]] = siz[now];
	ans[now] += fsum + siz[now];

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (rmv[t]) continue;
		i64 dt = 0;
		dfs1(t, now, -1, dt); // del
		dfs2(t, now, siz[now] - siz[t], 1, fsum - dt);
		dt = 0;
		dfs1(t, now, 1, dt); // del
	}

	for (auto c : cs) f[c] = vis[c] = 0;
	h[col[now]] = 0;
	cs.clear();

	// display
	// db << "ans: "; rep (i, 1, n) db << ans[i] << " "; dbendl;
}

void divide(int now) {
	rmv[now] = true;
	calc(now);

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (rmv[t]) continue;

		mx[rt] = 0x3f3f3f3f;
		tot = siz[t];
		get_rt(t, now);
		get_rt(rt, 0);

		// dbg(t);
		// dbg(rt);
		divide(rt);
	}	
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> col[i];

	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}

	mx[rt] = 0x3f3f3f3f;
	tot = n;
	get_rt(1, 0);
	get_rt(rt, 0);
	// db << "get rt\n";
	// dbg(rt);
	divide(rt);

	rep (i, 1, n) std::cout << ans[i] << "\n";
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
