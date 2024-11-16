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
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 100005;

int n, m, c;

struct Edge {
	int u, v;
	int pre;
	int w;
} es[maxn];

int last[maxn], cnt;

int ind[maxn];
inline void addEdge(int u, int v, int w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
	ind[v]++;
}

int s[maxn];
void topoSort() {
	std::queue<int> q;
	rep (i, 1, n) if (not ind[i]) q.push(i);

	while (not q.empty()) {
		int now = q.front(); q.pop();
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			ind[t]--;
			s[t] = std::max(s[t], s[now] + es[i].w);
			if (ind[t]) continue;
			q.push(t);
		}
	}
}

void solve() {
	std::cin >> n >> m >> c;
	rep (i, 1, n) std::cin >> s[i];

	rep (i, 1, c) {
		int u, v; std::cin >> u >> v;
		int w; std::cin >> w;
		addEdge(u, v, w);
	}

	topoSort();

	rep (i, 1, n) std::cout << s[i] << "\n";
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
