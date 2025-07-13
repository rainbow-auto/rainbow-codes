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

constexpr int maxn = 35;

i64 x, y, k;
i64 a[maxn];

i64 f[maxn][2];

void solve() {
	std::cin >> x >> y >> k;
	rep (i, 0, k) std::cin >> a[i];

	i64 d = std::abs(x - y);
	if (not d) return std::cout << "0\n", void(0);

	rep (i, 0, k - 1) {
		a[i + 1] = std::min(a[i + 1], (a[i] << 1));
	}
	rep (i, k + 1, 30) a[i] = (a[i - 1] << 1);

	std::memset(f, 0x3f, sizeof f);
	if (d & 1) f[0][0] = f[0][1] = a[0];
	else f[0][0] = 0;

	rep (i, 1, 30) {
		if ((d >> i) & 1) {
			f[i][0] = f[i - 1][0] + a[i];
			f[i][1] = std::min(f[i - 1][0] + a[i], f[i - 1][1]);
		} else {
			f[i][0] = std::min(f[i - 1][1] + a[i], f[i - 1][0]);
			f[i][1] = f[i - 1][1] + a[i];
		}
	}

	std::cout << f[30][0] << "\n";
}

/*
1 1
3 1
6 1
6 7
6 19
6 43
6 91
6 187
6 379
6 763
6 1531
6 3067
6 6139
6 12283
6 24571
6 49147
6 98299
6 196603
6 393211
6 786427
6 1572859
6 3145723
6 6291451
6 12582907
6 25165819
6 50331643
6 100663291
6 201326587
6 402653179
6 805306363
6 1610612731
*/

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
