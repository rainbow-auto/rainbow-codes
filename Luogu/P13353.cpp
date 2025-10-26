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

i64 p[maxn];

i64 f[maxn];
i64 sum[maxn];
int siz[maxn];
void dfs(int now, int fa) {
	siz[now] = 1;
	sum[now] = p[now];
	f[now] = p[now];

	std::vector<int> ts;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;

		dfs(t, now);
		f[now] += f[t];
		siz[now] += siz[t]; 
		sum[now] += sum[t];
		ts.push_back(t);
	}

	std::sort(ts.begin()`, ts.end(), [&](auto u, auto v) -> bool {
		return sum[v] * siz[u] > sum[u] * siz[v];
	});

	i64 pre = 1;
	for (auto t : ts) {
		f[now] += pre * sum[t];
		pre += siz[t];
	}
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> p[i];
	rep (i, 2, n) {
		int f; std::cin >> f;
		addEdge(f, i);
	}

	dfs(1, -1);
	std::cout << f[1] << "\n";
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
