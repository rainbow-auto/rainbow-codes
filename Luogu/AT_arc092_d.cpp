#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC Optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

const int maxn = 1005;
const int maxm = 200005;

int n, m;

std::vector <int> g[maxn];

struct Edge {
	int u, v;
};
std::vector <Edge> es;

std::bitset <maxn> vis;

bool f[maxn][maxn];
void dfs1 (int now, int st) {
	vis[now] = true; f[st][now] = true;
	for (auto t : g[now]) {
		if (vis[t]) { continue; }
		dfs1 (t, st);
	}
}

int col[maxn][2];

void dfs2 (int now, int colnow, int id) {
	vis[now] = true; col[now][id] = colnow;
	for (auto t : g[now]) {
		if (vis[t]) { continue; }
		dfs2 (t, colnow, id);
	}
}

bool ans[maxn][maxn];

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n >> m;
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		g[u].push_back (v);
		es.push_back (Edge { u, v });
	}

	rep (u, 1, n) { vis.reset (); dfs1 (u, u); }

	rep (u, 1, n) {
		rep (i, 1, n) { col[i][0] = col[i][1] = 0; }

		vis.reset (); vis[u] = true;
		rep (i, 0, (int) g[u].size () - 1) { if (not vis[g[u][i]]) { dfs2 (g[u][i], i + 1, 0); } }

		vis.reset (); vis[u] = true;
		per (i, (int) g[u].size () - 1, 0) { if (not vis[g[u][i]]) { dfs2 (g[u][i], i + 1, 1); } }

		rep (v, 1, n) {
			if (u == v) { continue; }

			bool req1 = f[v][u];
			bool req2 = (col[v][0] != col[v][1]);

			ans[u][v] = (req1 ^ req2);
		}
	}

	for (auto e : es) { std::cout << (ans[e.u][e.v] ? "diff" : "same") << "\n"; }

	return 0;
}
