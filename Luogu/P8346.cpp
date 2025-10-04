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

constexpr int maxn = 2000005;

int n, m;

int d[maxn];

std::bitset<maxn> rmv;
std::vector<int> g[maxn];

inline void clr() {
	rmv.reset();
	rep (i, 1, (n << 1)) {
		d[i] = 0;
		g[i].clear();
	}
}

bool chk() {
	std::queue<int> q;
	rep (i, 1, (n << 1)) if (d[i] == 1) {
		q.push(i);
	}
	
	while (not q.empty()) {
		int now = q.front(); q.pop();

		if (rmv[now]) continue;
		rmv[now] = true;

		int v = 0;
		for (auto t : g[now]) {
			if (rmv[t]) continue;
			v = t;
		}

		if (not v) return false;
		rmv[v] = true;
		
		for (auto t : g[v]) {
			if (rmv[t]) continue;
			d[t]--;
			if (d[t] == 1) {
				q.push(t);
			} 
		}
	}
	
	int tot = 0;
	rep (i, 1, (n << 1)) tot += rmv[i];
	
	return tot == (n << 1);
}

void solve() {
	std::cin >> n >> m;

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		v += n;
		g[u].push_back(v);
		g[v].push_back(u);
		d[v]++; d[u]++;
	}

	if (chk()) std::cout << "Renko\n";
	else std::cout << "Merry\n";

	clr();
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
