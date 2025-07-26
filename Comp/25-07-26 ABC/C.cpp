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

constexpr int maxn = 15;

int n, k, X;

std::string s[maxn];

std::vector<std::string> ss;
int a[maxn];
inline void add() {
	std::string cur = "";
	rep (i, 1, k) {
		cur += s[a[i]];
	}
	ss.push_back(cur);
}

void dfs(int now) {
	if (now > k) return add(), void(0);

	rep (i, 1, n) {
		a[now] = i;
		dfs(now + 1);
	}
}

void solve() {
	std::cin >> n >> k >> X;
	rep (i, 1, n) {
		std::cin >> s[i];
	}

	dfs(1);
	std::sort(ss.begin(), ss.end());

	std::cout << ss[X - 1] << "\n";
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
