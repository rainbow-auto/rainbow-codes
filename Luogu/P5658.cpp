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

constexpr int maxn = 500005;

int n;

int fa[maxn];
struct Edge {
	int u, v;
	int pre;
} es[maxn << 1];

int last[maxn], cnt;
inline void addEdge(int u, int v) {
	es[++cnt] = Edge {u, v, last[u]};
	last[u] = cnt;
}

char s[maxn];
std::stack<int> stk;

i64 f[maxn];
i64 ans;
void dfs(int now, i64 pre) {
	int t = 0;
	if (s[now] == '(') stk.push(now);
	if (s[now] == ')') if (not stk.empty()) f[now] = f[fa[t = stk.top()]] + 1, stk.pop();
	pre += f[now];
	ans ^= (pre * now);
	for (int i = last[now]; i; i = es[i].pre) {
		int t = es[i].v;
		dfs(t, pre);
	}
	if (s[now] == '(') stk.pop();
	if (t) stk.push(t);
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> s[i];
	rep (i, 2, n) {
		std::cin >> fa[i];
		addEdge(fa[i], i);		
	}

	dfs(1, 0);

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
