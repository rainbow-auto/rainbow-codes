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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 500005;

int n;
int a[maxn];
int pre[maxn], suf[maxn];

inline int solve(int t) {
	pre[0] = 0; rep (i, 1, n) pre[i] = pre[i - 1] + (a[i] == t) + 1;
	suf[n + 1] = 0; per (i, n, 1) suf[i] = suf[i + 1] + (a[i] == t) + 1;

	std::vector<int> pos;
	pos.push_back(0);
	rep (i, 1, n) if (a[i] != t) pos.push_back(i);
	pos.push_back(n + 1);

	int res = 0x3f3f3f3f;

	int lst = -1;
	for (auto p : pos) {
		if (not ~lst) {
			lst = p;
			continue;
		}

		res = std::min(res, pre[lst] + suf[p]);
		lst = p;
	}

	return res;
}

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		char c; std::cin >> c;
		a[i] = c - '0';
	}			

	std::cout << std::min(solve(0), solve(1)) << "\n";
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
