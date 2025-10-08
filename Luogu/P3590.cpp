#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
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

constexpr int maxn = 2000005;

int n;
int a[maxn];

int pre[3][maxn];

void solve() {
	std::cin >> n;
	rep (i, 1, n) {
		char c; std::cin >> c;
		if (c == 'B') a[i] = 0;
		if (c == 'C') a[i] = 1;
		if (c == 'S') a[i] = 2;
	}

	rep (x, 0, 2) rep (i, 1, n) pre[x][i] = pre[x][i - 1] + (a[i] == x);
	
	auto chk = [&](int l, int r) -> bool {
		std::array<int, 3> cnt = { pre[0][r] - pre[0][l - 1], pre[1][r] - pre[1][l - 1], pre[2][r] - pre[2][l - 1] };

		if ((cnt[0] == 0 and cnt[1] == 0) or (cnt[1] == 0 and cnt[2] == 0) or (cnt[1] == 0 and cnt[2] == 0)) {
			return true;
		} else if (cnt[1] != cnt[2] and cnt[2] != cnt[0] and cnt[0] != cnt[1]) {
			return true;
		}

		return false;
	};

	int ans = 0;
	rep (l, 1, 3) rep (r, l, n) {
		if (chk(l, r)) ans = std::max(ans, r - l + 1);
	}

	rep (r, n - 3, n) rep (l, 1, r) {
		if (chk(l, r)) ans = std::max(ans, r - l + 1);
	}

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
