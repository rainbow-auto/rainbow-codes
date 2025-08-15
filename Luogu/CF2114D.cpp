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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 700005;

int n, q;
int a[maxn], b[maxn];

int top[maxn], tot;

int ind[maxn];
std::vector<int> g[maxn];

inline void addEdge(int u, int v) {
	g[u].push_back(v);
	ind[v]++;
}

int f[maxn];
void topoSort() {
	std::fill_n(f + 1, tot, 0);

	std::queue<int> q;
	rep (i, 1, tot) if (not ind[i]) q.push(i);
	rep (i, 1, n) f[top[i]] = b[i];

	while (not q.empty()) {
		int now = q.front(); q.pop();

		for (auto t : g[now]) {
			ind[t] --;
			f[t] = std::max(f[t], f[now]);
			if (ind[t] == 0) q.push(t);
		}
	}
}

using Opertion = std::pair<std::pair<int, int>, int>;
std::vector<Opertion> ops;

void solve() {
	std::cin >> n >> q;
	rep (i, 1, n) std::cin >> b[i];
	rep (i, 1, n) top[i] = i;
	tot = n;

	while (q--) {
		int u, v; std::cin >> u >> v;
		int t; std::cin >> t;
		ops.push_back({{u, v}, t});
	
		addEdge(tot + 1, top[u]);
		addEdge(tot + 1, top[v]);
		top[t] = ++tot;
	}

	topoSort();

	// rep (i, 1, n) f[i] = b[i];
	// std::reverse(ops.begin(), ops.end());
	// for (auto [x, t] : ops) {
	// 	int c = f[t]; f[t] = 0;
	// 	f[x.first] = std::max(f[x.first], c);
	// 	f[x.second] = std::max(f[x.second], c);
	// }
	// std::reverse(ops.begin(), ops.end())

	rep (i, 1, n) a[i] = f[i];

	for (auto [x, t] : ops) {
		f[t] = std::min(f[x.first], f[x.second]);
	}
	
	bool ans = true;
	rep (i, 1, n) ans &= (f[i] == b[i]);

	if (not ans) std::cout << "-1\n";
	else {
		rep (i, 1, n) std::cout << a[i] << " ";
		std::cout << "\n";
	}
 
	std::fill_n(ind + 1, tot, 0);
	std::fill_n(top + 1, tot, 0);
	rep (i, 1, tot) g[i].clear();
	tot = 0;

	ops.clear();
	
	// dbendl;
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
