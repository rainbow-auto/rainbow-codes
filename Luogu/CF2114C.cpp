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

constexpr int maxn = 100005;
constexpr int mod = 998244353;

int n;
int p[maxn], q[maxn];
int w[maxn];

i64 pw[maxn];
inline void init() {
	pw[0] = 1;
	rep (i, 1, maxn - 1) pw[i] = pw[i - 1] * 2ll % mod;
}

void solve() {
	std::cin >> n;
	rep (i, 0, n - 1) std::cin >> p[i];
	rep (i, 0, n - 1) std::cin >> q[i];

	auto mxp = std::pair<int, int>{ -0x3f3f3f3f, 0 };
	auto mxq = std::pair<int, int>{ -0x3f3f3f3f, 0 };
	rep (i, 0, n - 1) {
		mxp = std::max(mxp, std::pair<int, int>{ p[i], i });
		mxq = std::max(mxq, std::pair<int, int>{ q[i], i });
		
		auto r = std::max(std::make_pair(mxp.first, q[i - mxp.second]), 
				 		  std::make_pair(mxq.first, p[i - mxq.second]));
		
		std::cout << (pw[r.first] + pw[r.second]) % mod << " ";
	}
	std::cout << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	

	init();

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
