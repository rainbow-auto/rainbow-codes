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

const int maxn = 1005;

int n;
std::vector<int> tr[maxn];

int fa[maxn];

void solve() {
	std::cin >> n;
	rep (i, 2, n) {
		int x; std::cin >> x;
		tr[x].push_back(i); tr[i].push_back(x);
	} 

	std::queue<int> q; q.push(1);
	std::bitset<maxn> vis; vis.set(1);

	std::vector<int> a; a.push_back(1);
	while (not q.empty()) {
		int now = q.front(); q.pop();
		for (auto t : tr[now]) {
			if (vis[t]) continue;
			a.push_back(t);
			fa[t] = now;
			vis.set(t);
			q.push(t);
		}
	}

	std::reverse(a.begin(), a.end());
	vis.reset();

	auto dfs = [&](auto &&dfs, int now, int dep) -> void {
		if (dep > 2) return;
		vis.set(now);
		for (auto t : tr[now]) {
			dfs(dfs, t, dep + 1);
		}
	};

	int ans = 0;

	for (auto x : a) {
		dbg(x);
		if (vis[x]) continue;
		if (fa[x]) x = fa[x];
		if (fa[x]) x = fa[x];
		
		ans++;
		vis.set(x);
		dfs(dfs, x, 0);
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
