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

constexpr int maxn = 1005;

int n;
int a[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];

	rep (i, 1, n - 1) {
		if (std::abs(a[i] - a[i + 1]) <= 1) return std::cout << "0\n", void(0);
	}

	a[0] = a[n + 1] = 0x3f3f3f3f;
	rep (i, 1, n - 1) {
		int l = a[i], r = a[i + 1];
		if (l > r) std::swap(l, r);
		l--, r++;
		if (l <= a[i - 1] and a[i - 1] <= r) return std::cout << "1\n", void(0);
		if (l <= a[i + 2] and a[i + 2] <= r) return std::cout << "1\n", void(0);
	}

	return std::cout << "-1\n", void(0);
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
