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


const int maxn = 100005;

inline void solve () {
	int n, k; std::cin >> n >> k;
	std::array <int, maxn> a;
	rep (i, 1, n) { std::cin >> a[i]; }

	int ans = 0;

	i64 curr = 0;
	rep (i, 1, n) { 
		if (a[i] >= k) { curr += a[i]; } 
		else if (a[i] == 0) {
			if (curr > 0) { curr --; ans ++; }
		}
	}

	std::cout << ans << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve ();
	}

	return 0;
}
