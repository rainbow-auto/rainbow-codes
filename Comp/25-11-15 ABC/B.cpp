#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

void solve() {
	std::string s; std::cin >> s;
	int n = s.size();
	std::vector<int> p(n);
	rep (i, 0, n - 1) p[i] = i;
	
	int ans = 0x3f3f3f3f;
	do {
		bool lead = true;
		if (s[p[0]] == '0') continue;

		int cur = 0;
		rep (i, 0, n - 1) {
			cur = cur * 10 + s[p[i]] - '0';
		}

		ans = std::min(ans, cur);
	} while (std::next_permutation(p.begin(), p.end()));

	std::cout << ans << '\n';
}

bool MemED;
int main() {
	fastread
	// lookMem	

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
