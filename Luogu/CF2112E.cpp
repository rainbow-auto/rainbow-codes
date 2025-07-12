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

const int maxn = 500005;

int m;

bool fst = true;
std::vector<int> ds[maxn];

int f[maxn];

inline void init() {
	if (not fst) return;
	int n = 500000;
	// rep (i, 2, n) {
	// 	for (int d = 1; d * d <= i; d++) {
	// 		if (i % d) continue;
	// 		ds[i].push_back(d);
	// 		if (i / d != d) ds[i].push_back(i / d);
	// 	}
	// }

	rep (d, 1, n) for (int t = d; t <= n; t += d) ds[t].push_back(d);

	std::memset(f, 0x3f3f3f3f, sizeof f);
	f[1] = 1;
	rep (i, 2, n) {
		for (auto d : ds[i]) {
			if (d > 2) f[i] = std::min(f[i], f[i / d] + f[d - 2]);
		}
	}

	fst = false;
}

void solve() {
	init();

	std::cin >> m;

	if (f[m] == 0x3f3f3f3f) std::cout << "-1\n";
	else std::cout << f[m] << "\n";
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
