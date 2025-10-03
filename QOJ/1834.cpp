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

constexpr int maxn = 10005;

int n, m;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	std::cin >> n;

	std::cout << "? " << n << " "; rep (i, 1, n) std::cout << i << " "; std::cout << "\n";
	std::cout.flush();

	std::cin >> m;

	rep (_, 1, 29) {
		std::vector<int> S, T;
		rep (i, 1, n) {
			bool x = rng() % 2;
			if (x) S.push_back(i);
			else T.push_back(i);
		}

		std::cout << "? " << S.size() << " "; for (auto x : S) std::cout << x << " "; std::cout << "\n";
		std::cout.flush();
		int s; std::cin >> s;
		std::cout << "? " << T.size() << " "; for (auto x : T) std::cout << x << " "; std::cout << "\n";
		std::cout.flush();
		int t; std::cin >> t;

		if ((m - s - t) & 1) return std::cout << "! NO\n" << std::flush, void(0);
	}
	std::cout << "! YES\n" << std::flush;
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
