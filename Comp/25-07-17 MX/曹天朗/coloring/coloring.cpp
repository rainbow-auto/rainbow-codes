/*
这文件名和大阳历文件夹名不一样。

太阴了。
*/

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

const int maxn = 100005;

int n, q;

char a[maxn];
inline void calc(std::array<int, maxn> &f) {
	std::set<char> s;
	int cur = 0;
	rep (i, 1, n) {
		if (not s.count(a[i])) cur++;
		f[i] = cur;
		rep (k, a[i] + 1, 'z') if (s.count(char(k))) s.erase(char(k));
		s.insert(a[i]);
	}
}

void solve() {
	std::cin >> n >> q;
	rep (i, 1, n) std::cin >> a[i];

	std::array<int, maxn> pre, suf;
	calc(pre);
	std::reverse(a + 1, a + n + 1);
	calc(suf);

	while (q--) {
		int l, r; std::cin >> l >> r;
		std::cout << pre[l - 1] + suf[n - r] << "\n";
	}
}

bool MemED;
int main() {
	fastread
	// lookMem	

	file("coloring")

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
