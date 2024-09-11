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

#define chkmin(x, y) x = std::min (x, y)

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 105;
const int maxS = 10005;

int n;
int a[maxn], b[maxn];

i64 f[maxn][maxS];

inline i64 w (i64 x, i64 y, i64 a_sum, i64 b_sum) {
	return (i64) (n - 1) * x * x + (n - 1) * y * y + 2ll * a_sum * x + 2ll * b_sum * y;
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _; std::cin >> _;

	while (_--) {
		std::cin >> n;
		rep (i, 1, n) { std::cin >> a[i]; }
		rep (i, 1, n) { std::cin >> b[i]; }

		int sum = 0;

		memset (f, 0x3f, sizeof (f));
		f[0][0] = 0;

		rep (i, 1, n) {
			rep (a_sum, 0, sum) {
				chkmin (f[i][a_sum + a[i]], f[i - 1][a_sum] + w (a[i], b[i], a_sum, sum - a_sum));
				chkmin (f[i][a_sum + b[i]], f[i - 1][a_sum] + w (b[i], a[i], a_sum, sum - a_sum));
			}
			sum += a[i]; sum += b[i];
		}

		i64 ans; memset (&ans, 0x3f, sizeof (ans));
		rep (i, 0, sum) { ans = std::min (ans, f[n][i]); }

		std::cout << ans << "\n";
	}

	return 0;
}
