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

constexpr int maxn = 200005;

int n;

int ind[maxn];

struct Edge {
	int u, v;
	int pre;
} es[maxn];

int last[maxn], cnt;
inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
	ind[v]++;
}

int ans[maxn];

inline void clr() {
	rep (i, 1, n) last[i] = ind[i] = 0;
	cnt = 0;
}

void solve() {
	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v, x, y; std::cin >> u >> v >> x >> y;
		if (x > y) addEdge(u, v);
		else addEdge(v, u);
	}

	std::queue<int> q;
	rep (i, 1, n) if (not ind[i]) q.push(i);

	int cur = n;
	while (not q.empty()) {
		int now = q.front(); q.pop();
		ans[now] = cur;
		cur--;

		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			ind[t]--;
			if (not ind[t]) q.push(t);
		}
	}

	rep (i, 1, n) std::cout << ans[i] << " "; std::cout << "\n";

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
