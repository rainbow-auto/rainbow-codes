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

constexpr int maxn = 100005;

int n;
std::pair<int, int> ls[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) std::cin >> ls[i].first >> ls[i].second;

	int sx, sy; std::cin >> sx >> sy;
	int tx, ty; std::cin >> tx >> ty;

	if (sx > tx) std::swap(sx, tx); 
	if (sy > ty) std::swap(sy, ty); 

	int ans = 0;
	rep (i, 1, n) {
		if (ls[i].first == 1) {
			ans += (sx <= ls[i].second and ls[i].second <= tx);
		} else {
			ans += (sy <= ls[i].second and ls[i].second <= ty);
		}
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
