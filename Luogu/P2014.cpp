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

constexpr int maxn = 305;

int n, W;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];
int last[maxn], cnt;
inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int w[maxn];

int f[maxn][maxn];
void dfs(int now) {
	f[now][1] = w[now];
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		dfs(t);

		per (j, W, 1) {
			rep (k, 0, j - 1) {
				f[now][j] = std::max(f[now][j], f[now][j - k] + f[t][k]);
			}
		}
	}
}

void solve() {
	std::cin >> n >> W;

	rep (i, 1, n) {
		int f; std::cin >> f;
		addEdge(f, i);
		std::cin >> w[i];
	}

	W++;
	dfs(0);

	std::cout << f[0][W] << "\n";
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
