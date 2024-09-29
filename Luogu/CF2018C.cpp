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

int n;

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

// d >= dep[now] and mxd[now] >= d <=> d \in [dep_now, mxd_now]
int dep[maxn], mxd[maxn];
void dfs(int now, int fa) {
	mxd[now] = dep[now];
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		dep[t] = dep[now] + 1;
		dfs(t, now);
		mxd[now] = std::max(mxd[now], mxd[t]);
	}
}

int dif[maxn];
void add(int l, int r) {
	dif[l] ++; dif[r + 1]--;
}

void clear() {
	rep (i, 1, n) last[i] = 0;
	cnt = 0;
	rep (i, 1, n) dep[i] = mxd[i] = 0;
	rep (i, 1, n + 1) dif[i] = 0;
}

void solve() {
	std::cin >> n;

	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v); addEdge(v, u);
	}
	
	dep[1] = 1;
	dfs(1, -1);

	rep (i, 1, n) add(dep[i], mxd[i]);

	int ans; std::memset(&ans, 0x3f, sizeof ans);
	int cur = 0;
	rep (d, 1, n + 1) {
		cur += dif[d];
		ans = std::min(ans, n - cur);
	}

	std::cout << ans << "\n";

	clear();
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
