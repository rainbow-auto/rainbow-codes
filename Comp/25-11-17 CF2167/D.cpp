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

constexpr int maxn = 100005;
constexpr i64 inf = i64(1e18);

int n;
i64 a[maxn];

std::vector<int> ps;
inline void sieve(int N) {
	std::bitset<maxn> vis;
	rep (i, 2, N) {
		if (not vis[i]) ps.push_back(i);
		for (auto p : ps) {
			if (i * p > N) break;
			vis[i * p] = true;
			if (i % p == 0) break;
		}
	}
}

void solve() {
	std::cin >> n;

	i64 ans = inf;
	rep (i, 1, n) {
		std::cin >> a[i];
		ans = std::min(ans, a[i] + 1);
		for (auto p : ps) if (a[i] % p) {
			ans = std::min(ans, i64(p));
			break;
		}
	}

	if (ans == inf) {
		std::cout << "-1\n";
	} else {
		std::cout << ans << "\n";
	}
}

bool MemED;
int main() {
	fastread
	// lookMem	

	sieve(1000);

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
