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

const int maxn = 1000005;

int n;
int p[maxn];
int a[maxn];

int ans[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> p[i];
	rep (i, 1, n) std::cin >> a[i];

	std::sort(a + 1, a + n + 1);

	int pre = 0, suf = n + 1;
	rep (i, 1, n) {
		if (i & 1) ans[++pre] = a[i]; 
		else ans[--suf] = a[i];
	}

	int mx = std::abs(ans[n] - ans[1]);
	rep (i, 2, n) mx = std::max(mx, std::abs(ans[i] - ans[i - 1]));

	std::cout << mx << "\n";

	rep (i, 1, n) std::cout << ans[i] << " \n"[i == n];
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::freopen("apples.in", "r", stdin);
	std::freopen("apples.out", "w", stdout);

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
