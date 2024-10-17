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
// #define MultiTask lovely_fairytale

const int maxn = 67;

int n;
int mx, mn, sum;

int rst[maxn];

int cnt, len;
bool dfs(int now, int last, int cur) {
	if (now > cnt) return true; 
	if (cur == len) return dfs(now + 1, mx, 0);

	per (i, last, mn) {
		if (rst[i] <= 0) continue;
		if (cur + i > len) continue;

		rst[i]--;
		if (dfs(now, i, cur + i)) return true;
		rst[i]++;

		if (cur + i == len or cur == 0) return false;
	}

	return false;
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _n; std::cin >> _n;
	
	std::memset(&mn, 0x3f, sizeof mn);
	rep (i, 1, _n) {
		int x; std::cin >> x;
		if (x > 50) continue;
		
		mn = std::min(mn, x);
		mx = std::max(mx, x);
		sum += x;

		rst[x] ++;
	}

	db << "mn: " << mn << "\n";
	db << "mx: " << mx << "\n";

	rep (ans, mx, (sum >> 1)) {
		if (sum % ans) continue;

		cnt = sum / ans;
		len = ans;

		if (dfs(1, mx, 0)) return std::cout << ans << "\n", 0;
	}

	std::cout << sum << "\n";

	return 0;
}
