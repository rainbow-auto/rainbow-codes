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

constexpr int maxn = 100005;

int n;
i64 m, a[maxn];
i64 sum;

i64 f[3], g[3];

std::bitset<3> to[maxn];

void solve() {
	std::cin >> n >> m;
	rep (i, 1, n) std::cin >> a[i];

	sum = 0;
	rep (i, 1, n) {
		to[i].reset();
		if (a[i] == m / a[i]) {
			sum += a[i];
			to[i].set();
		} else {
			int c = 0;
			if (m / (m / a[i]) != a[i]) {
				a[i] = m / a[i];
				c++;
			}

			if (m / a[i] > a[i]) c++;
			to[i].set(c);
			if (c == 0) to[i].set(2); 

			sum += std::max(m / a[i], a[i]);
		}
	}

	std::memset(f, 0x3f, sizeof f);
	std::memset(g, 0x3f, sizeof g);
	
	g[0] = 0;

	rep (i, 1, n) {
		rep (cur, 0, 2) {
			if (not to[i][cur]) continue;
			rep (lst, 0, 2) {
				// db << "lst: " << lst << " " << g[lst] + std::max(0ll, cur - lst) << " -> " << "f[" << cur << "]\n";
				f[cur] = std::min(f[cur], g[lst] + std::max(0ll, cur - lst));
			}
		}

		// rep (k, 0, 3) db << f[k] << " \n"[k == 3];

		std::memcpy(g, f, sizeof f);
		std::memset(f, 0x3f, sizeof f);
	}

	i64 ans = std::min({g[0], g[1], g[2]});

	std::cout << sum << " " << ans << "\n";
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
