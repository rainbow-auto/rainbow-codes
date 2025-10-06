#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
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

constexpr int maxn = 300005;

int n;
int s[maxn << 1];

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		std::cin >> s[i];
		s[i + n] = s[i];
	}	

	int p = 1;
	for (int i = 2; i <= n; ) {
		int lcp = 0;
		while (s[i + lcp] == s[p + lcp] and lcp < n) lcp++;
		if (s[i + lcp] > s[p + lcp]) {
			i = i + lcp + 1;
		} else {
			int nxt = std::max(i + 1, p + lcp + 1);
			p = i;
			i = nxt;
		}
	}

	rep (i, 1, n) std::cout << s[p + i - 1] << " "; std::cout << "\n";
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
