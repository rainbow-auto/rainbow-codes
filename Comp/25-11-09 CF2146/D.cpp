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

constexpr int maxn = 1000005;

int L, R;
int ans[maxn];

void solve(int l, int r, int b) {
	// dbg(l); dbg(r); dbg(b);

	if (l > r) return;
	if (l == r) return ans[l - L] = l, void(0);
	std::array<std::pair<int, int>, 2> rg = { std::pair<int, int>{-1, -1}, std::pair<int, int>{-1, -1}};

	rep (i, l, r) {
		auto &cur = rg[(i >> b) & 1];
		if (not ~cur.first) cur.first = i;
		cur.second = i;
	}

	if (not ~rg[0].first or not ~rg[1].first) return solve(l, r, b - 1), void(0);

	// db << rg[0].first << " " << rg[0].second << " | " << rg[1].first << " " << rg[1].second << "\n";

	int posl = rg[0].second, posr = rg[1].first;
	while (posl >= rg[0].first and posr <= rg[1].second) {
		ans[posl - L] = posr;
		ans[posr - L] = posl;
		posl --;
		posr ++;
	}

	if (posr <= rg[1].second) solve(posr, rg[1].second, b - 1);
	if (posl >= rg[0].first) solve(rg[0].first, posl, b - 1);
}

void solve() {
	std::cin >> L >> R;

	// dbg(L); dbg(R);
	solve(L, R, 30);

	i64 ansv = 0; rep (i, 0, R - L) ansv += ((i + L) | ans[i]);
	std::cout << ansv << "\n";
	rep (i, 0, R - L) std::cout << ans[i] << " "; std::cout << "\n";
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
