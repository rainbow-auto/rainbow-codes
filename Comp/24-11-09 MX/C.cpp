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
#define lookTime std::cerr << (double) clock() / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
#define MultiTask lovely_fairytale

const int maxn = 100005;

int n;
int a[maxn];

using u64 = unsigned long long;

const u64 base = 13331;
u64 pw[maxn];

inline void init(int R) {
	pw[0] = 1;
	rep (i, 1, R) pw[i] = pw[i - 1] * base;
}

namespace Task0 {
	const int maxn = 35;
	
	int ans;
	u64 ans_a;
	int ch[maxn];

	inline u64 get() {
		u64 res = 0;
		rep (i, 1, n - 1) res += 1ull * ch[i] * pw[n - 1 - i];
		return res;
	}

	int old_a[maxn];

	void dfs(int now) {
		if (now >= n) {
			rep (i, 1, n - 1) {
				a[ch[i]] = __builtin_popcount(a[ch[i]] + a[ch[i] + 1]);
				rep (j, ch[i] + 1, n) a[j] = a[j + 1];
			}

			if (a[1] < ans) ans = a[1], ans_a = get();
			
			std::memcpy(a, old_a, sizeof old_a);

			return;	
		}

		rep (i, 1, n - now) {
			ch[now] = i;
			dfs(now + 1);
		}
	}

	inline void solve() {
		std::memcpy(old_a, a, sizeof old_a);

		ans = 0x3f3f3f3f;
		dfs(1);
		std::cout << ans << " " << ans_a << "\n";
	}
}

// namespace Task1 {
// 	const int maxn = 305;

// 	int f[maxn][maxn];
// 	int g[maxn][maxn];

// 	inline bool chkmax(int &x, int y) { return x < y ? 0 : x = y, 1; }

// 	inline void solve() {
// 		std::memset(f, 0, sizeof f);
// 		rep (i, 1, n) f[i][i] = a[i];

// 		rep (len, 2, n) {
// 			rep (l, 1, n - len + 1) {
// 				int r = l + len - 1;
// 				rep (i, l, r - 1) {
// 					if (chkmax(f[l][r], __builtin_popcnt(f[l][i] + f[i + 1][r]))) g[l][r] = i;
// 				}
// 			}	
// 		}

// 		std::vector<int>().swap(ans);
// 		std::cout << f[1][n] << " ";
// 		get(1, n);

// 		std::cout << "\n";
// 	}
// }

void solve() {
	std::string s; std::cin >> s;
	n = s.length();

	rep (i, 1, n) a[i] = s[i - 1] - '0';

	Task0::solve();
}

bool MemED;
int main() {
	fastread
	// lookMem	

	init(10000);

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
