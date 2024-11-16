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
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

int x, n;

int a[10];

void solve() {
	std::cin >> x >> n;

	rep (i, 1, n) {
		static int cur[10]; cur[0] = -0x3f3f3f3f;
		rep (j, 1, 5) std::cin >> cur[j];

		int mx = 0;
		rep (j, 1, 5) if (cur[j] <= x) if (cur[j] > cur[mx]) mx = j;	

		if (not mx) continue;
		x -= cur[mx];
		a[cur[mx]]++;
	}	
	
	rep (i, 1, 5) std::cout << a[i] << " \n"[i == 5];
	std::cout << x << "\n";
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
