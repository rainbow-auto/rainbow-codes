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

constexpr int maxn = 200005;

int n, k;
char a[maxn];

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) std::cin >> a[i];
	
	std::array<int, 2> cnt = {};
	rep (i, 1, n) cnt[a[i] - '0']++;

	k = (n >> 1) - k;
	if (cnt[0] - k >= 0 and cnt[1] - k >= 0) {
		cnt[0] -= k;
		cnt[1] -= k;
	} else return std::cout << "NO\n", void(0);
	
	k = (n >> 1) - k;
	if ((cnt[0] >> 1) + (cnt[1] >> 1) < k) return std::cout << "NO\n", void(0);
	std::cout << "YES\n";
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
