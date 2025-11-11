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

constexpr int maxn = 400005;

int n;
int a[maxn];

inline i64 calc(int l, int r) {
	std::vector<int> v;
	rep (i, l, r) v.push_back(a[i]);
	std::sort(v.begin(), v.end());
	i64 res = 0;
	for (auto x : v) res += std::abs(x - v[1]);
	return res;
}

i64 f[maxn];
inline i64 solve(int l, int r) {
	f[l - 1] = 0;
	rep (i, l, r) {
		f[i] = 1e18;
		if (i - 2 >= l - 1) f[i] = std::min(f[i], f[i - 2] + calc(i - 1, i));
		if (i - 3 >= l - 1) f[i] = std::min(f[i], f[i - 3] + calc(i - 2, i));
	}

	return f[r];
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) a[i + n] = a[i];

	i64 ans = 1e18;
	rep (i, 1, 3) ans = std::min(ans, solve(i, n + i - 1));
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
