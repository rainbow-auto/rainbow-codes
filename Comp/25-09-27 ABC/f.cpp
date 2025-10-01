#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using u64 = unsigned long long;
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

constexpr int maxn = 23;

int n;
std::string s;

constexpr u64 base = 233;
constexpr i64 mod = 998244353;

u64 id[1 << maxn | 5];
i64 f[1 << maxn | 5];

void solve() {
	std::cin >> n;
	std::string s; std::cin >> s;
	
	rep (S, 0, (1 << n) - 1) {
		u64 h = 0;
		rep (i, 0, n - 1) {
			if (S & (1 << i)) {
				h = (h * base % mod + s[i] - 'a') % mod;
			}
		}
		id[S] = h;
	}

	f[0] = 1;
	rep (S, 0, (1 << n) - 1) {
		std::unordered_set<u64> vised;
		rep (i, 0, n - 1) {
			if (S & (1 << i)) {
				if (vised.count(id[S ^ (1 << i)])) continue;
				vised.insert(id[S ^ (1 << i)]);
				(f[S] += f[S ^ (1 << i)]) %= mod;
			}
		}
	}

	std::cout << f[(1 << n) - 1] << "\n";
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
