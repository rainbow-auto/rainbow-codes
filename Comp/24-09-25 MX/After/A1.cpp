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

const int maxn = 500005;
const i64 mod = 1e9 + 7;

int n;

struct Edge {
	int u, v;
	int pre;
	i64 w;
} es[maxn << 1];

int last[maxn], cnt;

void addEdge(int u, int v, i64 w) {
	es[++cnt] = Edge { u, v, last[u], w };
	last[u] = cnt;
}

i64 dis[maxn][2];
void dfs(int now, int fa, i64 disnow, int& rt, i64& disrt) {
	if (not ~rt or disnow > disrt) rt = now, disrt = disnow;

	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		dfs(t, now, disnow + es[i].w, rt, disrt);
	}
}

void getdis(int now, int fa, int id) {
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		dis[t][id] = dis[now][id] + es[i].w;
		getdis(t, now, id);
	}
}

i64 w[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		i64 w; std::cin >> w;

		addEdge(u, v, w); addEdge(v, u, w);
	}

	int s = -1; i64 diss = 0; dfs(1, -1, 0, s, diss);
	int t = -1; i64 dist = 0; dfs(s, -1, 1, t, dist);

	getdis(s, -1, 0);
	getdis(t, -1, 1);

	rep (i, 1, n) w[i] = std::max(dis[i][0], dis[i][1]);

	std::sort(w + 1, w + n + 1);

	i64 ans = 0;
	rep (i, 1, n) (ans += 2ll * w[i] % mod * (n - i) % mod) %= mod;

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
