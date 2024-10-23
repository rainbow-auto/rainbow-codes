#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 1000005;

int n;

std::vector<int> ps;
inline void sieve(int R) {
	std::bitset<maxn> np; np.set(1);
	rep (i, 2, R) {
		if (not np[i]) ps.push_back(i);
		for (auto p : ps) {
			if (p * i > R) break;
			np.set(i * p);
			if (i % p == 0) break;	
		}
	}
}

std::pair<int, int> ans;
void dfs(i64 now, int cur, int num, int lst) {
	if (num > n) return;
	ans = std::max(ans, std::make_pair(cur, -num));
	if (lst == 0) return;
	if (now >= ps.size()) return;

	i64 pw = 1;
	rep (i, 0, lst) {
		if (num * pw > n) break;
		dfs(now + 1, cur * (i + 1), num * pw, i);
		pw *= ps[now];
	}
}

void solve() {
	std::cin >> n;

	sieve(233);

	dfs(0, 1, 1, 30);

	std::cout << -ans.second << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

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
