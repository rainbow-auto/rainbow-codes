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

const int maxn = 100005;

int n, m;
int a[maxn];
int z[maxn];

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) std::cin >> a[i];

	std::priority_queue<int> q;
	rep (i, 1, m) {
		int x; std::cin >> x;
		q.push(-x);
	}

	std::sort(a + 1, a + n + 1);

	i64 ans = 0;
	rep (i, 1, n) {
		int x; do {
			if (q.empty()) return std::cout << "you died!\n", void(0);
			x = -q.top(); q.pop();	
		} while (x < a[i]);
		ans += x;
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
