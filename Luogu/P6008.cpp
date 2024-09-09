#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 1005;
const i64 mod = 1e9 + 7;

int n, m;
bool c[maxn][maxn];

i64 f[maxn * maxn];
int fa[maxn * maxn];
int find (int x) {
	if (fa[x] == x) { return x; }
	return fa[x] = find (fa[x]);
}

inline void merge (int x, int y) {
	x = find (x); y = find (y);
	if (x == y) { return; }
	if (rand () & 1) { std::swap (x, y); }

	fa[y] = x;
	f[x] *= f[y]; f[x] %= mod;
}

inline int id (int i, int j) { return (i - 1) * m + j; }

std::set <int> colors;

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	std::cin >> n >> m;
	rep (i, 1, n) {
		rep (j, 1, m) {
			char ch; std::cin >> ch;
			c[i][j] = ch == '.';
		}
	}

	rep (i, 1, n * m) { fa[i] = i; f[i] = 1; } 

	per (i, n - 1, 2) {
		rep (j, 2, m - 1) {
			if (not c[i][j]) { continue; }
			if (c[i][j - 1]) { merge (id (i, j), id (i, j - 1)); }
			if (c[i + 1][j]) { merge (id (i, j), id (i + 1, j)); }
		}

		colors.clear ();
		rep (j, 1, m) { if (c[i][j]) { colors.insert (find (id (i, j))); } }

		for (auto x : colors) { f[x] ++; f[x] %= mod; }
	}

	i64 ans = 1;
	rep (i, 2, n - 1) {
		rep (j, 2, m - 1) {
			if (not c[i][j]) { continue; }
			if (find (id (i, j)) == id (i, j)) { ans *= f[id (i, j)] % mod; ans %= mod; }
		}
	}

	std::cout << ans << "\n";

	return 0;
}
