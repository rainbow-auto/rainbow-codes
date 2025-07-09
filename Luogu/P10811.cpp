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

const int maxn = 2005;
const int maxv = 4000005;

std::vector<int> a;

std::bitset<maxv> f;

void solve() {
	int _n; std::cin >> _n;
	rep (i, 1, _n) {
		int x; std::cin >> x;
		if (x) a.push_back(x);
	}
	
	int n = a.size();
	
	std::sort(a.begin(), a.end());
	
	if (a.empty()) return std::cout << "0\n", void(0);
	if (a[0] * a[n - 1] > 0) return std::cout << a[n - 1] << "\n", void(0);
	
	int zero = 2000000;

	rep (i, 0, n - 2) {
		dbg(a[i]);
		if (a[i] > 0) {
			f |= f << a[i];
		} else {
			f |= f >> (-a[i]);
		}
		f[zero + a[i]] = 1;
	}

	i64 ans = 0;
	rep (i, -2000, 0) {
		if (f[zero + i]) ans = i;  
	}

	ans += a[n - 1];

	std::cout << ans << '\n';
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
