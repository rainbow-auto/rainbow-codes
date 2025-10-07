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

int op[maxn];

void solve() {
	int n, q; std::cin >> n >> q;

	std::array<int, 3> cnt; cnt.fill(0);

	bool flg = false;
	rep (i, 1, q) {
		char c; std::cin >> c;
		op[i] = c - '0';
		cnt[op[i]]++;
	}
	
	rep (i, 1, n) {
		if (cnt[0] + cnt[2] < i and cnt[1] + cnt[2] < n - i + 1) {
			std::cout << "+";
		} else if (cnt[0] >= i or cnt[1] >= n - i + 1 or cnt[0] + cnt[1] + cnt[2] >= n) {
			std::cout << "-";
		} else {
			std::cout << "?";
		}
	}
	std::cout << "\n";
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
