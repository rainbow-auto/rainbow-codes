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

const int maxn = 255;

int n, k;
int a[maxn];

inline void input() {
	std::string s; std::cin >> s;
	n = 0;
	for (auto c : s) a[++n] = c - '0';
	std::cin >> k;
}

void solve() {
	input();

	int m = n - k;

	int lst = 0;
	bool lead = true;
	rep (i, 1, m) {
		std::pair<int, int> mn = std::make_pair(0x3f3f3f3f, 0);
		rep (j, lst + 1, n - (m - i)) {
			mn = std::min(mn, std::make_pair(a[j], int{j}));
		}

		lst = mn.second;
		if (mn.first == 0 and lead) continue;
		std::cout << mn.first;
		lead = false;
	}

	if (lead) std::cout << "0";

	std::cout << "\n";
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
