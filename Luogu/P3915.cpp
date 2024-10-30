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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
#define MultiTask lovely_fairytale

const int maxn = 100005;

int n, k;
struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int siz[maxn];
int tot;
void dfs(int now, int fa) {
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		dfs(t, now);
		siz[now] += siz[t];
	}
	if (siz[now] == k) tot++, siz[now] = 0;
}

void solve() {
	std::memset(last, 0, sizeof last); cnt = 0;

	std::cin >> n >> k;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v); addEdge(v, u);
	}

	if (n % k) return std::cout << "NO\n", void(0);

	tot = 0;
	dfs(1, -1);

	if (tot == n / k) std::cout << "YES\n";
	else std::cout << "NO\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

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
