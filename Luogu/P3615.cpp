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

const int maxn = 100005;

i64 n;
int m;

i64 t[maxn];

std::string s[maxn];

void solve() {
	std::cin >> n >> m;

	rep (i, 1, m) {
		std::cin >> s[i];
		std::cin >> t[i];
	}

	i64 sum = 0;
	i64 mx = 0;
	per (i, m, 1) {
		i64 dt = 0, mxdt = 0;

		std::reverse(s[i].begin(), s[i].end());
		for (auto c : s[i]) {
			int cur = c == 'F' ? -1 : 1;
			dt += cur;
			mxdt = std::max(mxdt, dt);
		}

		mx = std::max({mx, sum + mxdt, sum + mxdt + dt * (t[i] - 1)});
		sum += dt * t[i];
	}

	if (sum > 0) std::cout << "-1\n"; 
	else std::cout << std::max(0ll, mx - 1) << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

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
