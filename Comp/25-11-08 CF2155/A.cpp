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
#define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

void solve() {
	int n; std::cin >> n;

	std::pair<int, int> cur = {n, 0};
	int ans = 1;

	while (not (cur.first == 1 and cur.second == 1)) {
		std::pair<int, int> nxt = {};
		if (cur.first) {
			if (cur.first & 1) {
				nxt.first ++;
				cur.first --;
			}

			ans += (cur.first >> 1);
			nxt.first += (cur.first >> 1);
			nxt.second += (cur.first >> 1);
		}

		if (cur.second) {
			if (cur.second & 1) {
				cur.second--;
				nxt.second++;
			}
			ans += (cur.second >> 1);
			nxt.second += (cur.second >> 1);
		}
		cur = nxt;
	}

	std::cout << ans << "\n";
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
