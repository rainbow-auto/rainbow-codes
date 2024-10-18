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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 10005;

int n;
int a[maxn];

bool dfs(int now, int lim) {
	if (now > lim) return a[lim] == n;
	if (1ll * a[now - 1] * (1ll << (lim - now + 1)) < n) return false;

	per (i, now - 1, 1) {
		per (j, now - 1, i) {
			int cur = a[i] + a[j];
			if (cur > n) continue;
			if (a[now - 1] >= cur) continue;

			a[now] = cur;
			if (dfs(now + 1, lim)) return true;
			a[now] = 0;
		}
	}

	return false;
}

bool solve() {
	std::cin >> n;
	if (not n) return false;

	int ans = 1;
	a[1] = 1;
	while (not dfs(2, ans)) ans++;

	rep (i, 1, ans) std::cout << a[i] << " \n"[i == ans];

	return true;
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif

	while (solve());	

	return 0;
}
