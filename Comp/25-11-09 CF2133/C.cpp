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

constexpr int maxn = 505;

int n;
int f[maxn];
std::vector<int> id[maxn];

std::vector<int> ans;
void dfs(int now) {
	ans.push_back(now);
	if (f[now] == 1) return;

	for (auto t : id[f[now] - 1]) {
		std::cout << "? " << now << " 2 " << now << " " << t << std::endl;
		int con; std::cin >> con;
		if (con == 2) {
			dfs(t);
			break;
		}
	}
}

inline void clr() {
	std::vector<int>{}.swap(ans);
	rep (i, 1, n) std::vector<int>{}.swap(id[i]);
}

void solve() {
	std::cin >> n;

	std::pair<int, int> mx = {0, 0};
	rep (i, 1, n) {
		std::cout << "? " << i << " " << n << " ";
		rep (j, 1, n) std::cout << j << " ";
		std::cout << std::endl;
		std::cin >> f[i];
		mx = std::max(mx, {f[i], i});
		id[f[i]].push_back(i);
	}

	dfs(mx.second);

	std::cout << "! " << mx.first << " ";
	for (auto x : ans) std::cout << x << " ";
	std::cout << std::endl;

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
