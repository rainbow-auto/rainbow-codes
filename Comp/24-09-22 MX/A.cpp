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

const int maxn = 1000005;

int n;
bool s[maxn];
int r[maxn];
int t[maxn];

int diff[maxn];

inline void solve () {
	std::cin >> n;
	rep (i, 1, n) { char c; std::cin >> c; s[i] = c - '0'; }	

	rep (i, 1, n) { std::cin >> r[i]; }
	rep (i, 1, n) { std::cin >> t[i]; }

	i64 ans = 0;
	int curr = 0;
	rep (i, 1, n) {
		curr += diff[i];
		if (s[i] ^ (curr & 1)) {
			ans += t[i];
			diff[r[i] + 1] --;
			curr ++;
		}
	}
	std::cout << ans << "\n";
}	

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen ("poker.in", "r", stdin);
	freopen ("poker.out", "w", stdout);

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve ();
	}

	return 0;
}
