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

constexpr int maxn = 1000005;

int n, m;
struct Task {
	int a, b;
	friend bool operator < (Task a, Task b) {
		return a.a > b.a;
	}
} ts[maxn];

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) std::cin >> ts[i].a >> ts[i].b;
	rep (i, 1, n) ts[i].a = m - ts[i].a + 1;
	std::sort(ts + 1, ts + n + 1);

	std::priority_queue<int> q;
	
	i64 ans = 0;

	int cur = 1;
	per (i, m, 1) {
		while (ts[cur].a >= i) q.push(ts[cur++].b);

		if (not q.empty()) {
			ans += q.top(); q.pop();
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
