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
// #define MultiTask lovely_fairytale

const int maxn = 20005;

int n;
i64 T;

struct Edge {
	int u, v;
	int pre;
	i64 w;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v, i64 w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

int ans;
i64 mxdep[maxn];
void dfs(int now, int fa, i64 from) {
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		dfs(t, now, es[i].w);
		mxdep[now] = std::max(mxdep[now], mxdep[t] + es[i].w);
	}
	if (mxdep[now] + from > T) ans++, mxdep[now] = 0;
}

void solve() {
	std::cin >> n;

	int mxw = 0;
	rep (i, 1, n) {
		int k; std::cin >> k;
		while (k--) {
			int t, w; std::cin >> t >> w;
			addEdge(i, t, w);
			mxw = std::max(mxw, w);
		}
	}	

	std::cin >> T;

	if (mxw >= T) return std::cout << "No solution.\n", void(0);

	ans = 0;
	dfs(1, -1, 0);
	std::cout << ans << "\n";
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
