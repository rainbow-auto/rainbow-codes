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

i64 f[maxn][2][6];
void dfs(int now, int fa) {
	std::vector<int> sons;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		sons.push_back(t);
		dfs(t, now);

		rep (p, 0, k) {
			f[now][1][c] = std::max(f[now][1][c], f[t][1][c] + a[now]);  
			if (c > 0) f[now][1][c] = std::max(f[now][1][c], f[t][0][c - 1] + a[now]);  
		}
	}

	rep (p, 0, k) {
		rep (q, 0, k) {
			if (p + q - 1 > k) continue;
			if (p + q - 1 < 0) continue;
			std::pair<i64, i64> mx;
			for (auto t : sons) {
				if (f[t][1][p] > mx.second) mx.second = f[t][1][p];
				if (mx.second > mx.first) std::swap(mx.first, mx.second);
			}
			f[now][0][p + q - 1] = std::max(f[now][0][p + q - 1], mx.first + mx.second + a[now]);
		}
	}
}

void solve() {
	std::cin >> n >> k;

	rep (i, 1, n) std::cin >> a[i];

	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}	

	dfs(1, 0);
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
