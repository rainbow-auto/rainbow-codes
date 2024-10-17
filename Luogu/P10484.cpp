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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 47;

int w, n;
int g[maxn];

void dfs(int now, int r, i64 sum, std::vector<i64> &a) {
	if (now > r) {
		a.push_back(sum);		
		return;
	}

	dfs(now + 1, r, sum, a);
	dfs(now + 1, r, sum + g[now], a);
}

void solve() {
	std::cin >> w;
	std::cin >> n;

	rep (i, 1, n) std::cin >> g[i];
	int pos = (n >> 1);

	std::vector<i64> a, b;	

	dfs(1, pos, 0, a);
	dfs(pos + 1, n, 0, b);

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	i64 ans = 0;
	for (auto x : a) {
		i64 y = *std::prev(std::lower_bound(b.begin(), b.end(), w - x));
		if (x + y <= w) ans = std::max(ans, x + y);
	}

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

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
