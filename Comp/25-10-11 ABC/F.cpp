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

constexpr int maxn = 65;

int n, m;
int a[maxn];

void dfs(int now, int L, int R, std::array<std::vector<int>, 2> &sum, int cur, bool lst) {
	if (now > R) {
		sum[lst].push_back(cur);
		return;
	}

	if (not lst) dfs(now + 1, L, R, sum, (cur + a[now]) % m, true);
	dfs(now + 1, L, R, sum, cur, false);
}

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) {
		std::cin >> a[i];
	}

	int L1 = 1, R1 = (n >> 1);
	int L2 = R1 + 1, R2 = n;

	std::reverse(a + L2, a + R2 + 1);

	std::array<std::vector<int>, 2> sum1, sum2;
	dfs(L1, L1, R1, sum1, 0, false);
	dfs(L2, L2, R2, sum2, 0, false);

	std::sort(sum1[0].begin(), sum1[0].end());	
	std::sort(sum1[1].begin(), sum1[1].end());	

	std::sort(sum2[0].begin(), sum2[0].end());	
	std::sort(sum2[1].begin(), sum2[1].end());	

	i64 ans = 0;

	rep (b1, 0, 1) rep (b2, 0, 1) {
		if (b1 and b2) continue;
		for (auto sum : sum1[b1]) {
			auto [l, r] = std::equal_range(sum2[b2].begin(), sum2[b2].end(), (m - sum) % m);
			ans += r - l;
		}
	}

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
