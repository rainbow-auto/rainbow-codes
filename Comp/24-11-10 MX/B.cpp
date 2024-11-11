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
const int mod = 1e9 + 7;

int n;
struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], tot;

inline void addEdge(int u, int v) {
	es[++tot] = Edge { u, v, last[u] };
	last[u] = tot;
}

int cnt[maxn][maxn];

i64 g[maxn]; // legal dfn
int siz[maxn];
int dep[maxn];
void init(int now, int fa) {
	siz[now] = 1;
	g[now] = 1;
	int sons = 0;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v; if (t == fa) continue;
		dep[t] = dep[now] + 1;
		init(t, now);
		sons++;
		(g[now] *= sons * g[t] % mod) %= mod;
		siz[now] += siz[t];
	}
}

i64 f[maxn][maxn][maxn];

i64 nxt[maxn][maxn];
inline void add(i64 cur[maxn][maxn], int x) { // O(n ^ 2)
	rep (i, 0, n) rep (j, 0, n) nxt[i][j] = cur[i][j];

	// dbg(siz[x]);
	// dbg(g[x]);

	rep (i, 0, n) {
		rep (j, 0, n) {
			if (siz[x] <= i) {
				(nxt[i][j] += cur[i - siz[x]][j] * g[x] % mod) %= mod;
			}
			if (siz[x] <= j) {
				(nxt[i][j] += cur[i][j - siz[x]] * g[x] % mod) %= mod;
			}
		}
	}

	// rep (i, 0, n) rep (j, 0, n) db << nxt[i][j] << " \n"[j == n];
	
	rep (i, 0, n) rep (j, 0, n) cur[i][j] = nxt[i][j];
}


void dfs(int now, int fa) {
	std::vector<int> sons;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v; if (t == fa) continue;
		sons.push_back(t);
	}

	for (auto v : sons) { // O(deg)
		rep (i, 0, n) rep (j, 0, n) f[v][i][j] = f[now][i][j];

		for (auto x : sons) { // O(deg)
			if (x == v) continue;
			// add x
			add(f[v], x);
		}
	
		rep (i, 1, n) {
			if (n - (i - 1 + siz[v]) < 0) continue;
			if (i - dep[v] - 1 < 0) continue;
			cnt[v][i] = f[v][i - dep[v] - 1][n - (i - 1 + siz[v])] * g[v] % mod;
		}
		dfs(v, now);
	}
}

// O (n \sum deg ^ 2 n ^ 2)

void solve() {
	std::freopen("gravekeeper.in", "r", stdin);
	std::freopen("gravekeeper.out", "w", stdout);

	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v); addEdge(v, u);
	}

	init(1, 0);

	// rep (i, 1, n) db << g[i] << " \n"[i == n];
	// dbendl;

	// rep (i, 0, n) f[1][0][i] = f[1][i][0] = 1;
	f[1][0][0] = 1;
	cnt[1][1] = g[1];
	dfs(1, 0);

	rep (i, 1, n) {
		rep (j, 1, n) {
			std::cout << cnt[i][j] << " ";
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
