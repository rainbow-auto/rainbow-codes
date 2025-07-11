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

constexpr int maxn = 200005;

int n;

int deg[maxn];

struct Edge {
	int u, v; 
	int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge(int u, int v) {
	es[++cnt] = Edge { u, v, last[u] };
	last[u] = cnt;
	deg[v] ++;
}

bool dep[maxn];

bool flg;
std::vector<std::pair<int, int>> ans;
void out(int now, int fa, int dep) {
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		if (t == fa) continue;
		if (dep & 1) ans.push_back(std::pair<int, int>{t, now});
		else ans.push_back(std::pair<int, int>{now, t});
		out(t, now, dep + 1);
	}
}

inline void clr() {
	rep (i, 1, n) deg[i] = last[i] = 0;
	cnt = 0;
	ans.clear();
}

void solve() {
	clr();

	std::cin >> n;
	rep (i, 1, n - 1) {
		int u, v; std::cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	} 

	int x = 0;
	rep (i, 1, n) if (deg[i] == 2) x = i;
	if (not x) return std::cout << "NO\n", void(0);
	
	bool flg = 1;
	for (int i = last[x]; i; i = es[i].pre) {
		int t = es[i].v;
		if (flg) ans.push_back(std::pair<int, int>{x, t});
		else ans.push_back(std::pair<int, int>{t, x});
		
		out(t, x, flg);
		flg ^= 1;
	}

	std::cout << "YES\n";
	for (auto [u, v] : ans) {
		std::cout << u << " " << v << "\n"; 
	}
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
