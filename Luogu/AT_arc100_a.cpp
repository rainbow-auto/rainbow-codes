#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 2000005;

int n;
int a[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) a[n + i] = a[i];

	bool flg = true;
	rep (i, 1, n) flg &= a[i] == 1;
	if (flg) return std::cout << "Yes\n", void(0);

	if (n % 4 == 0) return std::cout << "Yes\n", void(0);
	if (n % 4 == 1 or n % 4 == 3) {
		int mx = 0;
		int lst = 0x3f3f3f3f;
		rep (i, 1, (n << 1)) {
			if (a[i]) continue;
			mx = std::max(mx, i - lst - 1);
			lst = i;
		}
		if (mx < 1) return std::cout << "No\n", void(0);
	}
	if (n % 4 == 2) {
		bool flg = false;
		int lst = -1;
		rep (i, 1, (n << 1)) {
			if (not a[i]) continue;
			if (~lst) flg |= ((i - lst - 1) & 1) == 0;
			lst = i;
		}
		if (not flg) return std::cout << "No\n", void(0);
	}

	std::cout << "Yes\n";
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
