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

int n;
i64 a[maxn];
i64 sum[maxn];

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::map <i64, std::vector <int> > t;

	std::cin >> n;
	rep (i, 1, n) {
		i64 x; std::cin >> x;
		t[x].push_back (i);
		sum[i] = sum[i - 1] + x;
	}

	i64 ans = 0;

	std::set <int> s;
	s.insert (0); s.insert (n + 1);
	for (auto now : t) {
		i64 val; std::vector <int> pos;
		std::tie (val, pos) = now;

		for (auto x : pos) {
			auto it = s.upper_bound (x);
			int l = (*std::prev (it)) + 1;
			int r = (*it) - 1;
		
			ans = std::max (ans, val * (sum[r] - sum[l - 1]));
		}

		for (auto x : pos) { s.insert (x); }
	}

	std::cout << ans << "\n";

	return 0;
}
