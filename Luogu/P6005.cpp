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

constexpr int maxn = 2005;

int n, m;
i64 C, a[maxn];

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

void upd(int cur) {
	rep (now, 1, n + 1) for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		f[cur + 1][t] = std::max(f[cur + 1][t], f[cur][now] + a[t]);
	}
}

void solve() {
	std::cin >> n >> m >> C;
	rep (i, 1, n) std::cin >> a[i];

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v);
	}

	std::memset(f, -0x3f, sizeof f);
	f[0][1] = 0;

	int mxT = 2000;
	rep (t, 0, mxT) upd(t);

	i64 ans = 0;
	rep (t, 0, mxT) {
		ans = std::max(ans, f[t][1] - C * t * t);
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
