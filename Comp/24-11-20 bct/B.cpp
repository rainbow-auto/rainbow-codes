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

const int maxn = 500005;

int n;
struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int deg[maxn];

int last[maxn], cnt;
inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int dfn[maxn], dpos;
void dfs(int now, int fa) {
	dfn[now] = ++dpos;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		dfs(t, now);
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v); addEdge(v, u);
		deg[u]++;
		deg[v]++;
	}

	int rt = 0;
	rep (i, 1, n) if (deg[i] != 1) rt = i;
	dfs(rt, 0);

	std::vector<std::pair<int, int>> lvs;
	rep (i, 1, n) if (deg[i] == 1) lvs.push_back(std::make_pair(dfn[i], (int) i));
	std::sort(lvs.begin(), lvs.end());

	std::vector<std::pair<int, int>> ans;
	rep (i, 1, (lvs.size() + 1) >> 1) {
		int u = lvs[i - 1].second;
		int v = lvs[i - 1 + (lvs.size() >> 1)].second;
		ans.push_back(std::make_pair(u, v));
	}

	std::cout << ans.size() << "\n";
	for (auto x : ans) std::cout << x.first << " " << x.second << "\n";
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
