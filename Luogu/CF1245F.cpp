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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 33;

int a[maxn], b[maxn];

i64 f[maxn][2][2];
i64 dfs(int now, bool alim, bool blim) {
	if (now < 0) return 1;

	if (~f[now][alim][blim]) return f[now][alim][blim];

	i64 res = 0;
	rep (i, 0, alim ? a[now] : 1) {
		rep (j, 0, blim ? b[now] : 1) {
			if (i & j) continue;
			res += dfs(now - 1, alim and (i == a[now]), blim and (j == b[now]));
		}
	}

	f[now][alim][blim] = res;
	return res;
}

i64 calc(int alim, int blim) {
	if (alim < 0) return 0;
	if (blim < 0) return 0;
	
	memset(f, -1, sizeof(f));

	rep (i, 0, 30) a[i] = bool (alim & (1 << i));
	rep (i, 0, 30) b[i] = bool (blim & (1 << i));

	return dfs(30, true, true);
}

void solve() {
	int l, r; std::cin >> l >> r;

	std::cout << calc(r, r) - 2ll * calc(l - 1, r) + calc(l - 1, l - 1) << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _ = 1;
	
	int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
