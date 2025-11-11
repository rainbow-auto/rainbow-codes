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
int a[maxn], p[maxn];
int pos[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		std::cin >> p[i];
		pos[p[i]] = i;
	}

	rep (i, 1, n) {
		char c; std::cin >> c;
		a[i] = c - '0';
	}

	if (a[pos[1]] or a[pos[n]]) return std::cout << "-1\n", void(0);
	if (a[1] or a[n]) return std::cout << "-1\n", void(0);

	std::cout << "5\n";
	std::cout << std::min(pos[1], pos[n]) << " " << std::max(pos[1], pos[n]) << "\n";
	std::cout << 1 << " " << pos[1] << "\n";
	std::cout << 1 << " " << pos[n] << "\n";
	std::cout << pos[1] << " " << n << "\n";
	std::cout << pos[n] << " " << n << "\n";
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
