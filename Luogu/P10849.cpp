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

constexpr int maxn = 300005;

int n;
int a[maxn], b[maxn];

void solve() {
	std::cin >> n;
	rep (i, 0, n - 1) std::cin >> b[i];
	rep (i, 0, n - 1) std::cin >> a[i];

	i64 ans = 0;
	std::stack<int> stk;
	rep (i, 0, n - 1) {
		while (not stk.empty() and a[i]) {
			int t = stk.top();
			if (b[t] > a[i]) {
				ans += a[i];
				b[t] -= a[i];
				a[i] = 0;
			} else {
				ans += b[t];
				a[i] -= b[t];
				b[t] = 0; 
				stk.pop();
			}
		}
		stk.push(i);
	}

	rep (i, 0, n - 1) ans -= std::max(a[i] - b[i], 0);

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
