/*
这我那会啊。
*/

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

int n, m;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn];
int cnt = 1;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

int cut;

int dfn[now], dpos, low[maxn];
void tarjan(int now, int in) {
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (not dfn[t]) {
			tarjan(t);
			low[now] = std::min(low[now], low[t]);

			if (dfn[now] < dfn[t]) {
				cut ++;		
			}
		} else if (i != in ^ 1) {
			low[now] = std::min(low[now], dfn[t]);
		}
	}
}

void solve() {
	std::cin >> n >> m;	
	if (m == n - 1) return std::cout << "-1\n", void(0);

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}

	tarjan(1);

	std::cout << n - cut << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

	file("beehive")

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
