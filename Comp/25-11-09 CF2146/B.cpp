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

int n, m;
std::vector<int> ocur[maxn];
std::bitset<maxn> msk;

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) {
		int l; std::cin >> l;
		rep (j, 1, l) {
			int x; std::cin >> x;
			ocur[x].push_back(i);
		}
	}	

	bool flg = true;
	rep (i, 1, m) {
		if (ocur[i].size() == 1) {
			msk[ocur[i].front()] = true;
		}
		if (ocur[i].size() == 0) {
			dbg(i);
			flg = false;
			break;
		}
	}

	if (not flg) {
		std::cout << "NO\n";
	} else {
		int cnt = 0;
		rep (i, 1, n) cnt += (not msk[i]);
		if (cnt >= 2) std::cout << "YES\n";
		else std::cout << "NO\n";
	}

	rep (i, 1, n) msk[i] = false;
	rep (i, 1, m) std::vector<int>{}.swap(ocur[i]);
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
