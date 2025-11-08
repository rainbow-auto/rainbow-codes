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

constexpr int maxn = 100005;

int n, q;
int a[maxn];

void solve() {
	std::cin >> n >> q;

	bool flg = true;
	rep (i, 1, n) {
		char c; std::cin >> c;
		a[i] = c - 'A';
		flg &= a[i] == 0;
	}
	
	if (flg) {
		rep (i, 1, q) {
			int x; std::cin >> x;
			std::cout << x << "\n";
		}
	} else {
		rep (i, 1, q) {
			int x; std::cin >> x;
			int now = 1;
			int res = 0;
			while (x) {
				if (a[now] == 1) x >>= 1;
				else x--;
				res ++;
				now ++; now = (now - 1) % n + 1;
			}
	
			std::cout << res << "\n";
		}
	}

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
