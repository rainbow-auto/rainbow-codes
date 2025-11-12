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

struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
}

bool msk[maxn];
bool dep[maxn];
int d[maxn];

std::queue<int> leaf;
std::vector<int> chain;
void dfs(int now, int fa) {
	if (now == n) msk[now] = true;
	d[now] = 1;
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		dep[t] = (dep[now] ^ 1);
		dfs(t, now);
		msk[now] |= msk[t];
		d[now]++;
	}
	if (msk[now]) chain.push_back(now);
	if (d[now] == 1 and not msk[now]) leaf.push(now);
}

bool rmv[maxn];

inline void clr() {
	std::exchange(leaf, {});
	std::exchange(chain, {});
	rep (i, 1, n) rmv[i] = msk[i] = d[i] = dep[i] = 0;

	cnt = 0;
	rep (i, 1, n) last[i] = 0;
}

void solve() {
	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}

	dep[1] = 0; dfs(1, 0);

	std::cout << 3 * (n - 1) << "\n";

	while (not leaf.empty()) {
		int now = leaf.front(); leaf.pop();
		rmv[now] = true;
		if (dep[now]) std::cout << "1\n1\n2 " << now << "\n";
		else std::cout << "1\n2 " << now << "\n1\n";
		
		int fa = 0;
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			if (rmv[t]) continue;
			fa = t;
		}
		
		d[fa]--;
		if (msk[fa]) continue;
		if (d[fa] == 1) leaf.push(fa);
	}
	
	std::reverse(chain.begin(), chain.end());
	
	for (auto now : chain) {
		if (now == n) break;
		if (dep[now]) std::cout << "1\n1\n2 " << now << "\n";
		else std::cout << "1\n2 " << now << "\n1\n";
	}

	std::cout << "\n";

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
