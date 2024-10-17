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

const int maxn = 30005;

int n, m;

struct Edge {
	int u, v;
	int pre;
} es[maxn];

int last[maxn], cnt;

int ind[maxn];

inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
	ind[v]++;
}

std::bitset<maxn> f[maxn];

inline void topo() {
	rep (i, 1, n) f[i].set(i);

	std::queue<int> q;
	rep (i, 1, n) if (not ind[i]) q.push(i);

	while (not q.empty()) {
		int now = q.front(); q.pop();

		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			f[t] |= f[now];
			if (--ind[t]) continue;
			q.push(t);
		}
	}
}

void solve() {
	std::cin >> n >> m;

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		addEdge(v, u);
	}

	topo();

	rep (i, 1, n) {
		std::cout << f[i].count() << "\n";
	}
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
