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

const int maxn = 100005;

i64 n, k;
i64 a[maxn];

inline i64 count(i64 L) {
	i64 cnt = 0;
	rep (i, 1, n) cnt += a[i] / L; 
	return cnt;
}

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) std::cin >> a[i];	

	i64 l = 1, r = 1e9;
	i64 res = 0;
	while (l <= r) {
		i64 mid = (l + r) >> 1;
		if (count(mid) >= k) {
			l = mid + 1;
			res = mid;
		} else {
			r = mid - 1;
		}
	}

	std::cout << res << "\n";
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
