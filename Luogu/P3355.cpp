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

constexpr int maxn = 505;

int n, m;

constexpr int dx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
constexpr int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

namespace Dinic {
	constexpr int maxn = 2 * 500 + 8 * 500 * 500 + 5;
	struct Edge {
		int u, v;
		i64 flow;
		int pre;
	} es[maxn << 1];
	
	int last[maxn], cnt = 1;
	inline void _addEdge(int u, int v, int cap) {
		es[++cnt] = Edge { u, v, cap, last[u] };
		last[u] = cnt;
	}
	
	inline void addEdge(int u, int v, int cap) {
		_addEdge(u, v, cap);
		_addEdge(v, u, 0);
	}
	
	int S, T;
	
	int dep[maxn];
	inline bool bfs() {
		std::memset(dep, 0x3f, sizeof dep); dep[S] = 1;
		std::queue<int> q; q.push(S);
		while (not q.empty()) {
			int now = q.front(); q.pop();
			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;
				if (dep[t] != 0x3f3f3f3f) continue;
				if (not es[i].flow) continue;
				dep[t] = dep[now] + 1;
				q.push(t);
			}
		}

		return dep[T] != 0x3f3f3f3f;
	}

	int cur[maxn];
	int dfs(int now, i64 now_flow) {
		if (now == T or not now_flow) return now_flow;
		i64 res = 0;
		for (int &i = cur[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (not es[i].flow) continue;
			if (dep[t] != dep[now] + 1) continue;
			
			i64 t_flow = dfs(t, std::min(now_flow, es[i].flow));
			if (t_flow) {
				es[i].flow -= t_flow;
				es[i ^ 1].flow += t_flow;
				res += t_flow;
				now_flow -= t_flow;
				if (not now_flow) return res;
			}
		}
		return res;
	}

	int dinic(int _S, int _T) {
		S = _S;
		T = _T;

		int res = 0;
		while (bfs()) {
			std::memcpy(cur, last, sizeof cur);
			res += dfs(S, 0x3f3f3f3f);
		}

		return res;
	}
}

bool flg[maxn][maxn];

inline int get(int x, int y) {
	return (x - 1) * n + y;
}

void solve() {
	std::cin >> n >> m;

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		flg[u][v] = true;
	}	

	int S = get(n, n) + 1;
	int T = S + 1;
	rep (i, 1, n) {
		rep (j, 1, n) {
			if (flg[i][j]) continue;

			if ((i + j) & 1) {
				Dinic::addEdge(S, get(i, j), 1);
			} else {
				Dinic::addEdge(get(i, j), T, 1);
			}
		}
	}
	
	rep (i, 1, n) {
		rep (j, 1, n) {
			if (not ((i + j) & 1)) continue;
			if (flg[i][j]) continue;
			rep (k, 0, 7) {
				int px = i + dx[k];
				int py = j + dy[k];
				if (px < 1 or px > n) continue;
				if (py < 1 or py > n) continue;
				if (flg[px][py]) continue;
				Dinic::addEdge(get(i, j), get(px, py), 0x3f3f3f3f);
			}
		}
	}

	int ans = Dinic::dinic(S, T);
	ans = n * n - m - ans;

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
