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

int n;
int a[maxn];
int t[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) if (~a[i]) t[a[i]]++;
	rep (i, 1, n) if (t[i] > 1) return std::cout << "No\n", void(0);

	std::cout << "Yes\n";

	std::vector<int> rst;
	rep (i, 1, n) if (not t[i]) rst.push_back(i);

	rep (i, 1, n) {
		if (~a[i]) {
			std::cout << a[i] << " " ;
		} else {
			std::cout << rst.back() << " ";
			rst.pop_back();
		}
 	}
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
