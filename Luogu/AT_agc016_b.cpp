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

const int maxn = 100005;

int n;
int a[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];

	int c = 0, c1 = 0;
	rep (i, 1, n) c = std::max(c, a[i]);

	rep (i, 1, n) {
		if (a[i] != c) {
			if (a[i] == c - 1) c1++;
			else return std::cout << "No\n", void(0);
		} 
	}

	if (c1 == 0 and c + 1 == n) return std::cout << "Yes\n", void(0); 

	if (c1 + 1 <= c and (n - c1) / (c - c1) >= 2) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
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
