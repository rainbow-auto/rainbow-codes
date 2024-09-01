#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 1000005;

int n, q, k;
int a[maxn];

namespace Task1 {
	inline void solve () {
		int ans = 0;
		rep (S, 0, (1 << n) - 1) {
			std::vector <int> nums;
			rep (i, 1, n) {
				if (S & (1 << (i - 1))) {
					nums.push_back (a[i]);
				}
			}
			
			rep (i, 0, nums.size () - 1) {
				rep (j, 0, nums.size () - 1) {
					if (a[i] == a[j]) { continue; }
					if ((a[i] xor a[j]) < k) { continue; }
					goto IE;
				}
			}
			ans = std::max (ans, (int) nums.size ());
			IE:;
		}

		std::cout << ans << "\n";
	}
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	freopen ("anfang.in", "r", stdin);
	freopen ("anfang.out", "w", stdout);

	std::cin >> n >> q >> k;
	rep (i, 1, n) { std::cin >> a[i]; }

	Task1::solve ();

	return 0;
}
