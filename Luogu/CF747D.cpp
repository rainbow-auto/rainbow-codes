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

const int maxn = 2000005;

int n, k;
int a[maxn];

inline int calc(std::vector<int> rs, int k) {
	int res = 0;
	rep (i, 0, (int) rs.size() - 1) {
		if (k < rs[i]) break;
		k -= rs[i];
		res += 2;
	}
	return res;
}

void solve() {
	std::cin >> n >> k;
	rep (i, 1, n) {
		int x; std::cin >> x;
		a[i] = x < 0;
	}

	std::vector<int> rs;

	int tot = 0;
	int lst = 0;

	int org = 0;
	rep (i, 1, n) {
		if (a[i] != a[i - 1]) org++;
		if (not a[i]) continue;

		tot++;
		if (not lst or lst == i - 1) {
			lst = i;
			continue;
		}
		
		// db << "add " << lst + 1 << " " << i - 1 << " " << i - lst - 1 << "\n";
		rs.push_back((int) i - lst - 1);
		lst = i;
	}
	std::sort(rs.begin(), rs.end());
	
	if (not tot) return std::cout << "0\n", void(0);
	if (k < tot) return std::cout << "-1\n", void(0);

	k -= tot;

	int suf = n - lst;
	
	dbg(k);
	dbg(suf);

	int res1 = 0x3f3f3f3f;
	// int org = (rs.size() + 1) << 1;
	if (suf > 0) {
		if (k >= suf) {
			// use suf
			res1 = org - (1 + calc(rs, k - suf));
		}
	}

	int res2 = org - calc(rs, k);

	std::cout << std::min(res1, res2) << "\n";
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
