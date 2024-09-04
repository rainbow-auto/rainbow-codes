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

const int maxn = 100005;
const int maxB = 350;

int n, m;
int a[maxn];

int f[maxB][maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n;
	rep (i, 1, n) { std::cin >> a[i]; }	

	int B = sqrt (n);

	rep (k, 1, B) {
		per (i, n, 1) {
			int t = i + a[i] + k;
			if (t > n) { f[k][i] = 1; }
			else { f[k][i] = f[k][t] + 1; }
		}
	}

	int q; std::cin >> q;
	while (q--) {
		int p, k; std::cin >> p >> k;

		if (k <= B) { 
			std::cout << f[k][p] << "\n"; 
		} else {
			int res = 0;
			while (p <= n) {
				p += a[p] + k;
				res ++;
			}
			std::cout << res << "\n";
		}
	}

	return 0;
}
