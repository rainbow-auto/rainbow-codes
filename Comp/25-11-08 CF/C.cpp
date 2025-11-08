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

constexpr int maxn = 200005;

int n, k;
int a[maxn];

// inline bool chk(int d) {
// 	int cnt = 0;
// 	rep (i, 1, n) {
// 		int x = a[i];
// 		if (x % d == 0) continue;
// 		if (x / 3 >= d) {
// 			// [x - 2d, (x - d) - (x - d) / 2]
// 			int l = (x - d) - (x - d) / 2;
// 			int r = x - 2 * d;
// 			if ((l + d - 1) / d * d <= r) continue;
// 			else cnt++; 
// 		} else {
// 			cnt++;
// 		}
// 	}
// 	return cnt <= k;          
// }

int t[maxn], pre[maxn];

inline bool chk(int d) {
	int cnt = n;
	cnt -= t[d];
	if (2 * d <= n) cnt -= t[2 * d];
	if (3 * d <= n) cnt -= t[3 * d];
	if (4 * d <= n) cnt -= pre[n] - pre[4 * d - 1];
	return cnt <= k;          
}

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) t[a[i]]++;
	rep (i, 1, n) pre[i] = pre[i - 1] + t[i];

	per (g, n, 1) {
		if (chk(g)) {
			std::cout << g << "\n";
			break;
		}
	}

	rep (i, 0, n) t[i] = pre[i] = 0;
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
