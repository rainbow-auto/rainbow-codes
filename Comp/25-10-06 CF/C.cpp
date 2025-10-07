#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

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

int n;
int a[maxn];

int pre[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		char c; std::cin >> c;
		a[i] = c - 'a';
	}
	
	int all = 0;
	pre[0] = 0;
	rep (i, 1, n) {
		pre[i] = pre[i - 1] + (a[i] ? 1 : -1);
		all += (a[i] ? 1 : -1);
	}

	int ans = 0;

	std::map<int, int> s;
	s[0] = 0;
	int cur = 0;
	per (i, n, 0) {
		if (s.count(-pre[i])) {
			ans = std::max(ans, i + s[-pre[i]]);
		}

		cur += (a[i] ? 1 : -1);
		s[cur] = std::max(s[cur], n - i + 1);
	}

	if (ans == 0) std::cout << -1 << "\n";
	else std::cout << n - ans << "\n";
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
