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

constexpr int maxn = 10;

int n, m;

bool a[maxn][maxn];
int f[maxn][1 << maxn];

int calc(int S, int i) {
	int res = 0;
	rep (j, 1, m) if (a[i][j] and not (S & (1 << (j - 1)))) res ++;
	return res;
}

inline bool chk(int pS, int S) {
	bool px = !!(pS & 1), py = !!(S & 1);
	rep (j, 2, m) {
		bool x = !!(pS & (1 << (j - 1)));
		bool y = !!(S & (1 << (j - 1)));
		if (px and x and py and y) return false;
		px = x; py = y;
	}
	return true;
}

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) {
		rep (j, 1, m) {
			char c; std::cin >> c;
			if (c == '#') a[i][j] = true;
			else a[i][j] = false;
		}
	}	

	std::memset(f, 0x3f, sizeof f);
	rep (S, 0, (1 << m) - 1) f[1][S] = calc(S, 1);
	
	rep (i, 2, n) {
		rep (S, 0, (1 << m) - 1) {
			int w = calc(S, i);
			rep (pS, 0, (1 << m) - 1) {
				if (not chk(pS, S)) continue;
				f[i][S] = std::min(f[i][S], f[i - 1][pS] + w);
			}
		}
	}

	int ans = 0x3f3f3f3f;
	rep (S, 0, (1 << m) - 1) ans = std::min(ans, f[n][S]);
	std::cout << ans << "\n";
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
