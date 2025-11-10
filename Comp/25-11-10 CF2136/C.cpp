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
int a[maxn], f[maxn];
std::vector<int> pos[maxn];
int id[maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		std::cin >> a[i];
		pos[a[i]].push_back(i);
		id[i] = pos[a[i]].size() - 1;
	}

	f[0] = 0;
	rep (i, 1, n) {
		f[i] = f[i - 1];
		if (id[i] - a[i] + 1 >= 0) f[i] = std::max(f[i], f[pos[a[i]][id[i] - a[i] + 1] - 1] + a[i]);
	}

	std::cout << f[n] << "\n";

	// clr
	rep (i, 1, n) std::vector<int>{}.swap(pos[i]);
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
