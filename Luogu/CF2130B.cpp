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

void solve() {
	int n, s;
	std::cin >> n >> s;

	std::vector<int> t(3);

	i64 sum = 0;
	rep (i, 1, n) {
		int x; std::cin >> x;
		t[x]++;
		sum += x;
	}

	if (s == sum) return std::cout << "-1\n", void(0);
	if (s > sum + 1) return std::cout << "-1\n", void(0);

	rep (i, 1, t[0]) std::cout << 0 << " ";
	rep (i, 1, t[2]) std::cout << 2 << " ";
	rep (i, 1, t[1]) std::cout << 1 << " ";
	std::cout << "\n";
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
