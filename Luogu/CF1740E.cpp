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

constexpr int maxn = 100005;

int n;

i64 f[maxn], d[maxn];
std::vector<int> g[maxn];

void dfs(int now) {
	i64 dsum = 0;
	d[now] = 1;
	for (auto t : g[now]) {
		dfs(t);
		d[now] = std::max(d[now], d[t] + 1);
		dsum += f[t];
	}
	f[now] = std::max(d[now], dsum);
} 

void solve() {
	std::cin >> n;
	rep (i, 2, n) {
		int fa; std::cin >> fa;
		g[fa].push_back(i);
	}

	dfs(1);

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
