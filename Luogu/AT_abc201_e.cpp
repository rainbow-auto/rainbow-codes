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

constexpr int maxn = 200005;
constexpr i64 mod = 1e9 + 7;

int n;

struct Edge {
	int u, v;
	int pre;
	i64 w;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v, i64 w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

i64 a[maxn];

void dfs(int now, int fa) {
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		a[t] = (a[now] xor es[i].w);
		dfs(t, now);
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		i64 w; std::cin >> w;
		addEdge(u, v, w);
		addEdge(v, u, w);
	}

	dfs(1, 0);

	i64 ans = 0;
	rep (b, 0, 60) {
		std::array<i64, 2> cnt = {};
		rep (i, 1, n) {
			bool x = ((a[i] >> b) & 1);
			(ans += (1ll << b) % mod * cnt[x ^ 1] % mod) %= mod;
			cnt[x]++;
		}
	}

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
