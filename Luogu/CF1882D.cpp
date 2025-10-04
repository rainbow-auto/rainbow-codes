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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 200005;

int n;
i64 a[maxn];

struct Edge {
	int u, v;
	int pre;
	i64 w;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge{u, v, last[u]};
	last[u] = cnt;
}

i64 ans[maxn];
i64 siz[maxn];
void dfs1(int now, int fa) {
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		es[i].w = a[now] ^ a[t];
		dfs1(t, now);
		siz[now] += siz[t];
		ans[1] += siz[t] * es[i].w;
	}
}

void dfs2(int now, int fa) {
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;

		ans[t] = ans[now] - 1ll * siz[t] * es[i].w + 1ll * (n - siz[t]) * es[i].w;
		dfs2(t, now);
	}
}

inline void clr() {
	rep (i, 1, n) ans[i] = siz[i] = 0;
	cnt = 0;
	rep (i, 1, n) last[i] = 0;
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];

	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v); addEdge(v, u);
	}

	dfs1(1, 0);
	dfs2(1, 0);

	rep (i, 1, n) std::cout << ans[i] << " \n"[i == n];

	clr();
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
