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

const int maxn = 200005;

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

int col[maxn];

i64 siz[maxn], sum[maxn];
i64 ans[maxn];

inline i64 calc(i64 x) {
	return (x * (x - 1) >> 1) + x;
}

void dfs(int now, int fa) {
	i64 old = sum[col[now]];
	siz[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;

		i64 pre = sum[col[now]];
		dfs(t, now);
		siz[now] += siz[t];

		i64 dt = sum[col[now]] - pre; // 变化量即为 t 子树中颜色为 col[now] 的并
		ans[col[now]] += calc(siz[t] - dt);
	}

	sum[col[now]] = old + siz[now]; // merge now
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> col[i];
	
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}

	dfs(1, 0);

	rep (c, 1, n) {
		ans[c] += calc(n - sum[c]);
	}

	rep (i, 1, n) std::cout << calc(n) - ans[i] << "\n";
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
