#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
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

constexpr int maxn = 200005;
constexpr i64 inf = 1e18;

int n;
i64 a[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) if (not (i & 1)) a[i] *= -1ll;

	i64 sum = 0;
	rep (i, 1, n) sum += a[i];

	std::array<i64, 2> s = { -inf, -inf };
	i64 ans = 0;
	rep (i, 1, n) {
		ans = std::max(ans, -2ll * a[i] + i + s[(i & 1) ^ 1]);
		s[i & 1] = std::max(s[i & 1], -2ll * a[i] - i);
	}

	if (n & 1) ans = std::max(ans, i64(n - 1));
	else ans = std::max(ans, i64(n - 2));

	std::cout << ans + sum << "\n";
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
