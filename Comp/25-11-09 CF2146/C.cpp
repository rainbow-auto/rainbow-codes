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

int n;
int a[maxn];

std::bitset<maxn> s;

void solve() {
	std::cin >> n;
	rep (i, 1, n) a[i] = i;

	rep (i, 1, n) {
		char c; std::cin >> c;
		s[i] = c - '0';
	}

	s[0] = 1; s[n + 1] = 1;

	int lst = 0;
	rep (i, 1, n + 1) {
		if (s[i]) {
			if (lst == i - 1) {
				lst = i; continue;
			}
			if (lst == i - 2) {
				return std::cout << "NO\n", void(0);
			}
			// [lst + 1, i - 1]
			std::sort(a + (lst + 1), a + (i - 1) + 1, [&](int x, int y) -> bool {
				return x > y;
			});
			lst = i;
			continue;
		}
	}	
	std::cout << "YES\n";
	rep (i, 1, n) std::cout << a[i] << " "; std::cout << "\n";
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
