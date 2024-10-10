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
i64 a[maxn], s[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> a[i];
	
	i64 val = 0;
	rep (i, 1, n) val += a[i];
	val /= n;

	i64 cur = 0, sum = 0;
	rep (i, 1, n) {
		sum += a[i]; cur += val;
		s[i] = sum - cur;
	}

	std::sort(s + 1, s + n + 1);

	i64 p = s[(n + 1) >> 1];

	i64 ans = 0;
	rep (i, 1, n) ans += std::abs(s[i] - p); 

	std::cout << ans << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
