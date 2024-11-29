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

const int maxn = 2005;

int n, m;
std::bitset<maxn> a[maxn];

int gauss() {
	int req = 0;
	rep (i, 1, n) {
		int cur = i;
		while (not a[cur][i] and cur <= m) cur++;
		if (cur > m) return -1;
		req = std::max(req, cur);
		if (cur != i) std::swap(a[i], a[cur]);
		rep (j, 1, m) if (j != i and a[j][i]) a[j] ^= a[i];
	}
	return req;
}

void solve() {
	std::cin >> n >> m;

	rep (i, 1, m) {
		rep (j, 1, n) {
			char ch; std::cin >> ch;
			if (ch == '1') a[i].set(j);
		}
		char ch; std::cin >> ch;
		if (ch == '1') a[i].set(n + 1);
	}		

	int ans = gauss();
	if (~ans) {
		std::cout << ans << "\n";
		rep (i, 1, n) {
			if (a[i][n + 1]) std::cout << "?y7M#\n";
			else std::cout << "Earth\n";
		}
	} else {
		std::cout << "Cannot Determine\n";
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
		solve
		();
	}

	return 0;
}
