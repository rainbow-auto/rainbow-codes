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

const int maxn = 505;
const i64 mod = 1e9 + 7;

i64 fac[maxn];

int n;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

i64 f[maxn][maxn];
i64 ans[maxn][maxn];

i64 g[maxn][maxn]; // 当前
i64 h[maxn][maxn]; // 撤销

int siz[maxn];
i64 c[maxn];
void init(int now, int fa) {
	int tot = 0;
	c[now] = 1;
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v; if (t == fa) continue;
		init(t, now);
		siz[now] += siz[t];
		(c[now] *= 1ll * (++tot) * c[t] % mod) %= mod;
	}
}

void dfs(int now, int fa) {
	std::vector<int> sons;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v; if (t == fa) continue;
		sons.push_back(t);
	}
	
	int m = sons.size();
	rep (i, 0, m) rep (j, 1, n) g[i][j] = 0;
	rep (i, 1, n - 1) g[0][i + 1] = f[now][i];

	rep (i, 1, m) {
		int t = sons[i - 1];
		per (j, m - 1, 0) per (k, n - siz[t], 1) (g[j + 1][k + siz[t]] += g[j][k]) %= mod;
	}

	rep (i, 1, m) {
		int t = sons[i - 1];
		rep (j, 0, m) rep (k, 1, n) h[j][k] = g[j][k];
		rep (j, 0, m - 1) rep (k, 1, n - siz[t]) (((h[j + 1][k + siz[t]] -= h[j][k]) %= mod) += mod) %= mod;
		
		rep (k, 1, n) rep (j, 0, m - 1) (f[t][k] += h[j][k] * fac[j] % mod * fac[m - 1 - j] % mod) %= mod;

		i64 oth = 1;
		rep (j, 1, m) if (i != j) (oth *= c[sons[j - 1]]) %= mod;
		rep (k, 1, n) (f[t][k] *= oth) %= mod;
	}

	rep (i, 1, m) dfs(sons[i - 1], now);
}

void solve() {
	std::freopen("gravekeeper.in", "r", stdin);
	std::freopen("gravekeeper.out", "w", stdout);

	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v); addEdge(v, u);
	}

	fac[0] = 1;
	rep (i, 1, n) fac[i] = fac[i - 1] * i % mod;

	init(1, -1);
	f[1][1] = 1;
	dfs(1, -1);

	rep (i, 1, n) {
		rep (j, 1, n) {
			std::cout << (f[i][j] * c[i]) % mod << " ";
		}
		std::cout << "\n";
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
