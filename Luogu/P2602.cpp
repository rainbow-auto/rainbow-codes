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

std::vector<int> a;
i64 f[maxn][maxn][2][2];
inline i64 solve(int now, i64 d, int sum, bool lim, bool lead) {
	if (now < 0) return sum;
	i64 &ans = f[now][sum][lim][lead];
	if (~ans) return ans;
	ans = 0;
	rep (k, 0, (lim ? a[now] : 9)) 
		ans += solve(now - 1, d, sum + ((k == d) and (not (lead and d == 0))), lim and (k == a[now]), lead and (k == 0));
	return ans;
}

inline i64 solve(i64 x, i64 d) {
	std::exchange(a, {});
	while (x) {
		a.push_back(x % 10);
		x /= 10;
	}
	std::memset(f, -1, sizeof f);
	return solve(a.size() - 1, d, 0, true, true);
}

void solve() {
	i64 L, R; std::cin >> L >> R;
	rep (i, 0, 9) {
		std::cout << solve(R, i) - solve(L - 1, i) << " ";
	}
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
