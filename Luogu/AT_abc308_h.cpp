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

const int maxn = 305;

int n, m;
i64 g[maxn][maxn];

inline void addEdge(int u, int v, i64 w) {
	g[u][v] = g[v][u] = w;
}

i64 dis[maxn];
int col[maxn];
std::bitset<maxn> vis;
inline i64 calc(int S, int ban) {
	dbg(S);
	db << "ban " << ban << "\n";

	std::memset(dis, 0x3f, sizeof dis);
	std::memset(col, 0, sizeof col);
	vis.reset();

	vis.set(ban);
	dis[S] = 0;

	while (true) {
		int now = 0;
		rep (i, 1, n) if (not vis[i] and dis[i] < dis[now]) now = i;
		if (not now) break;
		vis.set(now);
		rep (t, 1, n) if (g[now][t] and not vis[t]) {
			if (dis[t] > dis[now] + g[now][t]) {
				dis[t] = dis[now] + g[now][t];
				if (now != S) col[t] = col[now];		
				else col[t] = t;
			}
		}
	}

	db << "dis: "; rep (i, 1, n) db << dis[i] << " "; dbendl;

	vis.reset(ban);

	i64 res; std::memset(&res, 0x3f, sizeof res);
	rep (i, 1, n) if (i != S and g[S][i] and vis[i] and col[i] != i) res = std::min(res, g[S][i] + dis[i]);
	dbg(res);
	rep (i, 1, n) rep (j, i + 1, n) if (vis[i] and vis[j] and i != S and j != S and g[i][j] and col[i] != col[j]) res = std::min(res, dis[i] + g[i][j] + dis[j]);
	dbg(res);
	return res;
}

void solve() {
	std::cin >> n >> m;
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		i64 w; std::cin >> w;
		addEdge(u, v, w);
		addEdge(v, u, w);
	} 

	i64 ans; std::memset(&ans, 0x3f, sizeof ans);
	rep (S, 1, n) {
		std::vector<std::pair<int, int>> ts;
		rep (i, 1, n) if (g[S][i]) ts.push_back(std::make_pair(g[S][i], i));
		std::sort(ts.begin(), ts.end());
		if (ts.size() > 3) ts.resize(3);
		for (auto x : ts) {
			// i64 upd = x.first + calc(S, x.second);
			// dbg(upd);
			// ans = std::min(ans, upd);
			ans = std::min(ans, x.first + calc(S, x.second));
		}
	}

	i64 inf; std::memset(&inf, 0x3f, sizeof inf);
	if (ans == inf) std::cout << "-1\n";
	else std::cout << ans << "\n";
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
