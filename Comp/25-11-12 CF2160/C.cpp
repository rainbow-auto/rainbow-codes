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

constexpr int maxb = 64;

inline bool chk(i64 n, i64 mx) {
	bool ans = true;
	rep (b, 0, mx) {
		ans &= (((n >> b) & 1) == ((n >> (mx - b)) & 1));
		if (b == mx - b) if ((n >> b) & 1) ans = false;
	}
	return ans;
}

void solve() {
	i64 n; std::cin >> n;

	i64 mx = 0;
	rep (b, 0, maxb - 1) if (n & (1ll << b)) mx = b;

	bool ans = false;
	rep (mxx, mx, maxb - 1) ans |= chk(n, mxx);

	if (ans) std::cout << "YES\n";
	else std::cout << "NO\n";
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
