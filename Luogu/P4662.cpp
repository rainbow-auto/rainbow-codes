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

const int maxn = 100005;

struct Edge {
	int u, v;
	int pre;
	i64 flow;
} es[maxn << 1];

int last[maxn], cnt = 1;
int cur[maxn];

inline void addEdge(int u, int v, int cap, bool flg = true) {
	es[++cnt] = Edge { u, v, last[u], cap };
	last[u] = cnt;
	if (flg) addEdge(v, u, 0, false); 
}

int n, m;
int S, T;

int c[maxn];

int in[maxn], out[maxn];

int dis[maxn];
inline bool bfs() {
	std::queue<int> q; q.push(S);
	std::memset(dis, 0x3f, sizeof dis); dis[S] = 0;

	while (not q.empty()) {
		int now = q.front(); q.pop();
		if (now == T) break;
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (not es[i].flow) continue;
			if (dis[t] != 0x3f3f3f3f) continue;
			dis[t] = dis[now] + 1;
			q.push(t);
		}
	}

	return dis[T] != 0x3f3f3f3f;
}

i64 dfs(int now, i64 now_flow) {
	if (now == T or not now_flow) return now_flow;
	
	i64 sum = 0;
	for (int &i = cur[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (not es[i].flow) continue;
		if (dis[t] != dis[now] + 1) continue;
		
		i64 t_flow = dfs(t, std::min(now_flow, es[i].flow));

		if (t_flow) {
			now_flow -= t_flow; sum += t_flow;
			es[i].flow -= t_flow; es[i ^ 1].flow += t_flow;
			if (not now_flow) return sum;
		}
	}

	return sum;
}

inline void dinic() {
	while (bfs()) {
		std::memcpy(cur, last, sizeof last);
		dfs(S, 0x3f3f3f3f);
	}
}

std::bitset<maxn> vis;
void build(int now) {
	vis.set(now);
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (not es[i].flow) continue;
		if (vis[t]) continue;
		build(t);
	}
}

void solve() {
	std::cin >> n >> m;
	std::cin >> S >> T;

	rep (i, 1, n) {
		std::cin >> c[i];
		in[i] = i;
		out[i] = i + n;
		addEdge(in[i], out[i], c[i]);
	}

	int inf; std::memset(&inf, 0x3f, sizeof inf);

	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		addEdge(out[u], in[v], inf);
		addEdge(out[v], in[u], inf);
	}

	S = in[S];
	T = out[T];

	dinic();

	build(S);

	std::vector<int> ans;

	rep (i, 2, cnt) {
		if (i & 1) continue;
		int u = es[i].u;
		int v = es[i].v;
		if (vis[u] and not vis[v]) ans.push_back(u);
	}

	std::sort(ans.begin(), ans.end());
	for (auto x : ans) std::cout << x << " ";
	std::cout << "\n";
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
