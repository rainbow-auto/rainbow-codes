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

constexpr int maxn = 200005;

int n, k;
int a[maxn];

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) std::cin >> a[i];
	std::sort(a + 1, a + n + 1);

	std::multiset<int> b;
	rep (i, 1, k) {
		int x; std::cin >> x;
		b.insert(x);
	}

	i64 ans = 0;
	int rst = 0;
	per (i, n, 1) {
		if (not b.empty() and (*b.begin()) <= rst + 1) {
			rst -= (*b.begin()) - 1;
			b.erase(b.begin());
		} else {
			rst ++;
			ans += a[i];
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
