#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 22000005;

int n; 
char s[maxn];

inline void in() {
	s[++n] = '#';
	std::string _s; std::cin >> _s;
	for (auto c : _s) {
		s[++n] = c;
		s[++n] = '#';
	}
}

int f[maxn];

void solve() {
	in();

	int ans = 0;

	f[1] = 1;
	std::pair<int, int> cur = { 1, 1 };
	rep (i, 2, n) {
		f[i] = std::min(f[2 * cur.second - i], cur.first - i + 1);
		while (i - f[i] >= 1 and i + f[i] <= n and s[i + f[i]] == s[i - f[i]]) f[i]++;
		cur = std::max(cur, {i + f[i] - 1, i});
		ans = std::max(ans, 2 * f[i] - 1);
	}
	
	std::cout << (ans - 1) / 2 << "\n";
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
