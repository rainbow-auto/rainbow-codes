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

constexpr int maxn = 500005;

int n, m;
i64 a[maxn];

std::bitset<maxn> flg;

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) std::cin >> a[i];
	
	i64 ans = 0;
	
	flg.set();

	per (b, 61, 1) {
		std::bitset<maxn> cur; cur.reset();

		int cnt = 0;
		rep (i, 1, n) {
			bool x = a[i] & (1ll << (b - 1));
			cnt += x;

			if (not (cnt & 1)) cur.set(i);
		}

		if ((flg & cur).count() >= m - 1 and (not (cnt & 1))) {
			flg &= cur;
		} else {
			ans |= (1ll << (b - 1)); 
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
