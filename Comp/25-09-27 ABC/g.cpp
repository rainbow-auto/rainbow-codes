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
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

constexpr int maxn = 200005;

int n, m;

constexpr int B = 30;

int a[maxn];

struct Node {
	int ch[2];
} tr[maxn << 6];

int rt, tot;

inline void ins(int x) {
	// db << "ins " << x << "\n";
	int now = rt;
	per (i, B, 0) {
		bool c = x & (1 << i);
		// db << c << " : ";
		if (not tr[now].ch[c]) tr[now].ch[c] = ++tot;
		now = tr[now].ch[c];
		// dbg(now);
	}
}

inline void upd(std::array<int, 2> ffa, std::array<int, 2> &fnow, int c, int x) {
	fnow[0] += ffa[0];
	if (x == c) fnow[1] += ffa[1];
	if (x < c) fnow[0] += ffa[1];
}

i64 ans;
void dfs(int now, std::array<int, 2> ffa, int dep) {
	// dbg(now);
	// db << ffa[0] << " " << ffa[1] << "\n";
	if (dep < 0) return;
	// if (not (tr[now].ch[0] || tr[now].ch[1])) return;
	std::array<int, 2> fnow = {};
	bool c = m & (1 << dep);
	if (tr[now].ch[0] and tr[now].ch[1]) {
		upd(ffa, fnow, c, 0);
		dfs(tr[now].ch[0], fnow, dep - 1);
		fnow = {};
		upd(ffa, fnow, c, 1);
		dfs(tr[now].ch[1], fnow, dep - 1);
	} else if (tr[now].ch[0]) {
		// db << "L\n";
		upd(ffa, fnow, c, 1);
		// db << "fnow: " << fnow[0] << " " << fnow[1] << "\n";
		// dbg((((1 << (dep + 1)) - 1)));
		ans += (1ll << dep) * (fnow[0] * (1 << dep)  + fnow[1] * ((m & ((1 << dep) - 1)) + 1));
		// db << "add: " << (1ll << dep) * (fnow[0] * (1 << dep)  + fnow[1] * (m & ((1 << (dep + 1)) - 1))) << "\n";
		upd(ffa, fnow, c, 0);
		dfs(tr[now].ch[0], fnow, dep - 1);
	} else {
		// db << "R\n";
		upd(ffa, fnow, c, 0);
		// db << "fnow: " << fnow[0] << " " << fnow[1] << "\n";
		ans += (1ll << dep) * (fnow[0] * (1 << dep)  + fnow[1] * ((m & ((1 << (dep)) - 1)) + 1));
		// db << "add: " << (1ll << dep) * (fnow[0] * (1 << dep)  + fnow[1] * (m & ((1 << (dep + 1)) - 1))) << "\n";
		upd(ffa, fnow, c, 1);
		dfs(tr[now].ch[1], fnow, dep - 1);
	}
}

namespace Checker {
	inline void chk() {
		i64 res = 0;
		rep (i, 0, m) {
			i64 mn = 0x3f3f3f3f;
			rep (j, 1, n) mn = std::min(mn, (a[j] xor i));
			res += mn;
		}
		dbg(ans);
		dbg(res);
		assert(res == ::ans);
	}
}

void solve() {
	std::cin >> n >> m;
	m--;
	rep (i, 1, n) {
		std::cin >> a[i];
		ins(a[i]);
	}

	// dbendl;
	dfs(rt, {0, 1}, B);

	std::cout << ans << "\n";

	// Checker::chk();
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
