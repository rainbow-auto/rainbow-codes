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
// #define MultiTask lovely_fairytale

const int maxn = 2005;
const int maxm = 25;
const int mod = 998244353;

int n, m;
bool a[maxn][maxm];

namespace Task1 {
	int p[maxm];
	int ans[maxn];
	inline void solve() {
		rep (i, 1, n) p[i] = i;
		do {
			int S = (1 << m) - 1;
			rep (i, 1, n) {
				int cnt = 0;
				rep (j, 1, m) if ((S & (1 << (j - 1))) and not a[p[i]][j]) cnt++;
				if (cnt == __builtin_popcount(S)) continue;
				if (cnt == 0) continue;
				rep (j, 1, m) if ((S & (1 << (j - 1))) and not a[p[i]][j]) S ^= (1 << (j - 1));
			}

			rep (j, 1, m) if (S & (1 << (j - 1))) (ans[j] += 1) %= mod;
		} while (std::next_permutation(p + 1, p + n + 1));
		
		rep (j, 1, m) std::cout << ans[j] << "\n";
	}
}

void solve() {
	std::freopen("yilihun.in", "r", stdin);
	std::freopen("yilihun.out", "w", stdout);

	std::cin >> n >> m;
	rep (i, 1, n) {
		rep (j, 1, m) {
			char ch; std::cin >> ch;
			a[i][j] = ch - '0';
		}
	}
	Task1::solve();
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
