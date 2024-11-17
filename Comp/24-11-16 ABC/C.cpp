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

const int maxn = 500005;

int n, k;
bool a[maxn];

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) {
		char c; std::cin >> c;
		a[i] = c == '1';
	}

	int cur = 0;
	int len = 0;
	int lst = 0;
	int st = 0;
	rep (i, 1, n + 1) {
		if (a[i] == a[i - 1]) continue;
		if (a[i] == 1 and a[i - 1] == 0) {
			cur++;
			if (cur == k) st = i;
		}
		if (a[i] == 0 and a[i - 1] == 1) {
			if (cur == k - 1) lst = i;
			if (cur == k) len = i - st;
		}
	}

	dbg(lst);
	dbg(st);
	dbg(len);

	rep (i, 1, n) {
		if (lst <= i and i <= lst + len - 1) std::cout << 1;
		else if (st <= i and i <= st + len - 1 and a[i]) std::cout << 0; 
		else std::cout << a[i];
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
