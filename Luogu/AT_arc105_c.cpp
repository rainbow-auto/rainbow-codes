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
const int maxS = (1 << 8) + 5;

int n, m;
int a[maxn];
int l[maxn], v[maxn];

int p[maxn];

int lim[maxS];
int dp[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	int max_w = 0;

	std::cin >> n >> m;

	rep (i, 1, n) { std::cin >> a[i]; max_w = std::max (max_w, a[i]); }

	int min_v = 0x3f3f3f3f;
	rep (i, 1, m) { std::cin >> l[i] >> v[i]; min_v = std::min (min_v, v[i]); }

	if (max_w > min_v) { std::cout << "-1\n"; return 0; }

	rep (S, 1, (1 << n) - 1) {
		int sum_w = 0;
		rep (i, 1, n) {
			if (S & (1 << (i - 1))) { sum_w += a[i]; }
		}

		// 找出限制最紧的
		rep (i, 1, m) {
			// 超重, 受到限制
			if (sum_w > v[i]) { 
				lim[S] = std::max (lim[S], l[i]); }
		}
	}

	int ans = 0x3f3f3f3f;

	// 枚举全排列
	rep (i, 1, n) { p[i] = i; }
	do {
		dp[1] = 0;
		rep (i, 2, n) {
			dp[i] = 0;
			int S = (1 << (p[i] - 1));
			per (j, i - 1, 1) {
				S |= (1 << (p[j] - 1));
				dp[i] = std::max (dp[i], dp[j] + lim[S]); // max 是为了找出最紧的限制
			} 
		}  	
		ans = std::min (ans, dp[n]);
	} while (std::next_permutation (p + 1, p + n + 1));

	std::cout << ans << "\n";

	return 0;
}
