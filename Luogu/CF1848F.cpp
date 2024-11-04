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

const int maxn = 2000005;

int n;
int a[maxn];
int b[maxn];

void solve() {
	std::cin >> n;
	rep (i, 0, n - 1) std::cin >> a[i];

	if (not *std::max_element(a, a + n)) return std::cout << "0\n", void(0);

	int ans = 0;
	int k = std::__lg(n);

	per (i, k - 1, 0) {
		dbg(i);

		rep (j, 0, n - 1) b[j] = (a[j] xor a[(j + (1 << i)) % n]);

		if (*std::max_element(b, b + n)) std::copy(b, b + n, a), ans |= (1 << i);
	}

	std::cout << ans + 1 << "\n";
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
