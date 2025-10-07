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

constexpr int maxn = 1000005;
constexpr int mod = 998244353;

int n, q;

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

int siz[maxn];
int f[maxn];
void dfs1(int now, int fa) {
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		dfs1(t, now);
		siz[now] += siz[t];
		(f[1] += 1ll * es[i].w * siz[t] % mod) %= mod;
	} 
}

void dfs2(int now, int fa) {
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		f[t] = ((f[now] + 1ll * (n - siz[t]) * es[i].w % mod - 1ll * siz[t] * es[i].w) % mod + mod) % mod;
		dfs2(t, now);
	}
}

void solve() {
	std::cin >> n >> q;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		int w; std::cin >> w;
		addEdge(u, v, w);
		addEdge(v, u, w);
	}	

	dfs1(1, 0);
	dfs2(1, 0);
	
	int ans = 0;
	rep (i, 1, n) (ans += f[i]) %= mod;

	while (q--) {
		int u, x; std::cin >> u >> x;
		std::cout << ((ans + 2ll * n * x % mod) % mod + 2ll * f[u] % mod) % mod << "\n";
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
