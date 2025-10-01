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
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

f64 X;
int m, n;

std::pair<f64, std::pair<int, int>> ans, nxt;

constexpr f64 eps = 1e-14;

void dfs(f64 X, int a, int b, int c, int d) {
	int x = a + c, y = b + d;
	if (x > n or y > m) return;

	decltype(ans) cur = { std::abs(((f64) 1.0 * x / y) - X), { x, y }};	
	nxt = std::min(nxt, cur);
	if (nxt < ans) std::swap(nxt, ans);

	if (X < ((f64) 1.0 * x / y)) dfs(X, a, b, x, y);
	else dfs(X, x, y, c, d);
}

void solve() {
	std::cin >> n >> m;
	std::cin >> X;

	nxt = { 1e18, { 1, 0 } };
	ans = { X, { 0, 1 } };

	dfs(X, 0, 1, 1, 0);

	if (std::fabs(ans.first - nxt.first) < eps) return std::cout << "TOO MANY\n", void(0);

	std::cout << ans.second.first << "/" << ans.second.second << "\n";
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
