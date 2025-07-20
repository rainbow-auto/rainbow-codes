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

constexpr int maxn = 18;

int n;
std::bitset<(1 << maxn) + 5> ok;

void solve() {
	ok.reset();

	std::cin >> n;
	rep (i, 1, (1 << n) - 1) {
		char c; std::cin >> c;
		if (c == '0') ok.set(i);
	}

	std::queue<int> q; q.push(0);
	std::bitset<1 << maxn> vis; vis[0] = true;

	while (not q.empty()) {
		int S = q.front(); q.pop();
		rep (i, 1, n) {
			if (S & (1 << (i - 1))) continue;
			int nS = (S | (1 << (i - 1)));

			if (not ok[nS]) continue;
			if (vis[nS]) continue;
			vis[nS] = true;
			// db << "to " << std::bitset<3>(nS) << "\n";
			q.push(nS);
		}
	}

	if (vis[(1 << n) - 1]) std::cout << "Yes\n";
	else std::cout << "No\n";

	dbendl
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
