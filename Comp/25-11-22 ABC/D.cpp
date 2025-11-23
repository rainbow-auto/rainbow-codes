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

int n, M;
i64 a[maxn], len[maxn];

i64 pw10[maxn];

std::map<int, int> cnt[13];

inline int getLen(int x) {
	int tot = 0;
	while (x) {
		x /= 10;
		tot++;
	}
	return tot;
}

void solve() {
	std::cin >> n >> M;
	rep (i, 1, n) std::cin >> a[i];
	rep (i, 1, n) len[i] = getLen(a[i]);

	rep (i, 1, n) a[i] %= M;
	rep (i, 1, n) cnt[len[i]][a[i]]++;

	pw10[0] = 1; rep (i, 1, 12) pw10[i] = 10ll * pw10[i - 1] % M;

	i64 ans = 0;
	rep (lenj, 0, 12) {
		// pw10[lenj] * a[i] + a[j] == 0;
		rep (i, 1, n) ans += cnt[lenj][(M - 1ll * a[i] * pw10[lenj] % M) % M];
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
